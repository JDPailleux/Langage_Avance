#include "CString.h"

class Definition
{
	private:
		CString clef;
		CString def;
		
	public:
		Definition(const char* c, const char* d);
		Definition(const Definition& d);
		~Definition();
		CString getClef() const;
		CString getMot() const;
		Definition& operator=(const Definition& cs);
	
};
