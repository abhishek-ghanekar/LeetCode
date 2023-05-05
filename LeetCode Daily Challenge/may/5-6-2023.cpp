class Solution {
private:
    bool isVowel(char c) {
        if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) {
            return true;
        }else {
            return false;
        }
    }
public:
    int maxVowels(string s, int k) {
        int start = 0;
        int end = 0;
        int n = s.length();
        int ans = 0;
        int temp = 0;

        while(end < n) {
           
           if(isVowel(s[end])){
             temp++;
           }
           // this will move the sliding window forward when the difference of end and start is k
           if(end - start == k) {
               //move forward
               // as we move forward if the starting value was an vowel then we decrement the temp pointer
               if(isVowel(s[start])) {
                   temp--;
               }
               //move forward
               start++;
           }
           
           ans = max(temp,ans);
           end++;
        }
        return ans;
    }
};