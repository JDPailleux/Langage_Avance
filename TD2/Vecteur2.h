 
 #include <string.h>
 #include <iostream>
 
 class Noeud
 {
	 private:
		int valeur;
		Noeud* nextNoeud;
	public:
		Noeud(int val);
		~Noeud();
		int getValeur() const ;
		void setValeur(int v);
		Noeud* getNext();
		void setNext(Noeud* newN);
 };
 
 class Vecteur
 {
	 private:
		Noeud* tete;
		int taille;
		
	public:
		//### Constructeur et destructeur ###//
		Vecteur();
		Vecteur(const Vecteur& v);
		Vecteur(int nbrElement);
		~Vecteur();
		
		//### Accesseurs ###//
		int getTaille() const;
		Noeud* getTete() const;
	 
		//### Operateurs ###//
		Vecteur& operator+=(const int a);
		Vecteur& operator=(const Vecteur& v);
		friend ostream& operator<<(ostream& flux, Vecteur& v);
		friend ostream&  operator>>(ostream& flux, const Vecteur& v);
		int operator[](const int i);

		// Il n'y a plus de surcharge de l'operateur [] car on ne manipule plus de tableau
		
 };
