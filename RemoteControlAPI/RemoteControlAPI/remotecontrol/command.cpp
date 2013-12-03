#include "command.h"
#include <iostream>

namespace rc{
	Command::Command(){
		//std::cout << "Command created" << std::endl;
	}

	Command::Command(CommandType _type){
		//std::cout << "Command created" << std::endl;
		type = _type;
	}

	Command::Command(CommandType _type, int _context){
		//std::cout << "Command created" << std::endl;
		type = _type;
		context = _context;
	}

	Command::Command(CommandType _type, boost::any _content){
		//std::cout << "Command created" << std::endl;
		type = _type;
		content = _content;
	}

	Command::Command(CommandType _type, boost::any _content, int _actionType, int _context){
		//std::cout << "Command created" << std::endl;
		type = _type;
		content = _content;
		actionType = _actionType;
		context = _context;
	}

	Command::Command(CommandType _type, boost::any _content, int _primitiveType, std::string _name, int _preferedModule, int _context){
		//std::cout << "Command created" << std::endl;
		type = _type;
		content = _content;
		primitiveType = _primitiveType;
		name = _name;
		preferedModule = _preferedModule;
		context = _context;
	}

	Command::Command(CommandType _type, int _actionType, std::string _name, int _primitiveType, int _preferedModule, int _context){
		//std::cout << "Command created" << std::endl;
		type = _type;
		actionType = _actionType;
		primitiveType = _primitiveType;
		name = _name;
		preferedModule = _preferedModule;
		context = _context;
	}

	Command::~Command(){
		//std::cout << "Command destroyed" << std::endl;
	}

	CommandType Command::getType(){
		return type;
	}

	boost::any Command::getContent(){
		return content;
	}

	void Command::setContent(boost::any _content){
		content = _content;
	}

	int Command::getActionType(){
		return actionType;
	}

	int Command::getPrimitiveType(){
		return primitiveType;
	}

	int Command::getContext(){
		return context;
	}

	std::string Command::getName(){
		return name;
	}

	int Command::getPreferedModule(){
		return preferedModule;
	}

	void Command::setParams(std::string _params){
		params = _params;
	}

	std::string Command::getParams(){
		return params;
	}

	int Command::getValueType(){
		return valueType;
	}

	void Command::setValueType(int _valueType){
		valueType = _valueType;
	}

	int Command::execute(){
		try{
			return boost::any_cast<int(*)()>(content)();
		} catch (...){
		}
		try{
			return boost::any_cast<std::function<int()>>(content)();
		} catch (...){
		}
	}

	int Command::execute(int arg){
		try{
			return boost::any_cast<int(*)(int)>(content)(arg);
		} catch (...){
		}
		try{
			return boost::any_cast<std::function<int(int)>>(content)(arg);
		} catch (...){

		}
	}

	int Command::execute(float arg){
		try{
			return boost::any_cast<int(*)(float)>(content)(arg);
		} catch (...){
		}
		try{
			return boost::any_cast<std::function<int(float)>>(content)(arg);
		} catch (...){

		}
	}

	int Command::execute(double arg){
		try{
			return boost::any_cast<int(*)(double)>(content)(arg);
		} catch (...){

		}
		try{
			return boost::any_cast<std::function<int(double)>>(content)(arg);
		} catch (...){

		}
	}

	int Command::execute(std::string arg){
		try{
			return boost::any_cast<int(*)(std::string)>(content)(arg);
		} catch (...){

		}
		try{
			return boost::any_cast<std::function<int(std::string)>>(content)(arg);
		} catch (...){

		}
	}
}