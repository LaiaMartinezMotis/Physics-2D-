#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePhysics.h"
#include "math.h"

#include "Box2D/Box2D/Box2D.h"

#ifdef _DEBUG
#pragma comment( lib, "Box2D/libx86/Debug/Box2D.lib" )
#else
#pragma comment( lib, "Box2D/libx86/Release/Box2D.lib" )
#endif

ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	world = NULL;
	debug = true;
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	world = new b2World(b2Vec2(GRAVITY_X, -GRAVITY_Y));

	// big static circle as "ground" in the middle of the screen
	int x = SCREEN_WIDTH / 2;
	int y = SCREEN_HEIGHT / 1.5f;
	int diameter = SCREEN_WIDTH / 2;

	b2BodyDef body;
	body.type = b2_staticBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);

	b2CircleShape shape;
	shape.m_radius = PIXEL_TO_METERS(diameter) * 0.5f;

	b2FixtureDef fixture;
	fixture.shape = &shape;
	b->CreateFixture(&fixture);

	return true;
}

// 
update_status ModulePhysics::PreUpdate()
{
	world->Step(1.0f / 60.0f, 6, 2);

	return UPDATE_CONTINUE;
}

// 
update_status ModulePhysics::PostUpdate()
{
	// On space bar press, create a circle on mouse position
	
		// TODO 1: When pressing 2, create a box on the mouse position
		// To have the box behave normally, set fixture's density to 1.0f
	

	
		// TODO 2: Create a chain shape using those vertices
		// remember to convert them from pixels to meters!
		
		
		
	

	/*if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN) {

		int Pikachu_transparent[376] = {
			110, 219,
			155, 257,
			188, 285,
			220, 307,
			257, 330,
			272, 337,
			260, 357,
			254, 375,
			250, 394,
			247, 415,
			244, 428,
			241, 452,
			238, 471,
			234, 485,
			227, 500,
			221, 514,
			215, 527,
			212, 542,
			217, 558,
			218, 565,
			235, 595,
			248, 614,
			257, 624,
			267, 638,
			277, 645,
			282, 655,
			277, 668,
			265, 682,
			257, 701,
			250, 717,
			247, 734,
			242, 744,
			241, 765,
			241, 781,
			241, 795,
			245, 814,
			248, 828,
			257, 842,
			261, 855,
			267, 870,
			275, 882,
			282, 895,
			284, 902,
			282, 912,
			277, 921,
			267, 935,
			261, 952,
			257, 967,
			251, 987,
			252, 1011,
			258, 1030,
			267, 1040,
			274, 1054,
			287, 1064,
			295, 1072,
			302, 1080,
			290, 1092,
			281, 1102,
			277, 1114,
			272, 1124,
			272, 1132,
			274, 1141,
			282, 1147,
			291, 1148,
			301, 1145,
			307, 1138,
			318, 1131,
			330, 1127,
			341, 1118,
			352, 1114,
			362, 1105,
			375, 1098,
			385, 1098,
			402, 1098,
			412, 1098,
			421, 1097,
			432, 1097,
			447, 1094,
			458, 1094,
			470, 1092,
			480, 1091,
			500, 1090,
			515, 1091,
			534, 1092,
			548, 1094,
			565, 1101,
			581, 1101,
			592, 1105,
			610, 1107,
			618, 1111,
			617, 1122,
			610, 1134,
			610, 1147,
			610, 1155,
			618, 1165,
			624, 1168,
			642, 1168,
			648, 1158,
			665, 1152,
			678, 1137,
			691, 1128,
			704, 1115,
			708, 1105,
			718, 1101,
			735, 1091,
			755, 1074,
			767, 1052,
			780, 1034,
			788, 1012,
			797, 994,
			804, 975,
			808, 961,
			812, 948,
			814, 931,
			891, 900,
			868, 842,
			947, 808,
			918, 717,
			1010, 687,
			972, 571,
			1217, 490,
			1120, 274,
			810, 467,
			932, 655,
			842, 688,
			880, 790,
			821, 817,
			852, 881,
			807, 898,
			802, 871,
			798, 850,
			791, 818,
			784, 782,
			774, 734,
			758, 660,
			744, 580,
			732, 498,
			725, 441,
			721, 412,
			717, 397,
			710, 381,
			704, 364,
			697, 352,
			727, 340,
			768, 332,
			811, 314,
			840, 304,
			867, 290,
			895, 271,
			927, 251,
			964, 215,
			1007, 171,
			898, 168,
			835, 185,
			787, 198,
			764, 207,
			738, 217,
			715, 231,
			695, 244,
			675, 251,
			658, 262,
			637, 275,
			628, 282,
			602, 271,
			577, 265,
			551, 258,
			525, 252,
			492, 252,
			468, 250,
			442, 250,
			415, 252,
			390, 257,
			361, 260,
			342, 271,
			322, 271,
			301, 246,
			245, 196,
			195, 157,
			155, 127,
			100, 97,
			70, 85,
			44, 77,
			25, 73,
			29, 89,
			47, 128,
			63, 154,
			82, 186,
			110, 218
		};
		b2Vec2 vec[188];
		int j = 0;


		for (int i = 0; i < 188; i++) {
			vec[i].x = PIXEL_TO_METERS(Pikachu_transparent[j]);
			j++;
			vec[i].y = PIXEL_TO_METERS(Pikachu_transparent[j]);
			j++;
		};

		b2BodyDef pikachu;
		pikachu.type = b2_dynamicBody;
		pikachu.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

		b2Body* pika = world->CreateBody(&pikachu);

		b2ChainShape shape;
		shape.CreateLoop(vec, 188);
		b2FixtureDef fixture;
		fixture.shape = &shape;
		fixture.density = 1.0f;
		pika->CreateFixture(&fixture);
	}*/

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(!debug)
		return UPDATE_CONTINUE;

	// Bonus code: this will iterate all objects in the world and draw the circles
	// You need to provide your own macro to translate meters to pixels
	for(b2Body* b = world->GetBodyList(); b; b = b->GetNext())
	{
		for(b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext())
		{
			switch(f->GetType())
			{
				// Draw circles ------------------------------------------------
				case b2Shape::e_circle:
				{
					b2CircleShape* shape = (b2CircleShape*)f->GetShape();
					b2Vec2 pos = f->GetBody()->GetPosition();
					App->renderer->DrawCircle(METERS_TO_PIXELS(pos.x), METERS_TO_PIXELS(pos.y), METERS_TO_PIXELS(shape->m_radius), 255, 255, 255);
				}
				break;

				// Draw polygons ------------------------------------------------
				case b2Shape::e_polygon:
				{
					b2PolygonShape* polygonShape = (b2PolygonShape*)f->GetShape();
					int32 count = polygonShape->GetVertexCount();
					b2Vec2 prev, v;

					for(int32 i = 0; i < count; ++i)
					{
						v = b->GetWorldPoint(polygonShape->GetVertex(i));
						if(i > 0)
							App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 255, 100, 100);

						prev = v;
					}

					v = b->GetWorldPoint(polygonShape->GetVertex(0));
					App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 255, 100, 100);
				}
				break;

				// Draw chains contour -------------------------------------------
				case b2Shape::e_chain:
				{
					b2ChainShape* shape = (b2ChainShape*)f->GetShape();
					b2Vec2 prev, v;

					for(int32 i = 0; i < shape->m_count; ++i)
					{
						v = b->GetWorldPoint(shape->m_vertices[i]);
						if(i > 0)
							App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 100, 255, 100);
						prev = v;
					}

					v = b->GetWorldPoint(shape->m_vertices[0]);
					App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 100, 255, 100);
				}
				break;

				// Draw a single segment(edge) ----------------------------------
				case b2Shape::e_edge:
				{
					b2EdgeShape* shape = (b2EdgeShape*)f->GetShape();
					b2Vec2 v1, v2;

					v1 = b->GetWorldPoint(shape->m_vertex0);
					v1 = b->GetWorldPoint(shape->m_vertex1);
					App->renderer->DrawLine(METERS_TO_PIXELS(v1.x), METERS_TO_PIXELS(v1.y), METERS_TO_PIXELS(v2.x), METERS_TO_PIXELS(v2.y), 100, 100, 255);
				}
				break;
			}
		}
	}

	return UPDATE_CONTINUE;
}
bool ModulePhysics::CreateCircles() {
	
	b2BodyDef body;
	body.type = b2_dynamicBody;
	float radius = PIXEL_TO_METERS(25);
	body.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

	b2Body* b = world->CreateBody(&body);

	b2CircleShape shape;
	shape.m_radius = radius;
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	b->CreateFixture(&fixture);
	return true;
 }

