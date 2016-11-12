using namespace std;

#include <iostream>
#include "Definition.h"

Definition:: Definition(const char* c, const char* d): clef(c), def(d) {}
Definition:: Definition(const Definition& d)
{
	clef = d.getClef();
	def = d.getMot();
}
Definition:: ~Definition(){}

CString Definition:: getClef() const
{
	return clef;
}

CString Definition:: getMot() const
{
	return def;
}

Definition& Definition:: operator=(const Definition& d)
{
	this->def = d.getMot();
	this->clef = d.getClef();
}

