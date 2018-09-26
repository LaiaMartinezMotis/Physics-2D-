#include "Globals.h"
#include "Application.h"
#include "ModulePhysics.h"
#include "math.h"

// TODO 1: Include Box 2 header and library
#include "Box2D/Box2D/Box2D.h"

#ifdef _DEBUG

#pragma comment (lib, "Box2D/libx86/Debug/Box2D.lib")

#else 
#pragma comment (lib, "Box2D/libx86/Release/Box2D.lib")

#endif

#define METERS_TO_PIXELS(meters){(int) (meters / 2)}
#define PIXELS_TO_METERS(pixels){(int) (pixels*2)}

ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug = true;
	b2Vec2 gravity(0.0f, -10.0f);//We define the gravity vector b2Vec2
	myworld = new b2World(gravity);
	/* we are creating the world on the stack, so the world must
	remain in scope.*/


}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	// TODO 2: Create a private variable for the world
	// - You need to send it a default gravity
	// - You need init the world in the constructor
	// - Remember to destroy the world after using it
	
	
	// TODO 4: Create a a big static circle as "ground"
	b2BodyDef ground;
	ground.type = b2_staticBody;
	ground.position.Set(PIXELS_TO_METERS(SCREEN_WIDTH/2), PIXELS_TO_METERS(SCREEN_HEIGHT/2));
	b2Body* body = myworld->CreateBody(&ground); 


	b2CircleShape groundCircle;
	groundCircle.m_radius = PIXELS_TO_METERS(100);
	/*body->CreateFixture(&ground, 10.0f);*/
	body->CreateFixture(&groundCircle, 0.0f);


	return true;
}

// 
update_status ModulePhysics::PreUpdate()
{
	// TODO 3: Update the simulation ("step" the world)
	float32 timeStep= 1.0f / 60.0f; //the length of time passed to simulate (seconds)
	int32 velocityIterations = 6; //how strongly to correct velocity
	int32 positionIterations = 2; //how strongly to correct position
	
	myworld->Step(timeStep, velocityIterations, positionIterations);
	
	return UPDATE_CONTINUE;
}

// 
update_status ModulePhysics::PostUpdate()
{
	// TODO 5: On space bar press, create a circle on mouse position
	// - You need to transform the position / radius

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(!debug)
		return UPDATE_CONTINUE;

	// Bonus code: this will iterate all objects in the world and draw the circles
	// You need to provide your own macro to translate meters to pixels
	
	for(b2Body* b = myworld->GetBodyList(); b; b = b->GetNext())
	{
		for(b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext())
		{
			switch(f->GetType())
			{
				case b2Shape::e_circle:
				{
					b2CircleShape* shape = (b2CircleShape*)f->GetShape();
					b2Vec2 pos = f->GetBody()->GetPosition();
					App->renderer->DrawCircle(METERS_TO_PIXELS(pos.x), METERS_TO_PIXELS(pos.y), METERS_TO_PIXELS(shape->m_radius), 255, 255, 255);
				}
				break;

				// You will have to add more cases to draw boxes, edges, and polygons ...
			}
		}
	}

	return UPDATE_CONTINUE;
}


// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");
	
	// Delete the whole physics world!
	delete myworld;
	myworld=nullptr;
	return true;
}

