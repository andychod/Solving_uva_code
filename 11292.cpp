#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 20000 + 5;
int A[maxn], B[maxn];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m==0)
			break;

		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];
		sort(A, A + n);
		sort(B, B + m);
		int cur = 0;      // 目前需要砍掉的頭的編號
		int cost = 0;     // 目前總費用
		for (int i = 0; i < m; i++)
		{
			if (B[i] >= A[cur])
			{
				cost += B[i];
				if (++cur == n)
					break;
			}
		}
		if (cur < n)
			cout << "Loowater is doomed!\n";
		else
			cout << cost << endl;
	}
	return 0;
}