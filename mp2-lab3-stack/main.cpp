#include <iostream>
#include "Calk.h"
using namespace std;


void main () {

	string inf="2*6+8", inf1="2*6+8)", inf2="2-8";
	TCalk Calk(inf), Calk2(inf1);
	TStack<int> A(200);

	cout << Calk2.Cheek() << endl;

	cout << "inf: " << inf << endl;
	cout << "inf2: " << inf2 << endl;
	cout << "Infix: " <<Calk.GetInfix() << endl;
	Calk.ToPostfix();
	cout << "Postfix: " <<Calk.GetPostfix() << endl;
	cout << "Result: " <<Calk.CCalk() << endl;
	Calk.SetInfix(inf2);
	cout << "SetInfix2: " << Calk.GetInfix() << endl;
}