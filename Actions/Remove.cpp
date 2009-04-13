#include "Remove.h"
#include "../Saiph.h"
#include "../World.h"

using namespace std;
using namespace action;

Remove::Remove(unsigned char key, int priority) : remove(REMOVE, priority), remove_key(string(1, key), PRIORITY_CONTINUE_ACTION) {
}

Remove::~Remove() {
}

const Command &Remove::getCommand() {
	switch (sequence) {
	case 0:
		return remove;
		
	case 1:
		return remove_key;

	default:
		return Action::noop;
	}
}

void Remove::updateAction(const Saiph *saiph) {
	if (saiph->world->question && saiph->world->messages.find(MESSAGE_WHAT_TO_REMOVE) != string::npos)
		sequence = 1;
	else if (sequence == 1)
		sequence = 2;
}
