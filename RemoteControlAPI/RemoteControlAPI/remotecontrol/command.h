#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <functional>
#include <boost\any.hpp>

namespace rc{

	enum CommandType{
		CLOSE,
		START,
		REGISTER_ACTION,
		REGISTER_VARIABLE,
		REGISTER_ACTION_TO_DEFAULT,
		REGISTER_DEFAULT_ACTION,
		CHANGE_CONTEXT,
		EXECUTE,
		ERROR,
		OTHER,
		SIZE_OF_COMMANDS};
	static const char* CommandTypes[SIZE_OF_COMMANDS] = { "close",
														  "start", 
														  "register_action", 
														  "register_variable",
														  "register_to_default",
														  "register_default_action",
														  "change_context",
														  "execute",
														  "error",
														  "other"};

	class Command{
	public:
		Command();
		// close/start
		Command(CommandType _type);
		// execute
		Command(CommandType _type, boost::any _content);
		// change context
		Command(CommandType _type, int _context);
		// full default
		Command(CommandType _type, boost::any _content, int _actionType, int _context);
		// full action
		Command(CommandType _type, boost::any _content, int _primitiveType, std::string _name, int _preferedModule, int _context);
		// full to default assign
		Command(CommandType _type, int _actionType, std::string _name, int _primitiveType, int _preferedModule, int _context);
		~Command();
		CommandType getType();
		boost::any getContent();
		void setContent(boost::any _content);
		int execute();
		int execute(int arg);
		int execute(float arg);
		int execute(double arg);
		int execute(std::string arg);
		int getActionType();
		int getPrimitiveType();
		int getContext();
		std::string getName();
		int getPreferedModule();
		void setParams(std::string _params);
		std::string getParams();
		int getValueType();
		void setValueType(int _valueType);
	private:
		CommandType type;
		boost::any content;
		int actionType, primitiveType, preferedModule, context;
		int valueType;
		std::string name, params;
	};
}

#endif;