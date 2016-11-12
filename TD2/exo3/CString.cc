using namespace std;


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

CString:: ~CString() // Redefinir le constructeur par copie et l'operateur =
{
//	delete []str;	// Destruction de la chaine str
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

 bool CString::operator==(const CString& c){ return strcmp(getString(), c.getString()) == 0;}

int CString:: nb_chr;


