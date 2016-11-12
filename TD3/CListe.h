
class CNoeud
{
	private:
		int val;
		CNoeud *next;
	public:
		CNoeud(int val);
		CNoeud(const CNoeud& n);
		~CNoeud();
		int getVal() const;
		CNoeud* getNext() const;
		void setNext(CNoeud *n);
};

class CList
{
	protected:
		CNoeud *tete;
	public:
		CList();
		~CList();
		CNoeud* getTete() const;
		virtual CList& operator<(int i) = 0; 
		virtual CList& operator>(int& i);
};

class CPile : public CList
{
	public:
		CPile();
		~CPile();
		CPile& operator<(int i);
		CPile& operator>(int& i);
};

class CFile : public CList
{
	public:
		CFile();
		~CFile();
		CFile& operator<(int i);
		CFile& operator>(int& i);
};