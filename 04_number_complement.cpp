/*
Given a positive integer, output its complement number.
The complement strategy is to flip the bits of its binary representation.
*/

class Solution {
public:
    int findComplement(int num) {
        int i=0;
        long long power = pow(2, i);
        while(power <= num) {
            i++;
            power = pow(2, i);
        }
        return num ^ (power-1);
    }
};
