#include <iostream>
#include <string.h>

class CString
{
	private:
		static int nb_chr; // Initialisé par défaut à 0;
		int taille; 
		char* str;
	public:
		CString();
		CString( const char* s);
		CString( const char c);
		~CString();
		
		//## Accesseurs ##//
		static int NbrChaines();
		char* getString() const;
		int getTaille() const;
		
		//### Operateurs ###//
		CString operator+(const CString& s);
		CString& operator=(const CString& s);
		bool operator== (const CString& s);
		bool operator>(const CString& s) ;
		bool operator<=(const CString& s) ;
};

