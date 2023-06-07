class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // we need to check the ith bit of the number
        // given number n 
        // assume a number 1
        // left shift it k times
        if(k == 0) return 1 & n;
        return (1 << k) & n;
    }
};