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
	int set(void *, int);
	void* get(int);
	void del(int);
	int size();

	void *& operator[](int id);
};

TABLE::~TABLE()
{
	while (ertekek.size()>0)
	{
		//delete ertekek[ertekek.size()-1]; // Nem jó, mert nem tud destruktorokat hívni.
		ertekek.pop_back();
	}
}

int TABLE::add(void *ertek)
{
	ertekek.push_back(ertek);
	return ertekek.size()-1;
}

int TABLE::set(void* ertek,int id)
{
	ertekek[id]=ertek;
	return id;
}

void* TABLE::get(int id=0)
{
	return ertekek[id];
}

void TABLE::del(int id)
{
	ertekek.erase(ertekek.begin()+id);
}

int TABLE::size()
{
	return ertekek.size();
}

void*& TABLE::operator[](int id)
{
	return ertekek[id];
}


template <typename T>
int table_add(TABLE &table, T *be)  { 
	T *pbe = new T;
	*pbe = *be;
	return table.add(pbe);
} 

template <typename T, typename Tr>
int table_set(TABLE &table, T *be, int id, Tr *regi)
{
	if (id>table.size()-1) {return table_add(table,be);} // Ha nagyobb az id mint amennyi elem van: csak hozzáadjuk a végéhez.
	delete static_cast<Tr*>(table.get(id));
	T *pbe = new T;
	*pbe = *be;
	return table.set(pbe,id);
}

template <typename T>
T table_get(TABLE table, T *be, int id=0)  { 
	if (id>table.size()-1) return *be;
	*be = *static_cast<T*>(table.get(id));
	return *be;
} 

template <typename Tr>
void table_del(TABLE &table, int id, Tr *regi) // Törli a típusnak megfelelően.
{
	if (id>table.size()-1) return;
	delete static_cast<Tr*>(table.get(id));
	table.del(id);
}


#endif