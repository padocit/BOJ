#include <iostream>
#include <string>

using namespace std;

void PrintFizzBuzz(int n)
{
	string out;

	if (n % 15 == 0) out = "FizzBuzz";
	else if (n % 3 == 0) out = "Fizz";
	else if (n % 5 == 0) out = "Buzz";
	else out = to_string(n);

	cout << out << "\n";
}

void ReadFizzBuzz(int* mul, int& n)
{
	string input;

	for (int i = 0; i < 3; ++i)
	{
		cin >> input;

		if (input == "FizzBuzz")
		{
			mul[i] = 15;
		}
		else if (input == "Fizz")
		{
			mul[i] = 3;
		}
		else if (input == "Buzz")
		{
			mul[i] = 5;
		}
		else // 숫자
		{
			n = stoi(input) + 3 - i;
			return;
		}
	}

	int k = 1;
	while ((mul[0] * k + 1) % mul[1] != 0 || (mul[1] * k + 1) % mul[2] != 0)
	{
		k += 1;
	}

	n = mul[0] * k + 3;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int mul[3] = { 0, };
	int n = 0;

	ReadFizzBuzz(mul, n);

	PrintFizzBuzz(n);

	return 0;
}