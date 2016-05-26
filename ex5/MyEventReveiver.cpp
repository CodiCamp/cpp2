
/// ==================================================================================================
/// MastEventReceiver code is © (Copyright) Robert E. Demarest, AKA Mastiff or Mastiff Odit
/// This file may be used in any non-commercial or commercial project as long as the following conditions are met:
/// You may not claim this code as being your own.
/// You may not use this code for any harmful, malicious or otherwise damaging programs.
///
/// This is version 1.2a of the class.
/// This class is designed for use with the Irrlicht Engine, it was written for version 1.3 of the engine.
/// ==================================================================================================

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// To use this Class just add  #include "MastEventReceiver.cpp"  to the end of your includes list. (or add the class in-line into your program)
// Then create an instance of it like so: MastEventReceiver eventReceiver;
// Then call the initialization fucntion like so: eventReceiver.init();
// Then inside your Main Game Loop place "eventReceiver.endEventProcess();" in the beginning of your game loop, before anything -
// that would require input, then put "eventReceiver.startEventProcess();" at the very end of your Main Game Loop.
// yeah I know it's confusing, but it makes alot more sense in the internals of the class.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Change this to the path where your Irrlicht Header Files are.
//#include "./irrlicht/irrlicht.h"

#include "MyEventReceiver.h"

	//////////////////////
	// Public functions
	//////////////////////

	float mouseWheel()
	{
		return mouse.wheel;
	}

	int mouseX()
	{
		return mouse.X;
	}

	int mouseY()
	{
		return mouse.Y;
	}

	bool leftMouseReleased()
	{
		if (mouseButtonState[0] == RELEASED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool leftMouseUp()
	{
		if (mouseButtonState[0] == RELEASED || mouseButtonState[0] == UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool leftMousePressed()
	{
		if (mouseButtonState[0] == PRESSED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool leftMouseDown()
	{
		if (mouseButtonState[0] == PRESSED || mouseButtonState[0] == DOWN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool middleMouseReleased()
	{
		if (mouseButtonState[1] == RELEASED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool middleMouseUp()
	{
		if (mouseButtonState[1] == RELEASED || mouseButtonState[1] == UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool middleMousePressed()
	{
		if (mouseButtonState[1] == PRESSED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool middleMouseDown()
	{
		if (mouseButtonState[1] == PRESSED || mouseButtonState[1] == DOWN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool rightMouseReleased()
	{
		if (mouseButtonState[2] == RELEASED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool rightMouseUp()
	{
		if (mouseButtonState[2] == RELEASED || mouseButtonState[2] == UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool rightMousePressed()
	{
		if (mouseButtonState[2] == PRESSED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool rightMouseDown()
	{
		if (mouseButtonState[2] == PRESSED || mouseButtonState[2] == DOWN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}//

	bool keyPressed(char keycode)
	{
		if (keyState[keycode] == PRESSED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool keyDown(char keycode)
	{
		if (keyState[keycode] == DOWN || keyState[keycode] == PRESSED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool keyUp(char keycode)
	{
		if (keyState[keycode] == UP || keyState[keycode] == RELEASED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool keyReleased(char keycode)
	{
		if (keyState[keycode] == RELEASED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	// This is used so that the Key States will not be changed during execution of your Main game loop.
	// Place this at the very START of your Main Loop
	void endEventProcess()
	{
		processState = ENDED;
	}

	// This is used so that the Key States will not be changed during execution of your Main game loop.
	// Place this function at the END of your Main Loop.
	void startEventProcess()
	{

		processState = STARTED;
		//Keyboard Key States
		for (int i = 0; i < KEY_KEY_CODES_COUNT; i++)
		{
			if (keyState[i] == RELEASED)
			{
				keyState[i] = UP;
			}

			if (keyState[i] == PRESSED)
			{
				keyState[i] = DOWN;
			}
		}
		//Mouse Button States
		for (int i = 0; i <= 2; i++)
		{
			if (mouseButtonState[i] == RELEASED)
			{
				mouseButtonState[i] = UP;
			}

			if (mouseButtonState[i] == PRESSED)
			{
				mouseButtonState[i] = DOWN;
			}
		}
		//Mouse Wheel state
		mouse.wheel = 0.0f;

	}

	void init()
	{
		//KeyBoard States.
		for (int i = 0; i <= KEY_KEY_CODES_COUNT; i++)
		{
			keyState[i] = UP;
		}
		//Mouse states
		for (int i = 0; i <= 2; i++)
		{
			mouseButtonState[i] = UP;
		}
		//Mouse X/Y coordenates.
		mouse.X = 0;
		mouse.Y = 0;
		mouse.wheel = 0.0f;
	}

/// ==========================================
/// END OF MastEventReceiver
/// ==========================================
