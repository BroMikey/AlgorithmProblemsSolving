#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

int lengthOfLongestSubstring(string s) {

    if (s.size() == 0 || s.size() == 1){
        return s.size();
    }
    if (isspace(s.front())) {
        return 1;
    }
    int i = 0, count = 0;
    for (i = 0; i < s.size(); i++) {
        map<char, int> words;
        int temp = 0;
        for(int k = i; k < s.size(); k++) {
            if (words.find(s[k]) == words.end()) {//如果找不到就存
                words[s[k]] = k;
                temp++;
            }
            else {
                count = max(count,temp);
                i = words.find(s[k])->second;//找到了就下一循环
                break;
            }
        }
        count = max(temp, count);
    }
    return count;
}

int main() {
    string s = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    cout << length << endl;
    return 0;
}