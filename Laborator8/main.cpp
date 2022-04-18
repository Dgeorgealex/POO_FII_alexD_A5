#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <utility>



using namespace std;
ifstream fin("date.in");




bool isseparator(char a, const string& sep)
{
	for (auto it : sep)
		if (a == it)
			return 1;
	return 0;
}
struct comparator
{
	bool operator()(const pair<string, int> &a , const pair<string, int> &b)
	{
		if (a.second != b.second)
			return a.second < b.second;
		return a.first > b.first;
	}
};

int main()
{
	map<string, int> m;
	priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;
	string s, sep = " ,.?!";

	getline(fin, s);
	cout << s << '\n';
	for (int i = 0; i <s.size(); i++)
	{
		if (!isseparator(s[i], sep))
		{
			int j;
			for (j = i; j < s.size() && !isseparator(s[j], sep); j++);
			string aux = s.substr(i, j - i);

			for (int k = 0; k < aux.size(); k++)
				aux[k] = tolower(aux[k]);

			m[aux]++;
			i = j;
		}
	}
	for (auto it : m)
		pq.push(make_pair(it.first, it.second));

	while (!pq.empty())
	{
		cout << pq.top().first << "=>" << pq.top().second << '\n';
		pq.pop();
	}
	return 0;
}