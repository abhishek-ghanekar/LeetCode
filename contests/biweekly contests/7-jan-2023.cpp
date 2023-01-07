// question 1 : 6287. Categorize Box According to Criteria
class Solution {
public:
    string categorizeBox(long long length, long long width, long long height, long long mass) {
        long long volume = length * width * height;
        if((length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000) && mass >= 100) {
            return "Both";
        }else if((length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000)) {
            return "Bulky";
        }else if(mass >= 100) {
            return "Heavy";
        }else {
            return "Neither";
        }
    }
};

//question 2 : 

//question 3 : 6289. Find Xor-Beauty of Array

class Solution {
public:
    int xorBeauty(vector<int>& nums) {   
    int beauty = 0;
    for (int num : nums) {
        beauty ^= num;
    }
    return beauty;
    }
};