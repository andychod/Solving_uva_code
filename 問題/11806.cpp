#include<iostream>
#include<string>
using namespace std;

const int MOD = 1000007;
const int MAXK = 510;
int C[MAXK][MAXK] = { {} };

int main()
{
	C[0][0] = 1;
	for (int i = 0; i <= MAXK; i++) // C i 取 j 的寫法  (排列組合)
	{
		C[i][0] = C[i][i] = 1; // 邊界條件
		for (int j = 1; j < i; j++)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}

	int T;
	cin >> T;
	for (int Kase = 1; Kase <= T; Kase++)
	{
		int n, m, k, sum = 0;
		cin >> n >> m >> k;
		for (int S = 0; S < 16; S++) //列舉所有16種"搭配方式"
		{                          
			int b = 0, r = n, c = m; //b用來統計集合的個數，r和c是可以放置的行列數
			if (S & 1)               //第一行沒有石頭，可以放石頭的行數r減1
			{
				r--;  b++;
			}
			if (S & 2)
			{
				r--;  b++;
			}
			if (S & 4)
			{
				c--;  b++;
			}
			if (S & 8)
			{
				c--;  b++;
			}
			if (b & 1)  //奇數個條件，做減法
				sum = (sum + MOD - C[r*c][k]) % MOD;
			else        //偶數個條件，作加法
				sum = (sum + C[r*c][k]) % MOD;
		}
		cout << "Case " << Kase << ": " << sum << endl;
	}
	return 0;
}