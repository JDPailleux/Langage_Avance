using namespace std

//####### CLASSE FORME #######//

void Forme:: deplacer(int x, int y)

//####### CLASSE CERCLE #######//

Cercle:: Cercle()
{
	rayon =0;
}
Cercle:: Cercle(Point c, int r)
{

}
Cercle:: Cercle(const Cercle& c)
{

}
Cercle:: ~Cercle()

Point Cercle:: getCentre() const
int Cercle:: getRayon() const
void Cercle:: deplacer(int x, int y)
void Cercle:: afficher()

//####### CLASSE FORME #######//

Segment:: Segment(){}
Segment:: Segment(Point pp1, Point pp2): p1(pp1), p2(pp2) {}

Segment:: Segment( const Segment& s)
{
	p1 = s.getP1();
	p2 = s.getP2();
}
	
Segment:: ~Segment() {	cout << "Le destruction p1.x : \n"<< p1.getX()<< " p1.y:" << p1.getY()<< " p2.x:" << p2.getX()<< " p2.y:" << p2.getY() << endl;}	
	
double Segment:: longueur(const Segment s)
	{
		return sqrt( (this->p1.getX()-this->p2.getX())*(this->p1.getX()-this->p2.getX()) 
		+ (this->p1.getY()-this->p2.getY())*(this->p1.getY()-this->p2.getY()) );
	}

Point Segment:: getP1() const
{
	return p1;
}

Point Segment:: getP2() const
{
	return p2;
}