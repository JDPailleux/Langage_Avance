using namespace std;

#include <iostream>
#include "Point.h"

Point::	Point(){
			x = 0;
			y = 0;
		}
Point::	Point(int c_x, int c_y){
			x = c_x;
			y = c_y;
		}
Point::	Point( const Point& p){
			x = p.getX();
			y = p.getY();			
		}
Point::	~Point(){	
			cout << " appel au destructeur\n" ;
		}
int Point:: getX() const{
			return x;
		}
int Point:: getY() const{
			return y;
		}
void Point:: afficher(){
			cout << "x : " << x << "\n";
			cout << "y : " << y << "\n";
		}	
void Point:: cloner(const Point& p){
			x = p.getX();
			y = p.getY();
		}	

