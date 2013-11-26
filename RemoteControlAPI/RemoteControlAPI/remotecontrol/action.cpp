#include "action.h"
#include <iostream>

namespace rc{
	Action::Action(){
		std::cout << "Command created" << std::endl;
	}

	Action::Action(std::function<void()> _action){
		std::cout << "Command created" << std::endl;
		action = _action;
	}

	Action::~Action(){
		std::cout << "Command destroyed" << std::endl;
	}

	std::function<void()> Action::getAction(){
		return action;
	}
}