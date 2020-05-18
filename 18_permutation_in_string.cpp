/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.



Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False


Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> chars1(26, 0);
        vector<int> chars2(26, 0);
        for (char ch : s1)
            chars1[ch-'a']++;
        int p = s1.length();
        int n = s2.length();
        for (int i=0; i<n; ++i) {
            chars2[s2[i]-'a']++;
            if (i >= p) {
                chars2[s2[i-p]-'a']--;
            }
            if (chars1 == chars2)
                return true;
        }
        return false;
    }
};
