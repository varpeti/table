#include <iostream>
#include "table.tcc"

using namespace std;

struct Skoord
{	
	double x,y;

	Skoord(double x, double y) : x(x), y(y) {};
	Skoord(){x=0;y=0;};

	~Skoord()
	{
		cout << "RIP Skoord" << endl;
	}
	
};


int main()
{
	
	Table t;

	table_insert(t,string("alma"));
	table_insert(t,4328);
	table_insert(t,2347.23);
	table_insert(t,Skoord(10.2,324.5));
	table_insert(t,&t); // Fontos hogy a rámutató pointert rakjuk bele, és ne magát. Különben az elemeik (mutatók) megegyezenek de maguk nem.

	cout << "0     " <<t[0]->get<string>() << endl;
	cout << "1     " <<t[1]->get<int>() << endl;
	cout << "2     " <<t[2]->get<double>() << endl;
	cout << "3     " <<t[3]->get<Skoord>().x << "x " << t[3]->get<Skoord>().y << "y " << endl; // 2x RIP Skoord
	cout << "4 0   " <<t[4]->get<Table*>()->at(0)->get<string>() << endl;
	cout << "4 1   " <<t[4]->get<Table*>()->at(1)->get<int>() << endl;
	cout << "4 4 0 " <<t[4]->get<Table*>()->at(4)->get<Table*>()->at(0)->get<string>() << endl;
	cout << "size: t:"<< t.size() << " t[4]:" << t[4]->get<Table*>()->size() << "\n\n";

	t[0]->set<string,string>("korte"); 		cout << "\"alma\" - t[0]=\"korte\"" << endl;
	Table *g = t[4]->get<Table*>();
	g->at(1)->set<int,string>("szilva"); 	cout << " 4328  - t[4][1]=\"szilva\"" << endl;
	table_insert(t,'@'); 					cout << " new   : t[5]='@'" << endl;
	cout << "size: t:"<< t.size() << " t[4]:" << t[4]->get<Table*>()->size() << endl;
	table_remove<Skoord>(t,3);
	cout << "size: t:"<< t.size() << " t[3]:" << t[3]->get<Table*>()->size() << "\n\n";

	cout << "0     " <<t[0]->get<string>() << endl;
	cout << "1     " <<t[1]->get<string>() << endl;
	cout << "2     " <<t[2]->get<double>() << endl;
	cout << "3 0   " <<t[3]->get<Table*>()->at(0)->get<string>() << endl;
	cout << "3 1   " <<t[3]->get<Table*>()->at(1)->get<string>() << endl;
	cout << "3 3 0 " <<t[3]->get<Table*>()->at(3)->get<Table*>()->at(0)->get<string>() << endl;
	cout << "3 3 4 " <<t[3]->get<Table*>()->at(3)->get<Table*>()->at(4)->get<char>() << endl;
	cout << "3 4   " <<t[3]->get<Table*>()->at(4)->get<char>() << endl;
	cout << "4     " <<t[4]->get<char>() << endl;
	cout << "size: t:"<< t.size() << " t[3]:" << t[3]->get<Table*>()->size() << "\n\n";

	return 0;
}
