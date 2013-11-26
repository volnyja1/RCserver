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
	rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROWS);
	//rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROWS);
	//rc::registerFunction(&ahoj, rc::RC_FLOAT, "arrow up", rc::ARROWS, 25);
	rc::registerDefaultAction(rc::STEP_FORWARD,&ahoj2);
	rc::registerDefaultListener(rc::STEP_FORWARD,rc::RC_FLOAT,"krok zpet",rc::ARROWS);

	rc::start();

	system("pause");

	std::cout << "executing...\n";
	rc::executeActions();

	system("pause");

	rc::close();

	system("pause");

	return 0;

	  /*string s = "1234";
	  istringstream is(s);
	  int num;
	  is >> num;
	  cout << "Èíslo je " << num << endl;
	  return 0;*/

}


/*#include <iostream>
#include <vector>

class any
{
private:
    struct base {
        virtual ~base() {}
        virtual base* clone() const = 0;
    };
    template <typename T>
    struct data: base {
        data(T const& value): value_(value) {}
        base* clone() const { return new data<T>(*this); }
        T value_;
    };
    base* ptr_;
public:
    template <typename T> any(T const& value): ptr_(new data<T>(value)) {}
    any(any const& other): ptr_(other.ptr_->clone()) {}
    any& operator= (any const& other) {
        any(other).swap(*this);
        return *this;
    }
    ~any() { delete this->ptr_; }
    void swap(any& other) { std::swap(this->ptr_, other.ptr_); }

    template <typename T>
    T& get() {
        return dynamic_cast<data<T>&>(*this->ptr_).value_;
    }
};

int main()
{
	std::vector<any> v;
    any a0(17);
    any a1(3.14);
	double x = 2.32;
	v.push_back(a0);
	v.push_back(a1);
    try { a0.get<double>(); } catch (...) {}
    std::cout << v[0].get<int>() << "\n";
	v[0] = x;
    std::cout << v[0].get<double>() << "\n";
	system("pause");
}*/