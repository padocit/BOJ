#include <iostream>
#include <set>

using namespace std;

struct point2D
{
	int x;
	int y;

	bool operator<(const point2D& other) const
	{
		if (y == other.y) return x < other.x;
		return y < other.y;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	set<point2D> myset;
	int N;
	cin >> N;

	while (N-- > 0)
	{
		point2D temp;
		cin >> temp.x >> temp.y;
		myset.insert(temp);
	}

	for (point2D i : myset)
		cout << i.x << ' ' << i.y << '\n';

	return 0;
}