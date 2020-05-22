/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnts;
        for (char ch : s) {
            cnts[ch]++;
        }
        map<int, string> ord;
        for (auto it=cnts.begin(); it != cnts.end(); ++it) {
            char ch = it->first;
            int cnt = it->second;
            ord[cnt] += string(cnt, ch);
        }
        string ans = "";
        for (auto rit=ord.rbegin(); rit != ord.rend(); ++rit) {
            ans += rit->second;
        }
        return ans;
    }
};