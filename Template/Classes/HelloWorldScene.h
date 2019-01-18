#pragma once

#include <irrlicht.h>
#include "exampleHelper.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class HelloWorldScene
{
public:
	HelloWorldScene();
	~HelloWorldScene();

	void Initialize(IrrlichtDevice* device);
};

