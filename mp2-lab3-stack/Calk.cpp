
#include "Calk.h"

TCalk::TCalk(string _inf): StCh(100), StD(100){
		infix=_inf;
		postfix="";
	}


bool TCalk::Cheek(){
	StCh.Clear();
	for(int i=0; i<infix.size(); i++) {
		if(infix[i]=='(')
			if(StCh.IsFull())
				throw -1;
			else
				StCh.Push('(');			//Проверку на переполенние
		if(infix[i]==')') 
			if(StCh.IsEmpty())
				return false;
			else
				StCh.Pop();
	}
	if(!StCh.IsEmpty())
		return false;
	else
		return true;
}
int TCalk::Priority(char ch){
	int res;
	switch (ch) {
	case '+': res=1; break;
	case '-': res=1; break;
	case '*': res=2; break;
	case '/': res=2; break;
	case '^': res=3; break;
	case '(': res=0; break;
	case ')': res=0; break;
	default: throw -1; break;
	}
	return res;
}
void TCalk::ToPostfix() {
	StCh.Clear();
	string buf='(' + infix + ')';

	for(int i=0; i<buf.size(); i++) {
		if(buf[i]=='(')
			StCh.Push('(');
		if(buf[i]>='0' && buf[i]<='9' || buf[i]=='.')
			postfix += buf[i];
		if(buf[i]==')') {
			char el=StCh.Pop();
			while(el!='(') {
				postfix += el;
				el=StCh.Pop();
			}
		}
		if (buf[i]=='+' || buf[i]=='-' || buf[i]=='*' || buf[i]=='/' || buf[i]=='^') {
			postfix += " ";
			while(Priority(buf[i]) <= Priority(StCh.Top()) )
				postfix+=StCh.Pop();
			StCh.Push(buf[i]);
		}
	}
}
double TCalk::CCalk(){
	if(Cheek()){
		StD.Clear();
		for(int i=0; i<postfix.size(); i++){
			if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^') {
				double op1, op2, res;
				op2=StD.Pop();
				op1=StD.Pop();
				switch (postfix[i]){
					case '+': res=op1+op2; break;
					case '-': res=op1-op2; break;
					case '*': res=op1*op2; break;
					case '/': res=op1/op2; break;
					case '^': res=pow(op1, op2); break;
				}
				StD.Push(res);
			}
			if(postfix[i]>='0' && postfix[i]<='9' || postfix[i]=='.'){
				char* tmp;
				double res;
				res = strtod(&postfix[i], &tmp);
				int j=tmp-&postfix[i];
				i+=j-1;
				StD.Push(res);
			}
		}
		//Проверка стека на наличие одного лишь элемента
		return StD.Pop();
	}
	else
		throw "Error";
}

string TCalk::GetInfix(){
	return infix;
}
string TCalk::GetPostfix(){
	return postfix;
}
void TCalk::SetInfix(string _inf){
	infix=_inf;
}

