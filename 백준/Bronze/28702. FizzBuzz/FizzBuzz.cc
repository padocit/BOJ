#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

bool ReadFizzBuzz(int& n)
{
	string input;
	for (int i = 0; i < 3; ++i)
	{
		cin >> input;
		// 수학적으로 3번 중 최소 1개는 반드시 숫자 자체로 입력됨.
		if (input != "Fizz" && input != "Buzz" && input != "FizzBuzz")
		{
			n = stoi(input) + 3 - i;
			return true;
		}
	}
	return false;
}

void PrintFizzBuzz(int n)
{
	string output;
	if (n % 15 == 0) output = "FizzBuzz";
	else if (n % 3 == 0) output = "Fizz";
	else if (n % 5 == 0) output = "Buzz";
	else output = to_string(n);

	cout << output;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	// Input
	int n;
	assert(ReadFizzBuzz(n));

	// Output
	PrintFizzBuzz(n);

	return 0;
}