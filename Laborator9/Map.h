#pragma once
template <class K, class V>
struct triplet
{
	K key;
	V value;
	int i;
};

template <class K, class V>
class Iterator
{
public:
	triplet<K, V> * p;

	Iterator& operator++() { 
		p++;
		return *this;
	}
	bool operator != (Iterator& m)
	{
		return p != m.p;
	}
	triplet<K, V> operator* () { return *p; }
};


template <class K, class V>
class Map
{
public:
	int size = 0;
	static const int Nmax = 100;
	triplet<K, V> elem[Nmax];

	V& operator[](const K& x)
	{
		int poz;
		for (poz = 0; poz < size; poz++)
			if (elem[poz].key == x)
				return elem[poz].value;

		if (size == Nmax)
		{
			printf("Memorie depasita");
			exit(0);
		}
		elem[size].key = x;
		elem[size].i = size;
		size++;
		return elem[size-1].value;
	}
	
	bool Set(const K& key, const V& value)
	{
		for(int i=0;i<size;i++)
			if (elem[i].key == key)
			{
				elem[i].value = value;
				return 1;
			}
		return 0;
	}

	bool Get(const K& key, V& value)
	{
		for (int i = 0; i < size; i++)
			if (elem[i].key == key)
			{
				value = elem[i].value;
				return 1;
			}
		return 0;
	}

	int Count()
	{
		return size;
	}

	void Clear()
	{
		size = 0;
	}

	bool Delete(const K& key)
	{
		int poz = -1;
		for (int i = 0; i < size; i++)
			if (elem[i].key == key)
				poz = i; 
		if (poz == -1)
			return 0;

		size--;
		for (int i = poz; i < size; i--)
		{
			elem[i] = elem[i + 1];
			elem[i].i = i;
		}
	}

	bool Includes(const Map<K, V>& map)
	{
		for (auto [key, value, index] : map)
		{
			bool ok = 0; 
			for (int i = 0; i < size; i++)
				if (elem[i].key == key && elem[i].value == value)
					ok = 1;
			if (!ok)
				return 0;
		}
		return 1;
	}

	Iterator<K, V> begin(){
		Iterator<K, V> tmp;
		tmp.p = &elem[0];
		return tmp;
	}

	Iterator<K, V> end() {
		Iterator<K, V> tmp;
		tmp.p = &elem[size];
		return tmp; 
	}

};

