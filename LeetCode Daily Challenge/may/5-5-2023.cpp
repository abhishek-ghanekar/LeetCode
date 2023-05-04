class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCount = 0;
        int dCount = 0;
        int rBan = 0;
        int dBan = 0;
        queue<char> q;

        for(char c: senate) {
           q.push(c);
           if(c == 'R') {
               rCount++;
           }else {
               dCount++;
           }
        }
        while(dCount && rCount) {
            char curr = q.front();
            q.pop();

            if(curr == 'D') {
                if(dBan) {
                    dBan--;
                    dCount--;
                }else {
                    rBan++;
                    q.push('D');
                }
            }else {
                if(rBan) {
                    rBan--;
                    rCount--;
                }else {
                    dBan++;
                    q.push('R');
                }
            }
        }
        return rCount ? "Radiant" : "Dire";
    }
};