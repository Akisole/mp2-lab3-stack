
#include "Stack.h"
#include <string>
using namespace std;

class TCalk {
	string infix;
	string postfix;
	TStack<char> StCh;
public:
	


	bool Cheek();		//�������� ������������ ������
	void ToPostfix();	//����������� � ����������� �������

};