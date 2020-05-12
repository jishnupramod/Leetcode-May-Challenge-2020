/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Find this single element that appears only once.



Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10


Note: Your solution should run in O(log n) time and O(1) space.
*/

// O(logn) Solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while (l <= r) {
            int mid = l+(r-l)/2;
            if (mid > 0 and nums[mid] == nums[mid-1]) {
                if (mid % 2)
                    l = mid + 1;
                else
                    r = mid - 2;
            }
            else if (mid < nums.size()-1 and nums[mid] == nums[mid+1]) {
                if (mid % 2)
                    r = mid - 1;
                else
                    l = mid + 2;
            }
            else
                return nums[mid];
        }
        return -1;
    }
};

// O(n) Solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a;
        for (int i : nums)
            a ^= i;
        return a;
    }
};
