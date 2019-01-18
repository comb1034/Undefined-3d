#ifndef __APP_DELEGATGE_H__
#define __APP_DELEGATGE_H__

#include <irrlicht.h>


#include "HelloWorldScene.h"

#ifdef _IRR_ANDROID_PLATFORM_
#include "android_native_app_glue.h"
#include "android_tools.h"
#endif // _IRR_ANDROID_PLATFORM


using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class AppDelegate
{
public:
	AppDelegate();
	~AppDelegate();

	static const dimension2d<u32> SCREEN_SIZE;

#ifdef _IRR_ANDROID_PLATFORM_
	int Run(android_app* app);
#else
	int Run();
#endif

private:

};

#endif