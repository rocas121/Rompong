#pragma once

#include "timer.h"
#include "Const.h"
#include "Util.h"
#include "Globals.h"
#include "hoshino.h"


#include "paddle.h"
class Game 
{
	private:
		Paddle paddle;
	public:
		Game();
		int run();
		void EventHandler(bool& quit);



};