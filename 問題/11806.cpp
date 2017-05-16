#include<iostream>
#include<string>
using namespace std;

const int MOD = 1000007;
const int MAXK = 510;
int C[MAXK][MAXK] = { {} };

int main()
{
	C[0][0] = 1;
	for (int i = 0; i <= MAXK; i++) // C i �� j ���g�k  (�ƦC�զX)
	{
		C[i][0] = C[i][i] = 1; // ��ɱ���
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
		for (int S = 0; S < 16; S++) //�C�|�Ҧ�16��"�f�t�覡"
		{                          
			int b = 0, r = n, c = m; //b�ΨӲέp���X���ӼơAr�Mc�O�i�H��m����C��
			if (S & 1)               //�Ĥ@��S�����Y�A�i�H����Y�����r��1
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
			if (b & 1)  //�_�ƭӱ���A����k
				sum = (sum + MOD - C[r*c][k]) % MOD;
			else        //���ƭӱ���A�@�[�k
				sum = (sum + C[r*c][k]) % MOD;
		}
		cout << "Case " << Kase << ": " << sum << endl;
	}
	return 0;
}