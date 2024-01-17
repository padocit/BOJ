#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int hash_func(string s)
{
	int r = 31;
	int M = 1234567891;

	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int c = s.at(i) - 'a' + 1; // 1 ~ 26
		sum += (c * int(pow(r, i))) % M; 
	}
	return sum;
}

int main()
{
	int L;
	cin >> L;
	string s;
	cin >> s; // 소문자
	
	int key = hash_func(s);
	cout << key << endl;
	return 0;
}