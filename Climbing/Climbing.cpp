#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*�������*/
void BackTracking(int state, vector<int>& choices, int& res, int n)
{
	if (state == n)
	{
		res++;
	}

	for (auto choice : choices)
	{
		//��֦
		if (state + choice > n)
		{
			continue;
		}
		//����ѡ��
		BackTracking(state + choice, choices, res, n);
		//����
		//�����ⲻ��Ҫ����

	}
}

int ClimbingStairswithBackTracking(int n)
{
	vector<int> choices = { 1, 2 };
	int res = 0;
	int state = 0;

	BackTracking(state, choices, res, n);

	return res;
}

/*
int main()
{
	int n = 3;
	int ans = ClimbingStairswithBackTracking(n);
	cout << ans << endl;
	return 0;
}
*/


/*��������*/
int Dfs(int i)
{
	if (i == 1 || i == 2)
	{
		return i;
	}
	int count = Dfs(i - 1) + Dfs(i - 2);
	return count;
}

int ClimbingwithDfs(int n)
{
	return Dfs(n);
}

/*
int main()
{
	cout << ClimbingwithDfs(109) << endl;
}
*/

/*���仯����*/
//ǰһ�������˷�̫��ʱ���ڼ�����ͬ��������Щ����¼�������Խ�ʡʱ��
int DfsMemory(int i, vector<int>& mem)
{
	if (i == 1 || i == 2)
	{
		return i;
	}
	if (mem[i])
	{
		return mem[i];
	}

	int count = DfsMemory(i - 1, mem) + DfsMemory(i - 2, mem);
	mem[i] = count;
	return count;
}

int ClimbingDfsMemory(int n)
{
	vector<int> mem(n + 1, 0);
	return DfsMemory(n, mem);
}

/*
int main()
{
	cout << ClimbingDfsMemory(1000);
	return 0;
}
*/

/*��̬�滮*/
int ClimbingDynamic(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}

	vector<int> Dp(n + 1);
	 
	Dp[1] = 1;
	Dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		Dp[i] = Dp[i - 1] + Dp[i - 2];
	}
	return Dp[n];
}

/*
int main()
{
	cout << ClimbingDynamic(10) << endl;
	return 0;
}
*/

int ClimbingDynamic2(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}

	int a = 1, b = 2;

	for (int i = 3; i <= n; i++)
	{
		int temp = b;
		b = a + b;
		a = temp;
	}

	return b;
}

/*
int main()
{
	cout << ClimbingDynamic2(3) << endl;
	return 0;
}
*/

int MinCostClimbing(vector<int>& cost)
{
	int n = cost.size() - 1;
	if (n == 1 || n == 2)
	{
		return n;
	}
	vector<int> dp(n + 1);
	dp[1] = cost[1];
	dp[2] = cost[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = min(dp[i - 1] , dp[i - 2]) + cost[i];
	}
	return dp[n];
}

/*
int main()
{
	vector<int> cost = { 1,10,1 };
	cout << MinCostClimbing(cost) << endl;
	return 0;
}
*/

int MinCostClimbing2(vector<int>& cost)
{
	int n = cost.size() - 1;

	if (n == 1 || n == 2)
	{
		return n;
	}

	int a = cost[1], b = cost[2];
	for (int i = 3; i <= n; i++)
	{
		int temp = b;
		b = min(a, b) + cost[i];
		a = temp;
	}
	return b;
}


/*�к�Ч����¥��*/
int ConstraintClimbing(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}

	vector<vector<int>> dp(n + 1, vector<int>(3, 0));

	dp[1][1] = 1;//��һ��[]���ǵ�i�׷������ڶ���[]����һ�����˼���
	dp[1][2] = 0;
	dp[2][1] = 0;
	dp[2][2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
	}
	return dp[n][1] + dp[n][2];
}












