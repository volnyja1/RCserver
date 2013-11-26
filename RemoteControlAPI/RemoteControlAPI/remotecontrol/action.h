#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <functional>

namespace rc{

	class Action{
	public:
		Action();
		Action(std::function<void()> _action);
		~Action();
		std::function<void()> getAction();
	private:
		std::function<void()> action;
	};
}

#endif;