/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp1, mp2;
        vector<int> res;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        for (char ch : alpha) {
            mp1[ch] = 0;
            mp2[ch] = 0;
        }
        for (char ch : p)
            mp1[ch]++;
        int slen = s.length();
        int plen = p.length();
        for (int i=0; i<slen; ++i) {
            mp2[s[i]]++;
            if (i >= plen) {
                mp2[s[i-plen]]--;
            }
            if (mp1 == mp2)
                res.push_back(i - plen + 1);
        }
        return res;
    }
};
