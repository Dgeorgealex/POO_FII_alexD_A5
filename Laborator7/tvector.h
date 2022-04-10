template <class T>
bool compare(const T& a, const T& b)
{
	return a > b;
}

template<class T>
bool paritate(const T& a, const T& b)
{
	return a % 2 == b % 2;
}

template <class T> 
class tvector
{
private:
	T* v;
	int n, maxx;
public:
	tvector() : n(0), maxx(1)
	{
		v = (T*)malloc(sizeof(T));
	}

	void push(const T& x)
	{
		if (n + 1 == maxx)
		{
			maxx = maxx * 2;
			v = (T*)realloc(v, maxx*sizeof(T));
		}
		v[n++] = x;
	}

	const T& pop()
	{
		return v[n - 1];
	}

	void remove(int i)
	{
		n--;
		for (int j = i; j < n; j++)
			v[j] = v[j + 1];
	}

	void insert(int i, const T& x)
	{
		n++;
		if (n == maxx)
		{
			maxx = maxx * 2;
			v = (T*)realloc(v, maxx * sizeof(T));
		}

		for (int j = n - 1; j > i; j--)
			v[j] = v[j - 1];
		v[i] = x;
	}

	void print()
	{
		for (int i = 0; i < n; i++)
			std::cout << v[i] << ' ';
		std::cout << '\n';
	}

	const T& get(int i)
	{
		return v[i];
	}

	void set(int i, const T& x)
	{
		v[i] = x;
	}

	int count()
	{
		return n;
	}
	
	void sort(bool(*callback)(const T&,const T&))
	{
		if (callback == nullptr)
		{
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if (!(v[i] < v[j]))
					{
						T aux = v[i];
						v[i] = v[j];
						v[j] = aux;
					}
		}
		else
		{
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if (!callback(v[i], v[j]))
					{
						T aux = v[i];
						v[i] = v[j];
						v[j] = aux;
					}
		}	
	}

	int firstIndexOf(const T& a, bool(*callback)(const T&, const T&))
	{
		if (callback == nullptr)
		{
			for (int i = 0; i < n; i++)
				if (a == v[i])
					return i;
			return n;
		}
		else
		{
			for (int i = 0; i < n; i++)
				if (callback(a, v[i]))
					return i;
			return n;

		}
	}
	~tvector()
	{
		delete[] v;
	}
};