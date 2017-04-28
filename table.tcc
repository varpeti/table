#ifndef _TABLE_
#define _TABLE_

#include <vector>
#include <iostream>

using namespace std;

class Telem
{
	void * ertek;

public:

	template <typename T>
	Telem(T be)
	{
		T *pbe = new T;
		*pbe = be;
		ertek = pbe;
	};

	~Telem(){
		delete ertek; // Nem tudja mghívni a típús szerinti destruktort, így memória szemét keletkezhet.
	};

	template <typename Tr, typename T>
	void set(T be)
	{
		delete static_cast<Tr*>(ertek);
		T *pbe = new T;
		*pbe = be;
		ertek = pbe;
	}

	template <typename T>
	T get(T &be)  { 
		be = *static_cast<T*>(ertek);
		return be;
	}

	template <typename T>
	T get()  { 
		return *static_cast<T*>(ertek);
	}

	template <typename Tr>
	void del()  { // Megszüntetéshez mindi ezt kell használni! Ez meghívja a típus destrukorát.
		delete static_cast<Tr*>(ertek);
	}


};

typedef vector<Telem*> Table;

template <typename T>
void table_insert(Table &t,T be)
{
	t.push_back(new Telem(be));
}

template <typename T>
void table_remove(Table &t,int id)
{
	if (id>t.size()-1) return;
	t[id]->del<T*>();
	t.erase(t.begin()+id);
}


#endif