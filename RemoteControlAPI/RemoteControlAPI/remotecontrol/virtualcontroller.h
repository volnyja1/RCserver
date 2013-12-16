#ifndef VIRTUALCONTROLLER_H
#define VIRTUALCONTROLLER_H

#include <string>
#include <map>
#include <boost\any.hpp>
#include "any.h"

namespace rc{
	class VControl{
	public:
		VControl();
		~VControl();
		void registerAction(boost::any _f, int _context, int _port);
		void registerDefaultAction(boost::any _f, int _actionType, int _context);
		boost::any getAction(int _id, int _type, int _context, int _port);
	private:
		boost::any getDefaultAction(int _id, int _type, int _context, int _port);
		// map<context,map<port,action>>
		std::map<int,std::map<int,boost::any>> actions;
		std::map<int,std::map<int,boost::any>> defaultActions;
	};
}

#endif;