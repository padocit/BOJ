#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	int V;
	cin >> V; // 1 <= V <= 15
	string vote;
	cin >> vote;

	int a = 0;
	int b = 0;
	for (int i = 0; i < V; i++)
	{
		if (vote[i] == 'A') a++;
		else if (vote[i] == 'B') b++;
	}

	if (a == b)
	{
		cout << "Tie" << endl;
	}
	else if (a > b)
	{
		cout << 'A' << endl;
	}
	else
	{
		cout << 'B' << endl;
	}

	return 0;
}