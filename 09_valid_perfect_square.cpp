/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/


// Using Binary Search method
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        int  l = 0;
        int r = num/2+1;
        while (l <= r) {
            double mid = l+(r-l)/2;
            if (mid == num/mid)
                return true;
            else if (mid > num/mid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};

// Using Babylonian method
class Solution {
public:
    bool isPerfectSquare(int num) {
        int temp = num;
        int digits = 0;
        while (temp) {
            temp /= 10;
            ++digits;
        }
        digits = digits/2+1;
        double guess = 1;
        for (; digits > 1; --digits)
            guess *= 10;
        int prev = 0;
        while (prev != (int)guess) {
            prev = (int)guess;
            guess = 0.5 * (guess + num/guess);
        }
        if (prev == (double)num/prev)
            return true;
        if ((prev+1) == (double)num/(prev+1))
            return true;
        return false;
    }
};
