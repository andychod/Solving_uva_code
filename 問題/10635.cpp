#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 250 * 250;
const int INF = 100000000;
int S[maxn], g[maxn], d[maxn]; //LIS所需
int num[maxn]; // num[X]為整數X的新編號，num[X]=0表沒

int main()
{
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		int N, p, q, x;
		cin >> N >> p >> q;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= p + 1; i++) { cin >> x; num[x] = i; }
		int n = 0;
		for (int i = 0; i < q + 1; i++){ cin >> x; if (num[x])S[n++] = num[x]; }

		//求解S[0]...S[n-1]的LIS
		for (int i = 1; i < n; i++) g[i] = INF;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int k = lower_bound(g + 1, g + n + 1, S[i]) - g; //在g[1]~g[n]中搜尋
			d[i] = k;
			g[k] = S[i];
			ans = max(ans, d[i]);
		}
		cout << "Case " << kase << ": " << ans << endl;
	}
	return 0;
}