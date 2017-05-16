#include<iostream>
using namespace std;
const int maxn = 10 + 5;
char grid[maxn][maxn];
int n;

int main()
{
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> grid[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) if (grid[i][j] == '.'){
				for (char ch = 'A'; ch <= 'Z'; ch++){
					bool ok = true;
					if (i>0 && grid[i - 1][j] == ch) ok = false;
					if (i < n - 1 && grid[i + 1][j] == ch) ok = false;
					if (j>0 && grid[i][j - 1] == ch) ok = false;
					if (j < n - 1 && grid[i][j + 1] == ch) ok = false;
					if (ok){ grid[i][j] = ch; break; }
				}
			}
		}

		cout << "Case " << kase << ":\n";
		for (int i = 0; i < n; i++)
			cout << grid[i] << endl;
	}

	return 0;
}