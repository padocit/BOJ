#include <iostream>
#include <string>
#include <map>

using namespace std;

class Poke_dict
{
public:

	Poke_dict()
	{

	}

	void setDict(int N)
	{
		for (int i = 0; i < N; i++)
		{
			string name;
			cin >> name;
			dict_.insert({ i + 1, name });
			fdict_.insert({ name, i + 1 });
		}
	}

	void testDict(int M)
	{
		for (int i = 0; i < M; i++)
		{
			string temp;
			cin >> temp;

			int num;
			if (temp[0] >= '0' && temp[0] <= '9') // 숫자라면
			{
				num = stoi(temp);
				cout << dict_[num] << '\n';
			}
			else // 문자라면
			{
				cout << fdict_[temp] << '\n';
			}
		}
	}

private:
	map<int, string> dict_;
	map<string, int> fdict_;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	Poke_dict mDict;
	mDict.setDict(N);
	mDict.testDict(M);

	return 0;
}