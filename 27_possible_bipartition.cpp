/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/


class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;
        for (vector<int> each : dislikes) {
            mp[each[0]].push_back(each[1]);
            mp[each[1]].push_back(each[0]);
        }
        if (dislikes.empty()) {
            return true;
        }
        stack<int> st;
        unordered_map<int, int> room;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            if (room[it->first] == 0) {
                room[it->first] = 1;
                st.push(it->first);
            }
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                for (int each : mp[node]) {
                    if (room[each] == room[node]) {
                        return false;
                    } else if (room[each] == 0) {
                        room[each] = room[node] == 1 ? 2 : 1;
                        st.push(each);
                    } 
                }
            }
        }
        return true;
    }
};