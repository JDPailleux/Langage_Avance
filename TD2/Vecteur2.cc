using namespace std;

#include "Vecteur2.h"

//#####################################  NOEUD  ################################//

Noeud :: Noeud(int v) {valeur = v; nextNoeud = NULL;}
Noeud :: ~Noeud() {
	if ( this->nextNoeud ) 
		delete this->nextNoeud;
	}
int Noeud :: getValeur() const{
	return valeur;
}
void Noeud:: setValeur(int v) {
	valeur = v;
}
Noeud* Noeud :: getNext() {
	return nextNoeud;
}
void Noeud :: setNext(Noeud* newN){
	nextNoeud = newN;
}


//##################################### VECTEUR ################################//

Vecteur:: Vecteur() {
	this->taille = 1;
	this->tete = new Noeud(0);
}

Vecteur:: Vecteur(int nbrElement) {
	
	this->taille = nbrElement;
		
	tete = new Noeud(taille);
	Noeud* ptr = tete;			// Pour garder le debut de ma liste.
	int i = taille-1;
	while (i > 0)
	{
		ptr->setNext(new Noeud(i));
		ptr = ptr->getNext();
		i--;
	}
	
}

Vecteur:: Vecteur(const Vecteur& liste) {
	
	if ( liste.getTete() != NULL)				// On vérifie si la liste existe.
	{
		this->taille = liste.getTaille();
		Noeud* tete1 = liste.getTete();
	
		tete = new Noeud(tete1->getValeur());
		tete1 = tete1->getNext();;
		Noeud* ptr = tete;			// Pour garder le debut de ma liste.
	
		while (tete1 != NULL)
		{
			ptr->setNext(new Noeud(tete1->getValeur()));
			tete1 = tete1->getNext();
			ptr = ptr->getNext();
		}
	}
	else 
	{
		taille = 0;
		tete = NULL;
	}
}

Vecteur:: ~Vecteur(){
	delete tete;
	taille =0;
	tete = NULL;
	cout << "Destruction du vecteur" << endl;
}


//### Accesseurs ###//
int Vecteur:: getTaille() const{
	return taille;
}

Noeud* Vecteur:: getTete() const{
	return tete;
}


//### Surcharges opérateurs ###// (=, [] (verifie qu'on est dans les bornes), +=, << (ostream), >> (istream))
Vecteur& Vecteur:: operator= (const Vecteur& v) 
{
	if ( tete != NULL) delete tete;
	if ( v.getTete() != NULL)
	{
		taille = v.getTaille();
		delete tete;
		Noeud* tmp2	= v.getTete();	// Pointeur qui va nous permettre de nous déplacer dans v
		tete = new Noeud(tmp2->getValeur());
		Noeud* tmp = tete;			// Pointeur qui va nous permettre de modifier le vecteur lui meme
		tmp2 = tmp2->getNext();		

		while (tmp2 != NULL)
		{
			tmp->setNext(new Noeud(tmp2->getValeur()));
			tmp = tmp->getNext();
			tmp2 = tmp2->getNext();
		}
	}
	else
	{
		taille = 0;
		tete = NULL;
	}
	return *this;
}
Vecteur& Vecteur:: operator+=( const int a) 
{
	taille++;
	Noeud* tmp = this->getTete();
	Noeud* val = new Noeud(a);
	if (tmp != NULL)
	{
		while (tmp->getNext() != NULL)
		{
			tmp = tmp->getNext();
		}
		tmp->setNext(val);
	}
	else
	{
		tete = val;
	}

	return *this;
}

ostream& operator<<(ostream& flux, Vecteur& v)
{
	flux << "( ";
	Noeud* tmp = v.getTete();
	while (tmp != NULL)
	{
		flux << tmp->getValeur() << " ";  
		tmp = tmp->getNext();
	}
	flux << ")"<< endl;
	return flux;
}
istream& operator>>(istream& flux, Vecteur& v) // Modifie mais ne créé pas
{
	int i, vtmp;
	Noeud* tmp = v.getTete();

	for ( i = 0; i < v.getTaille(); i++) // On démarre de 1 car il y a forcément une valeur en entrée.
	{
		flux >> vtmp;
		tmp->setValeur(vtmp); 
		tmp = tmp->getNext();
	}
	return flux;
}

int Vecteur:: operator[](const int i)
{
	if ( i > taille || i < 0) cerr << "erreur il n'y a pas d'élement à cet indice";
	Noeud* tmp = tete;
	int j;
	for (j = 0; j < i; j++)
	{
		tmp = tmp->getNext();
	}
	return tmp->getValeur();
}



int main()
{
	
	Vecteur v(4), v2(10);
	cout << "v : " << v << endl;
	v +=99;
	cout << "v2 : " << v2 << endl;
	v = v2;
	cout << "v : " << v << endl;

	return 0;
}
