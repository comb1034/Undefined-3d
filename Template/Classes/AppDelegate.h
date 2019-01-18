#ifndef __APP_DELEGATGE_H__
#define __APP_DELEGATGE_H__

#include <irrlicht.h>

#include "exampleHelper.h"

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

	int Run();

private:

};

#endif