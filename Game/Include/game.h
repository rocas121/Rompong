#pragma once

#include "timer.h"
#include "Const.h"
#include "Util.h"
#include "Globals.h"

#include "paddle.h"
#include "ball.h"

class Game 
{
	private:
		Paddle paddle;
	public:
		Game();
		int run();
		void EventHandler(bool& quit);



};