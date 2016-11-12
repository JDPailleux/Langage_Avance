#include <iostream>
#include <string.h>

enum COLOR {BLANC, NOIR, VERT, JAUNE, ROUGE, BLEU, CYAN};

class Point
{
	protected:
		int x, y;
	public:
		Point();
		Point(int xx, int yy);
		Point(const Point& p);
		~Point();

		int getX() const;
		int getY() const;
		virtual void afficher();
		virtual void cloner(const Point p);
};

class PointColor : public Point
{
	private:
		char* color; // chaine de caractère qui indique la couleur;
	public:
		PointColor();
		PointColor(int xx, int yy, const char* color);
		PointColor(const PointColor& p);
		~PointColor();

		char* getColor() const;
		void afficher();
		void cloner(const PointColor& p);
};
