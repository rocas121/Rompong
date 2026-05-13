#pragma once
#ifndef GAME_H
#define GAME_H

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
		Paddle npcPaddle;
	public:
		Game();
		int run();
		void EventHandler(bool& quit);



};

#endif