#include<iostream>
using namespace std;

long long getValue(long long n)
{
	long long v = 0;
	while (n > 10)
	{
		v += n % 10;
		n /= 10;
	}
	v += n;
	return v;
}

int main()
{
	long long num;
	while (cin >> num && num)
	{
		while (num / 10)
			num = num / 10 + num % 10;
		/*while (num>9)
		{
			num = getValue(num);
		}*/
		cout << num << endl;
	}

	return 0;
}