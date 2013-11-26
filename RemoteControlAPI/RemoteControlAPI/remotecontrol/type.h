#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <vector>

namespace rc{
	class Type {
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
		template <typename T> Type(T const& value): ptr_(new data<T>(value)) {}
		Type(Type const& other): ptr_(other.ptr_->clone()) {}
		Type& operator= (Type const& other) {
			Type(other).swap(*this);
			return *this;
		}
		~Type() { delete this->ptr_; }
		void swap(Type& other) { std::swap(this->ptr_, other.ptr_); }

		template <typename T>
		T& get() {
			return dynamic_cast<data<T>&>(*this->ptr_).value_;
		}
	};

	class Scalar{

	};

	class Vector{

	};

	class Matrix{

	};

	class Image{

	};

	class Text{

	};

	class Logical{

	};

	class Field{

	};
}

#endif;