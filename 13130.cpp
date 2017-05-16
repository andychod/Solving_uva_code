#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int num[5], flag = 1;
	while (T--)
	{
		flag = 1;
		for (int i = 0; i < 5; i++)
			cin >> num[i];
		sort(num, num + 5);
		for (int i = 0; i < 4; i++)
		{
			if (num[i + 1] - num[i] != 1)
			{
				flag = 0;
				break;
			}
		}

		if (flag)
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}