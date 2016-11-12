using namespace std;

#include <iostream>
#include "CString.h"

CString:: CString()
{
	str = new char[1];
	str[0] = '\0';
	taille = 0;
	nb_chr++;
}
CString:: CString( const char* s)
{
	str = new char[strlen(s)+1];
	strcpy(str,s);
	taille = strlen(s);
	nb_chr++;
}
CString:: CString( const char c)
{
	str = new char[2];
	str[0] = c;
	taille = 1;
	str[1] = '\0';
	nb_chr++;
}

CString:: ~CString()
{
	cout << "destruction :"<< this->getString() << endl;
	delete []str;	// Destruction de la chaine str
	nb_chr--;
	
}

//### Accesseurs ###//

char* CString:: getString() const
{
		return str;
}

int CString:: getTaille() const
{
	return taille;
}

int CString:: NbrChaines()
{
	return CString:: nb_chr;
}

//### Surchage opérateur ###//

CString CString:: operator+(const CString& s) 
{
	int tailleC = this->getTaille() + s.getTaille() + 1;
    char* tmp = new char[tailleC];
    strcpy(tmp, getString());
    strcat(tmp, s.getString());
    CString result = CString(tmp);
    return result;
}

CString& CString:: operator=(const CString& s)  
{
	if (this != &s )
	delete[] str;
	str = new char [taille = s.getTaille()+1];
	strcpy(str, s.str);
	return *this;
}

bool CString:: operator>(const CString& s)
{
	if(strcmp(this->getString(), s.getString())>0)
        return true;
    else 
		return false;
}

bool CString:: operator<=(const CString& s) 
{
	if(strcmp(s.getString(), this->getString()) >=0)
        return true;
    else 
		return false;
}

int CString:: nb_chr;

int main()
{
	CString s1("toto"), s2('g'), s3;
	s3 = s1;
	cout << s3.getString() << endl;
	s1 = s1 + s2;
	cout << s1.getString() << endl;
if (s1 > s2)	cout << "S1(totog) olus grand que s2(g)" << endl;
if (s1 <= s1)	cout << "S1 = s1" << endl;
	return 0;
}
