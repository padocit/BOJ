#include <bits/stdc++.h>
#include <list>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	list<char> editor;
	string s = "";
	cin >> s;
	for (auto c : s)
		editor.push_back(c);

	list<char>::iterator cur = editor.end();

	int T = 0;
	cin >> T;
	while (T-- > 0)
	{
		char command;
		cin >> command;
		switch (command)
		{
		case 'L':
			if (cur != editor.begin()) cur--;
			break;
		case 'D':
			if (cur != editor.end()) cur++;
			break;
		case 'B':
			if (cur != editor.begin()) {
				cur--;
				cur = editor.erase(cur);
			}
			break;
		case 'P':
			char c;
			cin >> c;
			editor.insert(cur, c);
			break;
		}
	}
	for (auto c : editor)
		cout << c;
	cout << '\n';

	return 0;
}