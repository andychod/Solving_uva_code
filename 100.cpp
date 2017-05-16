#include<iostream>
#include<algorithm>
using namespace std;

long long solve(long long n, long long &times)
{
	if (n == 1)
		return times;
	else if (n % 2 == 0)
		n /= 2;
	else
		n = 3 * n + 1;
	times++;
	solve(n, times);
}


int main()
{
	long long x, y, Max, times;
	long long X, Y;
	while (cin >> X >> Y)
	{
		x = X < Y ? X : Y;
		y = Y > X ? Y : X;
		Max = 1;
		int temp;
		for (long long i = x; i <= y; i++)
		{
			times = 1;
			temp = solve(i, times);
			Max = temp > Max ? temp : Max;

		}
		cout << x << " " << y << " ";
		cout << Max << endl;
	}

	return 0;
}