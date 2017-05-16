#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 1000000 + 10;
long long A[maxn], C[maxn], tot, M;

int main()
{
	int n;
	while (cin >> n)
	{
		tot = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> A[i];
			tot += A[i];
		}
		M = tot / n;
		C[0] = 0;
		for (int i = 1; i < n; i++)
			C[i] = C[i - 1] + A[i] - M;  //»¼±ÀC°}¦C
		sort(C, C + n);
		long long x1 = C[n / 2], ans = 0;   //­pºâx1
		for (int i = 0; i < n; i++)
			ans += abs(x1 - C[i]);
		cout << ans << endl;
	}
	return 0;
}