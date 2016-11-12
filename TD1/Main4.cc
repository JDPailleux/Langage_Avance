using namespace std;

#include <iostream>
#include "Point.h"

int main()
{
	Point p1, p2(4,7);
	cout<< p1.getX() << endl;
	p1.afficher();
	p2.afficher();
	
	return 0;
}
