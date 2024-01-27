#include <iostream>
#include <algorithm>

using namespace std;

struct point
{
	int x;
	int y;
};

bool cmp(const point& left, const point& right)
{
	if (left.x == right.x) return left.y < right.y;
	return left.x < right.x;
}

int main()
{
	int N;
	cin >> N;

	point* p = new point[N];
	for (int i = 0; i < N; i++)
		cin >> p[i].x >> p[i].y;

	sort(p, p + N, cmp);

	for (int i = 0; i < N; i++)
		cout << p[i].x << ' ' << p[i].y << '\n';

	return 0;
}