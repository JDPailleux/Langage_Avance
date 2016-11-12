using namespace std;
#include <iostream>

// Il faut ecrire les 4 premieres lignes sinon ne marche pas 
template<class T>
class Pair;
template<class T>
ostream& operator<<(ostream& o, const Pair<T>& p);

template<class T>
class Pair{
	private:
		T x, y;
	public:
		Pair(T xx, T yy){x = xx; y = yy;}
		T getMax() const {
		if(strcmp(typeid))
			if ( x > y) return x; 
			else return y;
		}
		friend ostream& operator<< <>(ostream& o, const Pair<T>& p); // Il faut rajouter <> apres << pour indiquer que c'est une méthode générique
};

//Il faut aussi spécifier à ostream qu'il va utiliser un template
template<class T>
ostream& operator<<(ostream& o, const Pair<T>& p){
	o << "(" << p.x <<","<< p.y <<")"<< endl;
	return o;
}

int main(){

	int i = 5, j = 6;
	float l = 10.0, m = 5.0;
	Pair<int> myInts (i,j);	//créer une paire d’entiers
	Pair<float> myFloats (l,m); //créer une paire de flottants
		
	cout << myInts.getMax()<< endl; //affiche le plus grand des 2 entiers
	cout << myFloats.getMax()<<endl; //affiche le plus grand des 2 flottants

	char c1='c', c2='d';
	Pair<char> myChars(c1,c2); //creer un objet qui contient une paire d’entiers
	cout << myChars.getMax()<< endl;
	return 0 ;
}