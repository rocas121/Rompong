#include "timer.h"
#include "hoshino.h"

#include "Const.h"
#include "Util.h"
#include "Globals.h"

class Game 
{
	private:

		float hue_ = 0.0f;

	public:
		//Base
		Game();
		int run();
		void EventHandler(bool& quit);

};