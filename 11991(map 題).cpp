#include<iostream>
#include<vector>
#include<map>
using namespace std;


map<int, vector<int> > a;

int main()
{
	int n, m, x, y;
	while (cin >> n >> m)
	{
		a.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (!a.count(x))
				a[x] = vector<int>();
			a[x].push_back(i + 1);
		}

		while (m--)
		{
			cin >> x >> y;
			if (!a.count(y) || a[y].size() < x)
				cout << "0\n";
			else
				cout << a[y][x - 1] << endl;
		}
	}
	return 0;
}