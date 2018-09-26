#pragma once
#include "Module.h"
#include "Globals.h"

#define PIXELS_TO_METERS(pixels) { (int)pixels}
#define METERS_TO_PIXELS(meters) { (int)meters}

class b2World;

class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

private:

	b2World *myworld;
	bool debug;
};