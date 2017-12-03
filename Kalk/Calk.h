
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

	int Cheek();				//Проверка корректности скобок
	int Priority(char ch);		//Получение приоритета операций
	void ToPostfix();			//Конвертация в постфиксную записть
	double CCalk();				//Вычисление выражения

	string GetInfix();			//Получение инфиксной строки
	string GetPostfix();		//Получение постфиксной строки
	void SetInfix(string _inf);	//Запись строки в инфиксную

};