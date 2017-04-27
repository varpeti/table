#include <iostream>
#include "table.hpp"

using namespace std;

struct Skoord
{	
	double x,y;

	Skoord(double x, double y) : x(x), y(y) {};
	Skoord(){x=0;y=0;};
	
};


int main()
{
	srand(time(0));
	
	TABLE t;

	string s = "alma";
	table_add(t,&s);
	s = "korte";
	table_add(t,&s);
	int i = 10;
	table_add(t,&i);
	Skoord k(9e-7,30.1);
	table_add(t,&k);
	table_add(t,&t); // Saját maga a negyedik eleme.


	s="";i=0;k=Skoord(0,0);

	cout << table_get(t,s,0) << endl;
	cout << table_get(t,s,1) << endl;
	cout << table_get(t,i,2) << endl;
	Skoord g; g = table_get(t,g,3);
	cout << g.x << " " << g.y << endl;

	TABLE z; z = table_get(t,z,4);
	cout << table_get(z,s,0) << endl; //Negyedik elemének az első eleme.



	return 0;
}
