#include <stdio.h>

long long arr[101][101][2];

int main()
{
	int n, m, i, j;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				arr[i][j][0] = 1;
			else
			{
				arr[i][j][0] = arr[i - 1][j - 1][0] + arr[i - 1][j][0];
				arr[i][j][1] = arr[i - 1][j - 1][1] + arr[i - 1][j][1];
			}

			if (arr[i][j][0] >= 100000000000000000)
			{
				arr[i][j][1]++;
				arr[i][j][0] = arr[i][j][0] % 100000000000000000;
			}
		}
	}

	if (arr[n][m][1] == 0)
		printf("%lld", arr[n][m][0]);
	else
		printf("%lld%lld", arr[n][m][1], arr[n][m][0]);
}