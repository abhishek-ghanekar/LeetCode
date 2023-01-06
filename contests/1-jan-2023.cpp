// question 1
// 2520. Count the Digits That Divide a Number
class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int digit;
        int temp = num;
        while(temp) {
            digit = temp%10;
           if(num%digit == 0) {
               count++;
           }
           temp = temp/10;
        }
        return count;
    }
};
//question 2
// 2521. Distinct Prime Factors of Product of Array
class Solution {
public:
    //storing if number is prime
    vector<bool> prime;
    //apply sieve of erothenis
    //mark false for all not prime numbers
    void primeSieve(int n) {
        for(int p = 2; p*p <=n;p++) {
            if(prime[p] == true) {
                for(int i = p*p ; i<=n;i += p) {
                    prime[i] = false;
                }
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int cnt = 0;
        prime.resize(1001,1);
        primeSieve(1000);
        unordered_set<int> s;
        vector<int> primes;
        for(int p = 2;p<=1000;p++) {
            if(prime[p]) {
                primes.push_back(p);
            }
        }
        for(int i= 0;i<nums.size();i++) {
            int n = nums[i];
            int j=0;
            while(n>1) {
                while(n>1 && j<primes.size() && n%primes[j] == 0) {
                    s.insert(primes[j]);
                    n = n/primes[j];
                }
                j++;
            }
        }
        return s.size();
    }
}; 
