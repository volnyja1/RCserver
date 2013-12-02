#include "remotecontrol\rc.h"

void ahoj(){
	std::cout << "Callback function" << std::endl;
}

void ahoj2(int a){
	std::cout << "Callback function: " << a << std::endl;
}

int main (){

	rc::init();

	system("pause");

	//int a = 2;
	//rc::assign(&a, "button 1", rc::RC_INT, rc::ACCELEROMETER);

	//rc::registerFunction([]{std::cout << "hello\n";}, rc::RC_FLOAT, "arrow up", rc::ARROWS);
	rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROW_UP);
	//rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROWS);
	//rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROWS, 25);
	rc::registerDefaultAction(rc::STEP_FORWARD,&ahoj2);
	rc::registerDefaultListener(rc::STEP_FORWARD,rc::RC_FLOAT,"krok zpet",rc::ARROW_DOWN);

	rc::start();

	system("pause");

	std::cout << "executing...\n";
	rc::executeActions();

	system("pause");

	rc::close();

	system("pause");

	return 0;

}