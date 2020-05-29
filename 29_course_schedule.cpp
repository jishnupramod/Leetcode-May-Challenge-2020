/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

class Solution {
public:
    // Khan's Algorithm - Checking if a graph has any cycles
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> indegree, outdegree;
        vector<int> indegree_zero;
        int zero_indegrees = 0;
        for (vector<int> each : prerequisites) {
            outdegree[each[0]].push_back(each[1]);
            indegree[each[1]].push_back(each[0]);
        }
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i].empty()) {
                indegree_zero.push_back(i);
                ++zero_indegrees;
            }
        }
        while (!indegree_zero.empty()) {
            int node = indegree_zero.back();
            indegree_zero.pop_back();
            for (int i : outdegree[node]) {
                auto it = find(indegree[i].begin(), indegree[i].end(), node);
                if (it != indegree[i].end()) {
                    indegree[i].erase(it);
                }
                if (indegree[i].empty()) {
                    indegree_zero.push_back(i);
                    ++zero_indegrees;
                }
            }
        }
        return numCourses == zero_indegrees;
    }
};