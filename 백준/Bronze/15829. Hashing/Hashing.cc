#include <iostream>
#include <cmath>

using namespace std;

int hash_func(char* s, int size)
{
	int r = 31;
	int M = 1234567891;

	int key = 0;
	long double sum = 0;
	for (int i = 0; i < size; i++)
	{
		double c = s[i] - 'a' + 1; // 1 ~ 26
		sum += c * pow(r, i);
	}
	key = fmodl(sum, M);
	
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
