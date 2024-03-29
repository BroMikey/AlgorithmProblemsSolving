#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

/*±©Á¦½â·¨*/
int DiffenceOfXor1(int N,vector<int> nums) {
	vector<int> mem;
	int maxXor = nums[0], minXor = nums[0];
	for (int i = 0; i < N; i++) {
		int temp = nums[i];
		mem.push_back(nums[i]);
		for (int j = i + 1; j < N; j++) {
			temp = temp ^ nums[j];
			maxXor = max(maxXor, temp);
			minXor = min(minXor, temp);
		}
	}
	return maxXor - minXor;
}


int DiffenceOfXor2(int n, vector<int>nums) {
	return 0;
}



int main() {
	int N = 0;
	cin >> N;
	vector<int> array(N);
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	cout << DiffenceOfXor1(N, array) << endl;
	//cout << DiffenceOfXor2(N, array) << endl;
	return 0;
}