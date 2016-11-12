using namespace std;
#include <iostream>
#include <string.h>

void tableauEcriture(int tab[], int taille)
{
	int i;
	for (i = 0; i < taille; i++)
	{
		tab[i] = i;
	}
	
}

void tableauLecture(const int tab[], int taille)
{
	int i;
	for (i = 0; i < taille; i++)
	{
		cout << tab[i] << "\n";
	}
}

int main()
{
	int tab[]= {1,2,3,4,6,7,0,99,23};
	tableauLecture(tab,9);
	tableauEcriture(tab,9);
	tableauLecture(tab,9);
}
