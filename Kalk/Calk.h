
#include "Stack.h"
#include <string>
using namespace std;

class TCalk {
	string infix;
	string postfix;
	TStack<char> StCh;
	TStack<double> StD;
public:
	TCalk (string _inf="");

	int Cheek();				//�������� ������������ ������
	int Priority(char ch);		//��������� ���������� ��������
	void ToPostfix();			//����������� � ����������� �������
	double CCalk();				//���������� ���������

	string GetInfix();			//��������� ��������� ������
	string GetPostfix();		//��������� ����������� ������
	void SetInfix(string _inf);	//������ ������ � ���������

};