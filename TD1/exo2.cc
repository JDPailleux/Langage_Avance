using namespace std;
#include <iostream>
#include <string.h>

void echange(int& arg1, int& arg2)
{
	int a;
	a = arg1;
	arg1 = arg2;
	arg2 = a;
}

int main()
{
	int x, y;
	x = 3;
	y = 8;
	echange(x,y);
	cout<<x<<"\n"<<y<<"\n";
}
