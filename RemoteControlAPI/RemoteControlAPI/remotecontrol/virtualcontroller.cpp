#include "virtualcontroller.h"
#include <iostream>
#include <string>
#include <stdexcept>

namespace rc{
	VControl::VControl(){
		//std::cout << "VControl created" << std::endl;
	}

	VControl::~VControl(){
		//std::cout << "VControl detroyed" << std::endl;
	}

	void VControl::registerAction(boost::any _f, int _context, int _port){
		actions[_context][_port] = _f;
	}

	void VControl::registerDefaultAction(boost::any _f, int _actionType, int _context){
		defaultActions[_context][_actionType] = _f;
	}

	boost::any VControl::getAction(int _id, int _type, int _context, int _port){
		try{
			// action type of default action
			int defaultAction = boost::any_cast<int>(actions[_context][_port]);
			return getDefaultAction(_id, _type, _context, defaultAction);
		} catch (...) {
			return actions[_context][_port];
		}
	}

	boost::any VControl::getDefaultAction(int _id, int _type, int _context, int _actionType){
		return defaultActions[_context][_actionType];
	}

}