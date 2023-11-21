#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

class Base
{
	public:
		Base(void);
		virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};