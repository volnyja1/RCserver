#include "remotecontrol\rc.h"

int ahoj(){
	std::cout << "Callback function" << std::endl;
	return 0;
}

int ahoj2(int a){
	std::cout << "Callback function: " << a << std::endl;
	return 0;
}

int main (){

	rc::init();

	system("pause");

	////int a = 2;
	////rc::assign(&a, "button 1", rc::RC_INT, rc::ACCELEROMETER);

	////rc::registerFunction([]{std::cout << "hello\n";}, rc::RC_FLOAT, "arrow up", rc::ARROWS);
	rc::registerFunction(&ahoj, rc::RC_VOID, "arrow up", rc::JOYSTICK_UP);
	rc::registerFunction(&ahoj, rc::RC_VOID, "arrow up", rc::JOYSTICK_DOWN);
	rc::registerFunction(&ahoj, rc::RC_VOID, "arrow up", rc::JOYSTICK_RIGHT);
	rc::registerFunction(&ahoj, rc::RC_VOID, "arrow up", rc::JOYSTIXK_LEFT);
	////rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROWS);
	////rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROWS, 25);
	/*rc::registerDefaultAction(rc::STEP_FORWARD,&ahoj2);
	rc::registerDefaultListener(rc::STEP_FORWARD,rc::RC_INT,"krok zpet",rc::ARROW_DOWN);*/

	rc::start();

	//rc::setContext(rc::DEFAULT_CONTEXT);

	system("pause");

	std::cout << "executing...\n";
	rc::executeActions();

	system("pause");

	rc::close();

	system("pause");

	return 0;

}