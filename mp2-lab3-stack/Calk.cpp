
#include "Calk.h"

bool TCalk::Cheek(){
	StCh.Clear();
	for(int i=0; i<infix.size(); i++) {
		if(infix[i]=='(')
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
			//-------------------------------
			//*******************************
			//-------------------------------
		}
}