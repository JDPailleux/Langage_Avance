 
 #include <string.h>
 #include <iostream>
 
 class Vecteur
 {
	private:
		int* Vect;
		int taille;
		
	public:
		//### Constructeurs et destructeur ###//
		Vecteur();						// Constructeur par défaut
		Vecteur(const Vecteur& v);		// Constructeur par recopie
		Vecteur(int taille, int* tab);
		~Vecteur();
		
		//### Accesseurs ###//
		int getTaille() const;
		int* getVect() const;
	 
		//### Operateurs ###//
		Vecteur operator+=(const int a);
		Vecteur operator=(const Vecteur& v);
		int operator[](const int n);
		friend ostream& operator<<(ostream& flux, Vecteur& v);			// Fonctions amies car on ne modifie pas l'objet de la classe
		friend ostream&  operator>>(ostream& flux, const Vecteur& v);
		
 };
