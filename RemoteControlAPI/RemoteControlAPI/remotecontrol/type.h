#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <vector>
#include "rc_var.h"
#include "any.h"

namespace rc{
	class Type {
	public:
		Type();
		~Type();
		void getContentFromData(std::string data);
		void setValueType(int valueType);
	protected:
		int valueType;
	};

	class Scalar:public Type{
	public:
		Scalar(){valueType = RC_SCALAR;}
		~Scalar();
	private:
		int content;
	};

	class Vector:public Type{
	public:
		Vector(){valueType = RC_VECTOR;}
		~Vector();
	private:
		any x, y, z;
	};

	class Matrix:public Type{
	public:
		Matrix(){valueType = RC_MATRIX;}
		~Matrix();
	private:
		any a00, a01, a02, a10, a11, a12, a20, a21, a22;
	};

	class Image:public Type{
	public:
		Image(){valueType = RC_IMAGE;}
		~Image();
	private:
	};

	class Text:public Type{
	public:
		Text(){valueType = RC_TEXT;}
		~Text();
	private:
	};

	class Logical:public Type{
	public:
		Logical(){valueType = RC_LOGICAL;}
		~Logical();
	private:
	};

	class Field:public Type{
	public:
		Field(){valueType = RC_FIELD;}
		~Field();
	private:
	};
}

#endif;