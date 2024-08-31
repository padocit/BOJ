#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, arr[100], v, num = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) 
		scanf("%d", &arr[i]);

	scanf("%d", &v);

	for (int i = 0; i < N; ++i) {
		if (arr[i] == v)
			++num;
	}
	printf("%d", num);

	return 0;
}