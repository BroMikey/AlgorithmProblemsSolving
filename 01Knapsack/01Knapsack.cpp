#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int m = 0, n = 0;
	int w[1005],v[1005];
	int dp[1005];
	scanf("%d %d",&m,&n);
	for(int i = 0; i < m; i++){
		scanf("%d %d",&w[i],&v[i]);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(j < w[i]){
				dp[j] = dp[i];
			}
			else{
				dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
			}
		}
	}
	
	
	printf("%d",dp[n - 1]);
}



















