#include <irrlicht.h>
#include <ozcollide\ozcollide.h>
#include <ozcollide\box.h>
#include <ozcollide\sphere.h>
#include "MyEventReceiver.h"
using namespace std;

using namespace irr;
using namespace core;
using namespace video;

using namespace ozcollide;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


/*
At first, we let the user select the driver type, then start up the engine, set
a caption, and get a pointer to the video driver.
*/

void drawCollision(Box* box, IVideoDriver* driver)
{
	driver->draw2DLine(vector2d<s32>(box->getPoint(0).x, box->getPoint(0).y), vector2d<s32>(box->getPoint(1).x, box->getPoint(1).y), SColor(255, 255, 0, 0));
	driver->draw2DLine(vector2d<s32>(box->getPoint(1).x, box->getPoint(1).y), vector2d<s32>(box->getPoint(3).x, box->getPoint(3).y), SColor(255, 255, 0, 0));
	driver->draw2DLine(vector2d<s32>(box->getPoint(2).x, box->getPoint(2).y), vector2d<s32>(box->getPoint(3).x, box->getPoint(3).y), SColor(255, 255, 0, 0));
	driver->draw2DLine(vector2d<s32>(box->getPoint(0).x, box->getPoint(0).y), vector2d<s32>(box->getPoint(6).x, box->getPoint(6).y), SColor(255, 255, 0, 0));
	box->~Box();
}

