#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

//eat tea tan ate nat bat end Ê¾ÀıÊäÈë

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>>map;
        for (auto str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};


int main()
{
    string input;
    vector<string> strings;
    while (cin >> input && input != "end")
    {
        strings.push_back(input);
    }
    Solution test;
    vector<vector<string>> ret = test.groupAnagrams(strings);
    for (auto it : ret)
    {
        for (auto str : it)
        {
            cout << str << " ";
        }
        cout << endl;
    }
	return 0;
}













