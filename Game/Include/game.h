#pragma once

#include "timer.h"
#include "hoshino.h"
#include "Const.h"
#include "Util.h"
#include "Globals.h"

class Game 
{
	public:
		Game();
		int run();
		void EventHandler(bool& quit);

};