bool ModulePhysics::CreateSquares() {
	b2BodyDef box;
	box.type = b2_dynamicBody;
	float half_height = PIXEL_TO_METERS(25);
	float half_width = PIXEL_TO_METERS(25);
	box.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

	b2Body* caja = world->CreateBody(&box);

	b2PolygonShape shape;
	shape.SetAsBox(half_height, half_width);
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	caja->CreateFixture(&fixture);
	return true;
}

bool ModulePhysics::CreateChains() {
	//Leter H

	int points[24] = {
		-38, 80,
		-44, -54,
		-16, -60,
		-16, -17,
		19, -19,
		19, -79,
		61, -77,
		57, 73,
		17, 78,
		20, 16,
		-25, 13,
		-9, 72
	};

	b2Vec2 vec[12];
	int j = 0;


	for (int i = 0; i < 12; i++) {
		vec[i].x = PIXEL_TO_METERS(points[j]);
		j++;
		vec[i].y = PIXEL_TO_METERS(points[j]);
		j++;
	};

	b2BodyDef chain;
	chain.type = b2_dynamicBody;
	chain.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

	b2Body* ch = world->CreateBody(&chain);

	b2ChainShape shape;
	shape.CreateLoop(vec, 12);
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	ch->CreateFixture(&fixture);
	return true;

}

// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");

	// Delete the whole physics world!
	delete world;

	return true;
}
