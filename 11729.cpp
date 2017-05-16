#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
	int j, b;
	bool operator < (const Job& x) const // ¹Bºâ¤l­«¸ü
	{
		return j > x.j;
	}
};

int main()
{
	int n, b, j, kase = 1;
	while (cin >> n && n)
	{
		vector<Job> v;
		for (int i = 0; i < n; i++)
		{
			cin >> b >> j;
			v.push_back(Job{ j, b });
		}
		sort(v.begin(), v.end());
		int s = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			s += v[i].b;
			ans = max(ans, s + v[i].j);
		}
		cout << "Case " << kase++ << ": " << ans << endl;
	}
	return 0;
}