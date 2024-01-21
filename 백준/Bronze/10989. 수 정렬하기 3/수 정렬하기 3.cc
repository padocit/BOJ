#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

#define MAX 10000

int main()
{
	int N, num;
	scanf("%d", &N);

	int* arr = new int[MAX];
	for (int i = 0; i < MAX; i++)
		arr[i] = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		arr[num - 1]++;
	}

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i + 1);

	delete[] arr;
	return 0;
}