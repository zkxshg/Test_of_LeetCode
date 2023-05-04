// https://leetcode.com/problems/dota2-senate/description/
// Queue

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();

        int Rnum = 0, Dnum = 0;

        queue<char> Q;
        for (char c : senate) {
            if (c == 'R') Rnum++;
            else Dnum++;

            Q.push(c);
        }

        int diff = 0;
        while (Rnum > 0 && Dnum > 0) {
            if (Q.front() == 'R') {
                if (diff >= 0) {
                    Q.pop(); Q.push('R');
                    diff++;
                }
                else {
                    Q.pop(); Rnum--;
                    diff++;
                }
            }
            else {  // Q.front() == 'D'
                if (diff <= 0) {
                    Q.pop(); Q.push('D');
                    diff--;
                }
                else {
                    Q.pop(); Dnum--;
                    diff--;
                }
            }
        }

        if (!Dnum) return "Radiant";
        return "Dire";
    }
};
