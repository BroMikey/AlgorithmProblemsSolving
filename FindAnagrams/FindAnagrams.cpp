#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

//寻找异位词可以转换为寻找词频相同的一段
vector<int> FindAnagrams(string s, string p) {
	int pLen = p.size(), sLen = s.size();

	if (sLen < pLen) {
		return vector<int>();
	}

	vector<int> ans;
	vector<int> sCount(26);
	vector<int> pCount(26);
	for (int i = 0; i < p.size(); i++) {
		pCount[p[i] - 'a']++;
		sCount[s[i] - 'a']++;
	}
	if (sCount == pCount)
	{
		ans.push_back(0);
	}
	for (int i = 0; i < sLen - pLen; i++) {
		--sCount[s[i] - 'a'];
		++sCount[s[i + pLen] - 'a'];

		if (sCount == pCount) {
			ans.push_back(i + 1);
		}
	}
	return ans;
}


int main() {
	string inputS = "cbaebabacd", inputP = "abc";

	vector<int> output = FindAnagrams(inputS,inputP);
	for (int one : output) {
		cout << one << " ";
	}
	return 0;
}