int main()
{
	s32 rocketAnimFrameSizeW = 55;
	s32 rocketAnimFrameSizeH = 83;
	//create collision primitives
	Box* rocketCollision = new Box();
	Sphere* sunCollision = new Sphere();

		//create an instance of the event receiver
	MyEventReceiver receiver;
	receiver.init();

	// create device
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9,
		core::dimension2d<u32>(800, 600), 16, false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	//add scene manager
	scene::ISceneManager* smgr = device->getSceneManager();
	
	video::ITexture* image = driver->getTexture("./media/Rocket_spritesheet.png");
	//driver->makeColorKeyTexture(image, position2d<s32>(0, 0));

	video::ITexture* bgrnd = driver->getTexture("./media/Background_Purple_Space-800x600.jpg");
	//driver->makeColorKeyTexture(bgrnd, position2d<s32>(0, 0));
	
	video::ITexture* sun = driver->getTexture("./media/sunAnim.PNG");
	driver->makeColorKeyTexture(sun, position2d<s32>(0, 0));
	
	//create a scene node to manipulate
	//scene::ISceneNode * node = smgr->addCubeSceneNode();
	//if (node)
	//{
	//	node->setPosition(core::vector3df(5, -30, 30));
	//	node->setMaterialTexture(0, driver->getTexture("./media/Rocket_spritesheet.png"));
	//	node->setMaterialFlag(video::EMF_LIGHTING, false);
	//	node->setScale(vector3df(0.1));

	//	/*scene::ISceneNodeAnimator* anim =
	//		smgr->createFlyCircleAnimator(core::vector3df(0, 0, 30), 20.0f);
	//	if (anim)
	//	{
	//		node->addAnimator(anim);
	//		anim->drop();
	//	}*/
	//}

	//smgr->addCameraSceneNode();
	//device->getCursorControl()->setVisible(false);

	int currentColumn = 0;
	int row = 0;
	int LastFps = -1;

	u32 lastTime = device->getTimer()->getTime();
	u32 lastAnimationFrame = device->getTimer()->getTime();
	u32 lastSunFrame = device->getTimer()->getTime();
	int previousFrame = 0;

	int sunFrame = 0;

	f32 MOVEMENT_SPEEDX = 0.05f;
	f32 MOVEMENT_SPEEDX1 = 0.05f;
	f32 MOVEMENT_SPEEDY = 0.05f;
	f32 MOVEMENT_SPEEDY1 = 0.05f;

	f32 acceeration = 0.0005f;


	position2df RocketPosition(300,300);
	

	while (device->run())
	{
		receiver.endEventProcess();
		const u32 currentTime = device->getTimer()->getTime();
		//u32 Dt = currentTime - lastTime;

		const f32 Dt= (f32)(currentTime - lastTime); // Time in seconds
		lastTime = currentTime;

		//compute how much time has passed since previous frame. If it is > the time between animation frames, curentframe++
		/* Check if keys W, S, A or D are being held down, and move the
		sphere node around respectively. */
//		core::vector3df nodePosition = node->getPosition();

	
		if (MOVEMENT_SPEEDX >= 2.0f)
				MOVEMENT_SPEEDX = 2.0f;
		if (MOVEMENT_SPEEDX <= 0.0f)
				MOVEMENT_SPEEDX = 0.0f;
		if (MOVEMENT_SPEEDY >= 2.0f)
				MOVEMENT_SPEEDY = 2.0f;
		if (MOVEMENT_SPEEDY <= 0.0f)
				MOVEMENT_SPEEDY = 0.0f;
		if (MOVEMENT_SPEEDX1 >= 2.0f)
				MOVEMENT_SPEEDX1 = 2.0f;
		if (MOVEMENT_SPEEDX1 <= 0.0f)
				MOVEMENT_SPEEDX1 = 0.0f;
		if (MOVEMENT_SPEEDY1 >= 2.0f)
				MOVEMENT_SPEEDY1 = 2.0f;
		if (MOVEMENT_SPEEDY1 <= 0.0f)
				MOVEMENT_SPEEDY1 = 0.0f;
		
		if (receiver.keyDown(irr::KEY_KEY_W))
		{
			RocketPosition.Y -= (MOVEMENT_SPEEDY * Dt );
			MOVEMENT_SPEEDY += acceeration * Dt;
		}
		if (receiver.keyUp(irr::KEY_KEY_W))
		{
			RocketPosition.Y -= (MOVEMENT_SPEEDY * Dt);
			MOVEMENT_SPEEDY -= acceeration * Dt;
		}
		if (receiver.keyDown(irr::KEY_KEY_S))
		{
			RocketPosition.Y += (MOVEMENT_SPEEDY1 * Dt);
			MOVEMENT_SPEEDY1 += acceeration * Dt;
		}
		if (receiver.keyUp(irr::KEY_KEY_S))
		{
			RocketPosition.Y += (MOVEMENT_SPEEDY1 * Dt);
			MOVEMENT_SPEEDY1 -= acceeration * Dt;
		}
		if (receiver.keyDown(irr::KEY_KEY_A))
		{
			RocketPosition.X -= MOVEMENT_SPEEDX * Dt;
			MOVEMENT_SPEEDX += acceeration * Dt;
		}
		if (receiver.keyUp(irr::KEY_KEY_A))
		{
			RocketPosition.X -= MOVEMENT_SPEEDX * Dt;
			MOVEMENT_SPEEDX -= acceeration * Dt;
		}
		if (receiver.keyDown(irr::KEY_KEY_D))
		{
			RocketPosition.X += MOVEMENT_SPEEDX1 * Dt;
			MOVEMENT_SPEEDX1 += acceeration * Dt;
		}
		if (receiver.keyUp(irr::KEY_KEY_D))
		{
			RocketPosition.X += MOVEMENT_SPEEDX1 * Dt;
			MOVEMENT_SPEEDX1 -= acceeration * Dt;
		}

		//Set here, in  order to update
		rocketCollision->setFromPoints(Vec3f(RocketPosition.X, RocketPosition.Y, 0),
			Vec3f(RocketPosition.X + rocketAnimFrameSizeW, RocketPosition.Y + rocketAnimFrameSizeH, 0));
		
		sunCollision->center = Vec3f(250, 200, 0);
		sunCollision->radius = 100.0f;

//		node->setPosition(nodePosition);
		
		if (currentTime - lastAnimationFrame >= (1000/60))
		{
			currentColumn++;
			lastAnimationFrame = currentTime;

		}
		if (currentColumn >= 10)
		{
			currentColumn = 0;
			row++;
		}
		if (row >= 6) row = 0;

		//sun animation
		if (currentTime - lastSunFrame >= (1000 / 5))
		{
			sunFrame++;
			lastSunFrame = currentTime;
		}
		if (sunFrame >= 5)
		{
			sunFrame = 0;
		}
	
		/* Check if keys W, S, A or D are being held down, and move the
		sphere node around respectively. */
		
		receiver.startEventProcess();

		driver->beginScene(true, true, SColor(255, 113, 113, 133));

		//smgr->drawAll(); // draw the 3d scene
		
			driver->draw2DImage(bgrnd, position2d<s32>(0, 0),
				rect<s32>(0, 0,
				800, 600), 0,
				SColor(255, 255, 255, 255),true);

			driver->draw2DImage(sun, position2d<s32>(300, 200),
				rect<s32>(sunFrame * 200, 0,
				(sunFrame + 1) * 200, 200), 0,
				SColor(255, 255, 255, 255), true);
			
			driver->draw2DLine(vector2d<s32>(300, 200), vector2d<s32>(400, 300), SColor(255, 0, 255, 0));

		driver->draw2DImage(image, 
			position2d<s32>((s32)RocketPosition.X, (s32)RocketPosition.Y),
				rect<s32>(currentColumn * rocketAnimFrameSizeW, row * rocketAnimFrameSizeH,
				(currentColumn + 1) * rocketAnimFrameSizeW, (row + 1) * rocketAnimFrameSizeH),0,
				SColor(255, 255, 255, 255), true);
		
		drawCollision(rocketCollision, driver);
		//smgr->addCameraSceneNode();
		driver->endScene();

		int fps = driver->getFPS();

		if (LastFps != fps)
		{
			core::stringw stingFPS = L"FPS: ";
			stingFPS += fps;
			device->setWindowCaption(stingFPS.c_str());
			LastFps = fps;
		}
	}

	device->drop();

	return 0;
}

/*
That's all. I hope it was not too difficult.
**/

