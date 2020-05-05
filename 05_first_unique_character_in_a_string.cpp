/*
Given a string, find the first non-repeating character in it and return its index.
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> chars;
        int len = s.length();
        for(int i=0; i<len; ++i) {
            chars[s[i]].first++;
            chars[s[i]].second = i;
        }
        for(int i=0; i<len; ++i) {
            if(chars[s[i]].first == 1)
                return chars[s[i]].second;
        }
        return -1;
    }
};
