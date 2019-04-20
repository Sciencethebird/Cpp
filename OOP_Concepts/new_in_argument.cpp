#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class foo{
public:
	foo(string in) {
		cout << "class constructor " <<in << endl;
		a = in;
	}
	~foo() {
		//cout << "obj destroyed" << endl;
	}
	string method() {
		return a;
	}
private:
	string a = "";
};

foo* ff(foo *temp) {

	cout << "Function called, member in obj "<< temp->method() << endl;
	//delete temp; //if you delete temp, temp has to be a pointer(something created by operator new)
	return temp;
}
int main()
{
	foo tp("tp");
	foo* t1 = ff(&tp);
	foo* t2 = ff(new foo("t2"));
	foo* t3 = new foo("t3");
	ff(t3);

	t1->method();
	//ff(&foo("extract ptr"));  // This will cause error, cuz you can't delete non-pointer
	
}
