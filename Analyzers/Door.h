#ifndef DOOR_H
#define DOOR_H
/* messages */
#define DOOR_DOOR_LOCKED "  This door is locked.  "
#define DOOR_UNLOCK_IT "  Unlock it? [yn] (n)  "
#define DOOR_BREAK_SHOP_DOOR "  \"Cad!  You did 400 zorkmids worth of damage!\"  Pay?  [yn] (n)  "

#include <string>
#include "../Analyzer.h"
#include "../Point.h"

class Saiph;

class Door : public Analyzer {
	public:
		Door(Saiph *saiph);

		void analyze();
		void parseMessages(const std::string &messages);

	private:
		Saiph *saiph;
		std::string command2;
		Point position;
		unsigned char unlock_tool_key;
		bool in_a_pit;

		void findUnlockingTool();
};
#endif
