/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.



Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3


Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
*/


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int judge = 0;
        set<int> tr;
        unordered_map<int, int> cnts;
        for (vector<int> pair : trust) {
            tr.insert(pair[0]);
            cnts[pair[1]]++;
        }
        for (int i : tr)
            judge ^= i;
        for (int i=1; i<=N; ++i)
            judge ^= i;
        if (judge and cnts[judge] == N-1)
            return judge;
        return -1;
    }
};

// Using indegree-outdegree concept
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // int ins[N+1], outs[N+1];
        // memset(ins, 0, sizeof(ins));
        // memset(outs, 0, sizeof(outs));
        if (trust.size() < N-1)
            return -1;

        vector<int> trustLvl(N+1, 0);
        int judge = 1;
        for (vector<int> pair : trust) {
            trustLvl[pair[0]] = -1;
            if (trustLvl[pair[1]] != -1) {
                trustLvl[pair[1]]++;
                if (trustLvl[pair[1]] == N-1)
                    judge = pair[1];
            }
        }
        return trustLvl[judge] == N-1 ? judge : -1;
    }
};
