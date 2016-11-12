using namespace std;

#include <iostream>
#include "Definition.h"

Definition:: Defintion(const char* c, const char* d): clef(CString(c)), def(CString(d)) {}
Definition:: ~Defintion()
{
	cout << "destruction du mot " << getClef() << endl;
}

char* Defintion:: getClef() const
{
	return clef.getString();
}

char* Defintion:: getDef() const
{
	return def.getString();
}

int main()
{
	Definition homer ("Homer", "Buveur de biere");
	cout << "La def du mot " << homer.getClef() << "est " << homer.getDef() << endl;
	
}
