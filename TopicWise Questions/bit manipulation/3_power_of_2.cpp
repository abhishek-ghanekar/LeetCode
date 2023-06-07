class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n-1)) == 0;
    }
};
// if the number has one bit then it is a power of 2