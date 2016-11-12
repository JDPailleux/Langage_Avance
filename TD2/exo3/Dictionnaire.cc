using namespace std;
#include "Dictionnaire.h"

//####### NOEUD #######//

Noeud:: Noeud(Definition d) :def(d) {nextNoeud = NULL;}
Noeud:: ~Noeud() {
	if ( this->nextNoeud ) 
		delete this->nextNoeud;
	}
Definition Noeud :: getDef() const{
	return def;
}
void Noeud:: setDef(Definition d) {
	def = d;
}
Noeud* Noeud :: getNext() {
	return nextNoeud;
}
void Noeud :: setNext(Noeud* N){
	nextNoeud = N;
}

//####### DICTIONNAIRE #######//

Dictionnaire:: Dictionnaire() // Par défaut le dictionnaire comporte aucune définition
{
	dico = NULL;
	taille = 0;
}
Dictionnaire:: Dictionnaire(const Dictionnaire& d)
{
	if ( d.getDico() != NULL)				// On vérifie si le dictionnaire d existe.
	{
		Noeud* tete1 = d.getDico();
	
		dico = new Noeud(tete1->getDef());
		tete1 = tete1->getNext();;
		Noeud* ptr = dico;			// Pour garder le debut de ma liste.
	
		while (tete1 != NULL)
		{
			ptr->setNext(new Noeud(tete1->getDef()));
			tete1 = tete1->getNext();
			ptr = ptr->getNext();
		}
	}
	else 
	{
		dico = NULL;
	}
}
Dictionnaire:: ~Dictionnaire()
{
	if ( dico != NULL) 
	{
		delete dico;
		taille = 0;
		dico = NULL;
	}
	cout << "appel du destructeur de Dictionnaire" << endl;
}
Noeud* Dictionnaire:: getDico() const
{
	return dico;
}
void Dictionnaire:: ajoutDef(Definition d)
{
	if ( dico != NULL)
	{
		Noeud* tmp = dico;
		Noeud* ajout = new Noeud(d);
		while (tmp !=  NULL && tmp->getDef().getClef() <= d.getClef())
		{
			tmp = tmp->getNext();
		}
		ajout->setNext(tmp->getNext());
		tmp->setNext(ajout);
	}
	else
	{
		dico = new Noeud(d);
	}
	taille++;

}
bool Dictionnaire:: rechercheDef(const char* mot)
{
	CString c = mot; // Conversion par constructeur
	Noeud *tmp = dico;
	while(tmp != NULL && tmp->getDef().getClef() <= c) //Comparaison de CString
	{
		if(c == tmp->getDef().getClef())
			return true;
		tmp = tmp->getNext();
	}
	return false;
}
/* Version 2:

CString Dictionnaire:: rechercheDef(const char* mot)
{
	CString c = mot; // Conversion par constructeur
	Noeud *tmp = dico;
	while(tmp != NULL && tmp->getDef().getClef() <= c) //Comparaison de CString
	{
		if(c == tmp->getDef().getClef())
			return tmp->getDef().getClef();
		tmp = tmp->getNext();
	}
	return CString("N'existe pas");
}


*/
void Dictionnaire:: afficher(const char* mot)
{
	if ( !rechercheDef(mot)) cout << "le mot n'existe pas" << endl;
	else //la clef est dans le dico
	{
	Noeud *tmp = dico;
	CString c = mot;
	while(c > tmp->getDef().getClef())
	tmp = tmp->getNext();
	//a la sortie du while, tmp est le noeud contenant la clef
	cout << "la definition du mot " << tmp->getDef().getClef().getString()\
	<< " est " << tmp->getDef().getMot().getString() << endl;
	}
}	

int main()
{
	
	Dictionnaire* d1 = new Dictionnaire();
	Definition homer("Homer", "Buveur de biere");
	d1->ajoutDef(homer);
	cout << d1->rechercheDef("Allo") << endl; //affiche 0, le mot n'est pas trouve
	cout << d1->rechercheDef("Homer") << endl;
	d1->afficher("Homer"); //la definition est affichee
	delete d1;
	return 0;
	
}
