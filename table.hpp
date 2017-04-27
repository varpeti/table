#ifndef _TABLE_
#define _TABLE_

#include <vector>

using namespace std;

class TABLE
{
	vector<void *> ertekek;

public:

	TABLE(){};
	~TABLE();

	int add(void *);
	void set(void *, int);
	void* get(int);
	int del(int);
	int size();
};

TABLE::~TABLE()
{
	while (ertekek.size()>0)
	{
		//delete ertekek[ertekek.size()-1]; // Hmm nem jó?
		ertekek.pop_back();
	}
}

int TABLE::add(void *ertek)
{
	ertekek.push_back(ertek);
	return ertekek.size()-1;
}

void* TABLE::get(int id=0)
{
	return ertekek[id];
}

int TABLE::del(int id)
{
	//delete ertekek[id];
	ertekek.erase(ertekek.begin()+id);
}

int TABLE::size()
{
	return ertekek.size();
}


template <typename T>
int table_add(TABLE &table, T *be)  { 
	T *pbe = new T;
	*pbe = *be;
	return table.add(pbe);
} 

template <typename T>
T table_get(TABLE table, T &be, int id=0)  { 
	be = *static_cast<T*>(table.get(id));
	return be;
} 


#endif