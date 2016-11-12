#include <iostream>
#include "CList.h"

using namespace std;

//########## CNOEUD ###########//

CNoeud::CNoeud(int v){ val = v; next = NULL; }
CNoeud::CNoeud(const CNoeud& n)
{
	val = n.getVal();
	CNoeud *ptr = n.getNext();
	if(ptr == NULL)
		next = NULL;
	
	next = new CNoeud(ptr->getVal());
	ptr = ptr->getNext();
	CNoeud *ptr2 = next;
	while(ptr != NULL)
	{
		ptr2 = new CNoeud(ptr->getVal());
		ptr = ptr->getNext();
		ptr2 = ptr2->getNext();
	}
}
CNoeud::~CNoeud(){ delete next; }
int CNoeud::getVal() const{ return val; }
CNoeud* CNoeud::getNext() const{ return next; }
void CNoeud::setNext(CNoeud *n){ next = n; }
		
//########## CLIST ###########//

CList::CList(){ tete = NULL; }
CList::~CList(){ delete tete; }
CNoeud* CList::getTete() const{ return tete; }
ostream& operator<<(ostream& o, const CList& p)
{
	CNoeud *ptr = p.getTete();
	while(ptr != NULL)
	{
		o << ptr->getVal() << ' ';
		ptr = ptr->getNext();
	}
	o << endl;
	return o;
}
CList operator>(int& i){
	if (tete != NULL){}
		i = tete->getVal();
		Noeud* tmp = tete->getNext();
		tete->setNext(NULL);
		delete tete;
		tete = tmp;
	}
	else cerr << "Liste vide";
	return *this;
}

//########## CPILE ###########//

CPile::CPile():CList(){}
CPile::~CPile(){ cout << "Appel du destructeur CPILE";} // Pas besoin de delete car appel automatique le destructeur de CList
CPile& CPile::operator<(int i){ 
	CNoeud *ptr = tete;
	tete = new CNoeud(i);
	tete->setNext(ptr);	
	return *this; 
}

//########## CFILE ###########//

CFile::CFile():CList(){}
CFile::~CFile(){cout << "Appel du destructeur CFILE"; }

CFile& CFile::operator<(int i){ 
	CNoeud *tmp = new CNoeud(i);
	if(tete == NULL)
		tete = tmp;
	else
	{
		CNoeud *ptr;
		ptr = tete;
	
		while(ptr->getNext() != NULL)
			ptr = ptr->getNext();
		
		ptr->setNext(tmp);
	}
	return *this; 
}
		
int main()
{
	CPile pile;
	CFile file;
	
	CList *ptlist = &file;
	*ptlist < 0 < 1; //ptlist est de type CList, la methode doit etre definie au niveau statique pour pouvoir compiler
	cout << *ptlist;
	int i;
	*ptlist > i;
	cout << *ptlist << "i=" << i << endl;
	
	 ptlist = &pile;
	 *ptlist < 0 < 1;
	cout << *ptlist;
	*ptlist > i;
	cout << *ptlist << "i=" << i << endl;
	//si l'exo demande pop, au lieu de getTop, definir la copie de liste pour gerer les delete correctement
	
	return 0;
}