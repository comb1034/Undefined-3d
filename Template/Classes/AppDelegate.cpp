#include "AppDelegate.h"

#ifdef _WIN32
const dimension2d<u32> AppDelegate::SCREEN_SIZE = dimension2d<u32>(640, 480);
#else
const dimension2d<u32> AppDelegate::SCREEN_SIZE = dimension2d<u32>(720, 1280);
#endif // _WIN32

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{

}

#ifdef _IRR_ANDROID_PLATFORM_
int AppDelegate::Run(android_app *app)
#else
int AppDelegate::Run()
#endif // _IRR_ANDROID_PLATFORM_
{
#ifdef _IRR_ANDROID_PLATFORM_
	app_dummy();

	SIrrlichtCreationParameters param;
	//	param.DriverType = EDT_OGLES1;				// android:glEsVersion in AndroidManifest.xml should be "0x00010000" (requesting 0x00020000 will also guarantee that ES1 works)
	param.DriverType = EDT_OGLES2;				// android:glEsVersion in AndroidManifest.xml should be "0x00020000"
	param.WindowSize = dimension2d<u32>(0, 0);	// using 0,0 it will automatically set it to the maximal size
	param.PrivateData = app;
	param.Bits = 24;
	param.ZBufferBits = 16;
	param.AntiAlias = 0;
#ifndef _DEBUG
	param.LoggingLevel = ELL_NONE;
#endif

	IrrlichtDevice *device = createDeviceEx(param);
#else
	IrrlichtDevice *device =
		createDevice(video::EDT_OPENGL, SCREEN_SIZE, 16,
			false, false, false, 0);

#endif // _IRR_ANDROID_PLATFORM_
	
	if (!device)
		return 1;

#ifdef _IRR_ANDROID_PLATFORM_
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	ILogger* logger = device->getLogger();
	IFileSystem * fs = device->getFileSystem();

	/* Access to the Android native window. You often need this when accessing NDK functions like we are doing here.
	   Note that windowWidth/windowHeight have already subtracted things like the taskbar which your device might have,
	   so you get the real size of your render-window.
	*/
	ANativeWindow* nativeWindow = static_cast<ANativeWindow*>(driver->getExposedVideoData().OGLESAndroid.Window);
	int32_t windowWidth = ANativeWindow_getWidth(app->window);
	int32_t windowHeight = ANativeWindow_getHeight(app->window);

	/* Get display metrics. We are accessing the Java functions of the JVM directly in this case as there is no NDK function for that yet.
	   Checkout android_tools.cpp if you want to know how that is done. */
	irr::android::SDisplayMetrics displayMetrics;
	memset(&displayMetrics, 0, sizeof displayMetrics);
	irr::android::getDisplayMetrics(app, displayMetrics);
	
	stringc mediaPath = "media/";
	// The Android assets file-system does not know which sub-directories it has (blame google).
	// So we have to add all sub-directories in assets manually. Otherwise we could still open the files,
	// but existFile checks will fail (which are for example needed by getFont).
	for (u32 i = 0; i < fs->getFileArchiveCount(); ++i)
	{
		IFileArchive* archive = fs->getFileArchive(i);
		if (archive->getType() == EFAT_ANDROID_ASSET)
		{
			archive->addDirectoryToFileList(mediaPath);
			break;
		}
	}

#else
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

#endif // _IRR_ANDROID_PLATFORM_

	
	//device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	HelloWorldScene main;
	main.Initialize(device);

	while (device->run() == true)
	{
		/*
		Anything can be drawn between a beginScene() and an endScene()
		call. The beginScene() call clears the screen with a color and
		the depth buffer, if desired. Then we let the Scene Manager and
		the GUI Environment draw their content. With the endScene()
		call everything is presented on the screen.
		*/
#ifdef _IRR_ANDROID_PLATFORM_
		if (device->isWindowActive() == true)
#endif
		{
			driver->beginScene(ECBF_COLOR | ECBF_DEPTH, SColor(255, 100, 101, 140));

			smgr->drawAll();
			guienv->drawAll();

			driver->endScene();
		}
#ifdef _IRR_ANDROID_PLATFORM_
		device->yield(); // probably nicer to the battery
#endif // _IRR_ANDROID_PLATFORM
	}
#ifdef _IRR_ANDROID_PLATFORM_
	/* Cleanup */
	device->setEventReceiver(0);
	device->closeDevice();
#endif // _IRR_ANDROID_PLATFORM
	device->drop();

	return 0;
}
