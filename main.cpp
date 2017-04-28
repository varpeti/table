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
	
	Table t;

	table_insert(t,string("alma"));
	table_insert(t,4328);
	table_insert(t,2347.23);
	table_insert(t,Skoord(10.2,324.5));
	table_insert(t,t); // Saját maga, de új elemeket nem tartalmaz,

	cout << "size: "<< t.size() << endl;
	cout << "0   " <<t[0]->get<string>() << endl;
	cout << "1   " <<t[1]->get<int>() << endl;
	cout << "2   " <<t[2]->get<double>() << endl;
	cout << "3   " <<t[3]->get<Skoord>().x << " " << t[3]->get<Skoord>().y << endl;
	cout << "4 0 " <<t[4]->get<Table>()[0]->get<string>() << endl;
	cout << "4 1 " <<t[4]->get<Table>()[1]->get<int>() << "\n\n";

	t[3]->set<Skoord>(Skoord(324.5,-10.2));	// alap	módosítás
	t[4]->get<Table>()[1]->set<int>(987);	// végigfejtés a második fokig és módosítás
	Table g = t[4]->get<Table>();
	g[0]->set<string>(string("korte"));	// kifejtés a második fokra és utána modosítás
	table_insert(g,	"ez a g 4-es");
	table_insert(t,	"ez a t 5-os");
	//table_insert(t[4]->get<Table>(),"ez a t 4 4-es"); Ez nem fog működni. Helyette újra berakom a "g"-t a "t"-be.
	t[4]->set<Table>(g);

	cout << "size: t:"<< t.size() << " g:" << g.size() << " t[4]:" << t[4]->get<Table>().size() << endl; // egyel kevesebb a "g" mert saját maga már nem adódott magához, és a "t"-hez és a "g"-hez is 1-1 új elemet adtunk.
	cout << "t 0   " <<t[0]->get<string>() << endl;
	cout << "t 1   " <<t[1]->get<int>() << endl;
	cout << "t 2   " <<t[2]->get<double>() << endl;
	cout << "t 3   " <<t[3]->get<Skoord>().x << " " << t[3]->get<Skoord>().y << endl;
	cout << "t 4 0 " <<t[4]->get<Table>()[0]->get<string>() << endl;
	cout << "t 4 1 " <<t[4]->get<Table>()[1]->get<int>() << endl;
	cout << "g 4   " <<g[4]->get<char*>() << endl;
	cout << "t 4 4 " <<t[4]->get<Table>()[4]->get<char*>() << endl;
	cout << "t 5   " <<t[5]->get<char*>() << "\n\n";


	table_remove<char*>(g,4); // Ezzel megszűnik a g[4] teljesen és a t[4][4] értéke. (Mivel a g[4] ugyan oda muatatott.) // ez liküszöbölhető még több pointerrel :D

	cout << "size: t:"<< t.size() << " g:" << g.size() << " t[4]:" << t[4]->get<Table>().size() << endl; // a t[4][4]-nek van egy már nem létező ojektumra mutató pointere.
	cout << "t 5   " <<t[5]->get<char*>() << "\n\n"; // a t[5] maradt.

	return 0;
}
