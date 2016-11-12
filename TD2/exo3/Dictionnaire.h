#include "Definition.h"

 class Noeud
 {
	private:
		Definition def;
		Noeud* nextNoeud;
	public:
		Noeud(Definition d);
		~Noeud();
		Definition getDef() const ;
		void setDef(Definition d);
		Noeud* getNext();
		void setNext(Noeud* N);
 };

class Dictionnaire
{
	private:
		Noeud* dico;
		int taille;
	public:
		Dictionnaire();
		Dictionnaire(const Dictionnaire& d);
		~Dictionnaire(); // Destructeurs

		Noeud* getDico() const;
		void ajoutDef(Definition d);
		bool rechercheDef(const char* mot); // On recherche la definition de mot
		void afficher(const char* mot);	// On affiche la définition du mot	
};