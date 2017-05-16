#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long m, w, count;
	long long ele[100000];
	while (T--)
	{
		count = 0;
		cin >> m >> w;
		for (int i = 0; i < m; i++)
			cin >> ele[i];
		sort(ele, ele + m);
		for (int i = 0; i < m; i++)
		{
			w -= ele[i];
			if (w >= 0)
				count++;
			else
				break;
		}
		cout << count << endl;
	}

	return 0;
}