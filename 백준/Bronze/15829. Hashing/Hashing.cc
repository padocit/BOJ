#include <iostream>
#include <cmath>

using namespace std;

int hash_func(char* s, int size)
{
	int M = 1234567891;
	int key = 0;
	long long sum = 0;
	for (int i = 0; i < size; i++)
	{
		long long r = 1;
		int c = s[i] - 'a' + 1; // 1 ~ 26
		for (int k = 0; k < i; k++)
		{
			r *= 31;
			if (r > M) r %= M; 
		}
		sum += c * r;
	}
	key = sum % M;
	
	return key;
}

int main()
{
	int L;
	cin >> L;
	char* s = new char[L];
	cin >> s; // 소문자
	
	int key = hash_func(s, L);
	cout << key << endl;
	return 0;
}
