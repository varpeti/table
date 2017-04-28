// Használat:
//	t.add(ertek);				Hozzáad a tábla végéhez egy bármilyen típúsú "ertek" elemet. Visszatér: az (int) "id"-vel.
//	t.set<tipus>(ertek,id);		A tábla (int) "id"-edik "tipus"-ú elemét törli majd "ertek"-re változtatja, vagy hozzáadja a lista végéhez. Visszatér: az (int) "id"-vel.
//	t.get<tipus>(id);			A tábla (int) "id"-edik "tipus"-ú elemével visszatér.
//	t.get(ertek,id);			A tábla (int) "id"-edik "ertek" típósának megfelelő elemével visszatér, és "ertek" valtozóba is visszaadja.
//	t.del<tipus>(id);			A tábla (int) "id"-edik elemét törli "tipus" szerint és minden utána lévő elem id-jét egyel csökkenti. 


#ifndef _TABLE_
#define _TABLE_

#include <vector>

using namespace std;

class Stable
{
	vector<void *> ertekek;

public:

	Stable(){};
	~Stable(){};

	template <typename T>
	int add(T be)  { 
		T *pbe = new T;
		*pbe = be;
		ertekek.push_back(pbe);
		return ertekek.size()-1;
	} 

	template <typename Tr, typename T>
	int set(T be, int id)
	{
		T *pbe = new T;
		*pbe = be;
		if (id>ertekek.size()-1 or id==0) {
			ertekek.push_back(pbe);
		} else {
			delete static_cast<Tr*>(ertekek[id]);
			ertekek[id]=pbe;
		}
		return id;
	}

	template <typename T>
	T get(T &be, int id=0)  { 
		if (id>ertekek.size()-1) return be;
		be = *static_cast<T*>(ertekek[id]);
		return be;
	} 

	template <typename T>
	T get(int id=0)  { 
		T ki;
		if (id>ertekek.size()-1) return ki;
		return *static_cast<T*>(ertekek[id]);
	} 

	template <typename T>
	void del(int id) // Törli a típusnak megfelelően.
	{
		if (id>ertekek.size()-1) return;
		delete static_cast<T*>(ertekek[id]);
		ertekek.erase(ertekek.begin()+id);
	}

	int size()
	{
		return ertekek.size();
	}

};


#endif