#include<iostream>
#include<cmath>
using namespace std;

int countD(long long n)
{
	int d = 0;
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return d;
}


long long inverse(long long n, const int &d)
{
	long long m = 0;
	for (int i = d - 1; i >= 0; i--)
	{
		m += (n % 10) * (int)pow(10, i);
		n /= 10;
	}
	return m;
}


int main()
{
	int T;
	cin >> T;
	long long n;
	long long m; // ¤Ï¹L¨Ó
	while (T--)
	{
		cin >> n;
		int times = 0;
		int d = countD(n);
		m = inverse(n, d);

		while (n - m != 0)
		{
			n += m;
			d = countD(n);
			m = inverse(n, d);
			times++;
		}
		cout << times << " " << n;
	}

	return 0;
}