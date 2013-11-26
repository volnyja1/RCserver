#include "type.h"

/*namespace rc{
	template <typename T> Type(T const& value): ptr_(new data<T>(value)) {}
		
	Type::Type(Type const& other): ptr_(other.ptr_->clone()) {}
		
	Type& operator= (Type const& other) {
		Type(other).swap(*this);
		return *this;
	}
		
	Type::~Type() {
		delete this->ptr_;
	}
		
	void Type::swap(Type& other) {
		std::swap(this->ptr_, other.ptr_);
	}

	template <typename T>
	Type::T& get() {
		return dynamic_cast<data<T>&>(*this->ptr_).value_;
	}
}*/