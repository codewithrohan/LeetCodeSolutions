/* Dynamic Programming implementation of MCP problem */

#include <bits/stdc++.h>
#include<limits.h>
#define R 3
#define C 3
using namespace std;
int min(int x, int y, int z);

int minCost(int cost[R][C], int m, int n)
{
	int i, j;
	int tc[R][C];

	tc[0][0] = cost[0][0];

	/* Initialize first column of total cost(tc) array */
	for (i = 1; i <= m; i++)
		tc[i][0] = tc[i - 1][0] + cost[i][0];

	/* Initialize first row of tc array */
	for (j = 1; j <= n; j++)
		tc[0][j] = tc[0][j - 1] + cost[0][j];

	/* Construct rest of the tc array */
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			tc[i][j] = min(tc[i - 1][j - 1],
						tc[i - 1][j],
						tc[i][j - 1]) + cost[i][j];

	return tc[m][n];
}

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
if (x < y)
	return (x < z)? x : z;
else
	return (y < z)? y : z;
}

/* Driver code*/
int main()
{
int cost[R][C] = { {1, 2, 3},
					{4, 8, 2},
					{1, 5, 3} };
cout << " " << minCost(cost, 2, 2);
return 0;
}

