#include <iostream>
#include <string.h>
#include "Point.h"

class Forme // c'est une classe abstraite => methode virtuel pure
{
	// attributs?
	public:
		virtual ~Forme()
		{
			cout << "destruction d'une forme"
		};
		virtual void deplacer(int x, int y) =0; 
		virtual void afficher()= 0;
};

class Cercle : public Forme
{
	private: 
		Point centre;
		int rayon;
	public:
		Cercle();
		Cercle(Point c, int r);
		Cercle(const Cercle& c);
		~Cercle();

		Point getCentre() const;
		int getRayon() const;
		void deplacer(int x, int y);
		void afficher();
};

class Rectangle : public Forme
{
	private:
		Point centre;
		int longueur, largeur;
	public:
		Rectangle();
		Rectangle(Point HD, Point BG);
		Rectangle(const Rectangle& R);
		~Rectangle();

		Point getCentre() const;
		void deplacer(int x, int y);
		void afficher();

};

class Triangle : public Forme
{
	private:
		Point haut, bas_d, bas_g;
	public:
		Triangle();
		Triangle(Point P1, Point P2, Point P3);
		Triangle(const Triangle& T);
		~Triangle();

		Point getHaut()const;
		Point getBD()const;
		Point getBG()const;
		void deplacer(int x, int y);
		void afficher();
};

class Segment
{
	private:
		Point p1, p2;
		
	public:
		Segment();
		Segment(Point p1, Point p2);
		Segment(const Segment& s);
		~Segment();
		double longueur(const Segment s);
		Point getP1()const;
		Point getP2()const;
};