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
		
		static int NbrChaines();
		char* getString() const;
		int getTaille() const;
		
		CString plus(char c);
		bool plusGrandQue( const CString& s);
		bool infOuEgale( const CString& s);
		CString plusGrand( const CString& s);
		
		//### Operateurs ###//
		CString operator+(const CString& s) const ;
		bool CString:: operator>(const CString& s) const;
		bool CString:: operator<=(const CString& s) const;
};


