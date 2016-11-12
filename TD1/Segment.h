#include <string.h>
#include "Point.h"

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
		Point getP1();
		Point getP2();
		bool estVertical();
		bool estHorizontal();
		bool estSurDiagonale();
};

