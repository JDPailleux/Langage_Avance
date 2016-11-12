using namespace std;

#include <iostream>
#include <math.h>
#include "Segment.h"

Segment:: Segment(){}
Segment:: Segment(Point pp1, Point pp2): p1(pp1), p2(pp2) {}

Segment:: Segment( const Segment& s)
{
	p1 = s.getP1();
	p2 = s.getP2();
}
	
Segment:: ~Segment()
	{
		cout << "Le destruction p1.x : \n"<< p1.getX()<< " p1.y:" << p1.getY()<< " p2.x:" << p2.getX()<< " p2.y:" << p2.getY() << endl;
	}	
	
double Segment:: longueur(const Segment s)
	{
		return sqrt( (this->p1.getX()-this->p2.getX())*(this->p1.getX()-this->p2.getX()) 
		+ (this->p1.getY()-this->p2.getY())*(this->p1.getY()-this->p2.getY()) );
	}

Point Segment:: getP1()
{
	return p1;
}

Point Segment:: getP2()
{
	return p2;
}
	
bool Segment:: estVertical()
	{
		if (this->p1.getX() == this->p2.getX()) return true;
		else return false;
	}
bool Segment:: estHorizontal()
	{
		if (this->p1.getY() == this->p2.getY()) return true;
		else return false;
	}
bool Segment:: estSurDiagonale()
	{
		if ( !estVertical() && !estHorizontal()) return true;
		else return false;
	}

int main()
{
	Point p1(4,5),p2(8,5);
	Segment s(p1,p2);
	
	cout << s.longueur(s) << "\n";
	cout << s.estVertical() << "\n";
	cout << s.estHorizontal() << "\n";
	cout << s.estSurDiagonale() << "\n";
	
	return 0;
}
