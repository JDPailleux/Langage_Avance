using namespace std;

#include "Vecteur.h"

Vecteur:: Vecteur()
{
	this->taille = 1;
	this->Vect = new int[1];
	this->Vect[0] = 0;
}

Vecteur:: Vecteur(int taille, int* tab)
{
	this->taille = taille;
	this->Vect = new int[taille];
	int i;
	for ( i = 0; i < taille; i++)
	{
		this->Vect[i] = tab[i];
	}
}

Vecteur:: Vecteur(const Vecteur& v)
{
	this->taille = v.getTaille();
	int i;
	for ( i = 0; i < taille; i++)
	{
		this->Vect[i] = v.Vect[i];
	}
}

Vecteur:: ~Vecteur()
{
	delete []Vect;
	cout << "Destruction du vecteur" << endl;
	Vect = NULL;
}

//### Accesseurs ###//
int Vecteur:: getTaille() const
{
	return taille;
}

int* Vecteur:: getVect() const
{
	return Vect;
}

//### Surcharges opérateurs ###// (=, [] (verifie qu'on est dans les bornes), +=, << (ostream), >> (istream))

Vecteur Vecteur:: operator= (const Vecteur& v) 
{	
    if (Vect)
        delete[] Vect;

    taille = v.getTaille();
    Vect = new int[taille];
   
    for (int i = 0; i < taille; i++)
        Vect[i] = v.getVect()[i];
    return *this;
	
}

Vecteur Vecteur:: operator+=( const int a) 
{
	taille++;
	int* tmp = new int[taille];
	for ( int i = 0; i < taille -1; i++)
	{
		tmp[i] =  Vect[i];
	}
	tmp[taille-1] = a;
	delete []Vect;
	Vect = new int[taille];
	for ( i = 0; i < taille -1; i++)
	{
		Vect[i] =  tmp[i];
	}
	return *this;
}

int Vecteur:: operator[](const int i)
{
	if( i >= getTaille() || i < 0)
		cerr << "Errueur indice hors bornes \n";
	return Vect[i];
}

ostream& operator<<(ostream& flux, Vecteur& v)
{
	int i;
	flux << "( ";
	for ( i = 0; i < v.getTaille(); i++)
	{
		flux << v.getVect()[i] << " ";  
	}
	flux << ")"<< endl;
	return flux;
}

istream& operator>>(istream& flux, Vecteur& v)
{
	int i;
	for ( i = 0; i < v.getTaille(); i++)
	{
		flux >> v.getVect()[i];  
	}
	return flux;
}


int main()
{
	int tab[] = {1,2,4,5};
	int tab2[] = {3,4,7,8};
	Vecteur v1(4, tab), v2(4, tab2);
	//v1 += 99;
	v1 = v2;
	cout << v1;
	cout << v2;
	/*Vecteur v3(4,tab2);
	cin >> v3;
	cout << v3;*/
	
	return 0;
}
