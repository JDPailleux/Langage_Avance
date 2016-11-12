using namespace std;

#include <iostream>
#include "Cstring.h"

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
	delete []str;
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

//### Surchage opérateur ### //

CString CString:: operator+(const CString& s) const
{
	taille = getTaille() + s.getTaille() + 1;
    char* tmp = new char[taille];
    strcpy(tmp, getString());
    strcat(tmp, s.getString());
    CString result = CString(tmp);
    return result;
}

bool CString:: operator>(const CString& s) const
{
	if(strcmp(this->getString(), s.getString())>0)
        return true;
    else 
		return false;
}

bool CString:: operator<=(const CString& s) const
{
	if(strcmp(this->getString(), s.getString())>0)
        return true;
    else 
		return false;
}

//### Restes fonctions ###//

CString CString:: plus(char c)
{
	CString cs = CString(c);
	taille++;
	return (*this) + cs;
}


bool CString:: plusGrandQue( const CString& s)
{
	
	if(strcmp(this->getString(), s.getString())>0)
        return true;
    else 
		return false;
}

bool CString:: infOuEgale( const CString& s)
{
	return !this->plusGrandQue(s);
}
CString CString:: plusGrand( const CString& s) 
{
	if ( plusGrandQue(s) ) return *this;
	else return s;
}
int CString:: nb_chr;




int main()
{
	CString s1("toto"),
			s2('q'),
			s3;
			
	
	cout << "nbrChaines " << CString::NbrChaines() << endl;
	//afficher le nombre de chaines crées
	
	s3 = s1.plus( 'w');
	cout << "s3 = " << s3.getString() << endl;
	
	if ( s1.plusGrandQue(s2) ) // Si s1 > s2 au sens alphabetique 
		cout << "plus grand" << endl;
		
	if ( s1.infOuEgale(s2) ) // si s1 <= s2 au sens alphabétique
		cout << "plus petit" << endl;
		
	s3 = s1.plusGrand( s2); // retourner s1 si s1>s2, s2 sinon
	
	return 0;
}
/*
 char* tmp2 = new char[2];
		tmp2[0] = c;
		tmp2[1] = '\0';
		
    strcat(str, tmp2);
    taille++;
    delete []tmp2;
    cout << "contenu de str:" <<str << endl;
   CString cs(str);
   return cs;
} 
*/
