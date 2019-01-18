#include "HelloWorldScene.h"



HelloWorldScene::HelloWorldScene()
{
}


HelloWorldScene::~HelloWorldScene()
{
}

void HelloWorldScene::Initialize(IrrlichtDevice * device)
{
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	/*
	We add a hello world label to the window, using the GUI environment.
	The text is placed at the position (10,10) as top left corner and
	(260,22) as lower right corner.
	*/
	guienv->addStaticText(L"Hello World! This is Irrlicht with the burnings software renderer!",
		rect<s32>(10, 10, 260, 22), true);

	
	const io::path mediaPath = getExampleMediaPath();

	/*
	To show something interesting, we load a Quake 2 model and display it.
	We get the Mesh from the Scene Manager with getMesh() and add a SceneNode
	to display the mesh with addAnimatedMeshSceneNode(). Check the return value
	of getMesh() to become aware of loading problems and other errors.

	Instead of writing the filename sydney.md2, it would also be possible
	to load a Maya object file (.obj), a complete Quake3 map (.bsp) or any
	other supported file format. By the way, that cool Quake 2 model
	called sydney was modeled by Brian Collins.
	*/
	IAnimatedMesh* mesh = smgr->getMesh(mediaPath + "sydney.md2");
	if (!mesh)
	{
		device->drop();
		return;
	}
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, driver->getTexture(mediaPath + "sydney.bmp"));
	}
	
	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

	return;
}
