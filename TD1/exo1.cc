using namespace std;
#include <iostream>
#include <string.h>

int main()
{
	int i;
	// a)
	
	int tab[10] = {2,3,4,5,1,7,6,11,8,9};
	int *p = tab;
	
	for ( i = 0; i < 10; i++)
	{
		cout << *(p+i) << endl	;
	}
	
	// b)
	const char* charTab1[3] = {"truc","machin","chose"}; // Manière statique, Le Warning c'est pour indiquer que se sont des constantes
	char* charTab2[3];
	
	for ( i = 0; i < 3; i ++)
	{
		charTab2[i] = new char[strlen(charTab1[i])];
		strcpy(charTab2[i],charTab1[i]);		
		cout << *(charTab2+i)<< "\n";
	}
	for ( i = 0; i < 3; i ++)
	{
		delete charTab2[i];
	}
	/*
	 Ou delete []charTab2;
	 */
	
	
	return 0;
}

