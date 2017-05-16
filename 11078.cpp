#include<iostream>
#include<algorithm>
using namespace std;

int A[100000], n;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		int ans = A[0] - A[1];
		int MaxAi = A[0];
		for (int j = 1; j < n; j++)
		{
			ans = max(ans, MaxAi - A[j]);
			MaxAi = max(A[j], MaxAi);
		}
		cout << ans << endl;
	}
	return 0;
}