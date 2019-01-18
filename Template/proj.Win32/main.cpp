#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include "AppDelegate.h"

int main()
{
	AppDelegate app;
	return app.Run();
}
