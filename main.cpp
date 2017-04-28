#include <iostream>
#include "table.tcc"

using namespace std;

struct Skoord
{	
	double x,y;

	Skoord(double x, double y) : x(x), y(y) {};
	Skoord(){x=0;y=0;};
	
};


int main()
{
	Stable t;

	string s = "alma";
	t.add(s); 
	s="korte";
	cout << t.get(s,0) << endl;

	int i = 100;
	t.add(i);
	cout << t.get(i,1) << endl;
	Skoord k(63.45,34567e-4);
	t.add(k);
	Skoord g; 
	t.get(g,2); cout << g.x << " " << g.y << endl;
	s="szilva";
	t.set<int>(s,1); s="";
	cout << t.get(s,1) << endl;
	t.del<string>(0);
	cout << t.get(s,0) << endl;

	Stable szam;
	for (int i = 0; i < 100; ++i)
	{
		szam.set<int>(rand()%(i+1),i);
	}
	t.add(t); // id=2 | Saját maga
	t.add(szam); // id=3 | A száz "véletlen" szám.

	return 0;
}
