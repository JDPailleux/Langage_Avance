using namespace std;
#include "Point.h"

//### POINT ###//

Point :: Point()
{
	x = 0;
	y = 0;
}

Point :: Point(int xx, int yy): x(xx), y(yy) {}

Point :: Point(const Point& p)
{
	x = p.getX();
	y = p.getY();
}

Point :: ~Point() {	cout << "appel du destructeur Point" << endl;}

int Point :: getX() const {	return x;}

int Point :: getY() const {	return y;}

void Point:: afficher() {	cout << "x : " << x << ", y : " << y << endl;}

void Point:: cloner(const Point p)
{
	x = p.getX();
	y = p.getY();
}

//### POINTCOLOR ###//

PointColor:: PointColor()
{
	color = new char[100]; // Une couleur ne fait pas plus de 100 caractère
	strcpy(color,"BLANC"); // Par défaut la couleur est blanche.
}
PointColor:: PointColor(int xx, int yy, const char* coul): Point(xx,yy)
{
	color = new char[100];
	strcpy(color,coul);
}
PointColor:: PointColor(const PointColor& p)
{
	this->Point:: cloner(p);
	color = p.getColor();
}
PointColor:: ~PointColor(){	if ( color != NULL) {delete[] color; color = NULL;}cout << "appel du destructeur PointColor" << endl;}

char* PointColor:: getColor() const {	return color;}

void PointColor :: afficher(){	Point:: afficher();cout << ", couleur = " << color << endl;}

void PointColor :: cloner(const PointColor& p)
{
	this->Point:: cloner(p);
	color = p.getColor();
}

int main(int argc, char const *argv[])
{
	Point p(2,3);
	p.afficher();
	Point p2;
	p2.cloner(p);
	p2.afficher();

	PointColor p3(4,8,"NOIR"), p4(p3);
	p3.afficher();
	p4.afficher();

	return 0;
}