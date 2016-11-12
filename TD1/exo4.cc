#include <string.h>

class Point
{
	private:
		int x,y;
	public:
		Point();
		Point(int c_x, int c_y);
		Point(const Point& p);
		~Point();
		
		int getX() const;
		int getY() const;
		void afficher();
		void cloner(const Point& p);
};
