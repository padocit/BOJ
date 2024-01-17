#include <iostream>
#include <string>

using namespace std;

void Palindrome(int num)
{
	string s = to_string(num);
	int size = s.length();
	for (int i = 0; i < size / 2; i++)
	{
		if (s.at(i) != s.at(size - i - 1))
		{
			cout << "no" << endl;
			return;
		}
	}
	cout << "yes" << endl;
}

int main()
{
	int num;
	
	while (true)
	{
		cin >> num;
		if (num == 0) break;
		Palindrome(num);
	}

	return 0;
}