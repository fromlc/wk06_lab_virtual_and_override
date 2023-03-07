//------------------------------------------------------------------------------
// Pr15-17.cpp : demos a subtle error that can occur with virtual functions
// 
// Author: Tony Gaddis in Gaddis 9e, pp. 961-962
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// Base : class with virtual funA
//------------------------------------------------------------------------------
class Base {
public:

	virtual void funA(int arg) const {
		cout << "This is Base::funA" << '\n';
	}
};

//------------------------------------------------------------------------------
// Derived : redefines Base::funA
//------------------------------------------------------------------------------
class Derived : public Base {
public:

	//virtual void funA(long arg) const {
	//virtual void funA(long arg) const override {
	virtual void funA(int arg) const {
	//void funA(int arg) const {
		cout << "This is Derived::funA" << '\n';
	}
};

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// allocate instances on the stack
	Base b;
	Derived d;

	// call funA with the two stack instances
	cout << "\nusing stack instances:\n";
	cout << "b: ";
	b.funA(99);
	cout << "d: ";
	d.funA(99);

	// allocate instances on the heap, use pointers to access instances
	Base* bP1 = new Base();
	Base* bP2 = new Derived();
	Derived* dP = new Derived();

	// call funA with the two pointers
	cout << "\nusing heap instances:\n";
	cout << "bP1: ";
	bP1->funA(99);
	cout << "bP2: ";
	bP2->funA(99);
	cout << "dP: ";
	dP->funA(99);

	return 0;
}