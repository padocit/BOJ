#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	int count = 0;
	int num = 666;
	while (count < N)
	{
		string s = to_string(num);
		if (s.find("666") != std::string::npos) count++;
		if (count == N) cout << num << endl;
		num++;
	}

	return 0;
}