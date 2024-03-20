#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 1005;

int main(){
	int m = 0, n = 0;
	scanf("%d %d", &m, &n);

	int w[MAX], v[MAX];
	int dp[MAX + 1] = { 0 };
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			if (j < w[i])
			{
				continue;
			}
			else
			{
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}
	printf("%d", dp[n]);
	return 0;

}