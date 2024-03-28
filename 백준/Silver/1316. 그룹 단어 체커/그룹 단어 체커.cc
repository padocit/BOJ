#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		set<char> alphabet;
		string word;
		cin >> word;

		bool isGroup = true;
		for (int j = 0; j < word.size(); j++)
		{
			char c = word[j];

			if (alphabet.find(c) == alphabet.end()) // 없으면
				alphabet.insert(c);
			else // 이미 있으면
				isGroup = false;

			while (word[j + 1] == c) j++; // 그룹문자 쭉 점프
		}
		if (isGroup) count++; // 검사 결과 그룹 단어면 카운트
	}

	cout << count;

	return 0;
}