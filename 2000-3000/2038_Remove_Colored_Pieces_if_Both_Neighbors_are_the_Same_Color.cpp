// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/?envType=daily-question&envId=2023-10-02
// Greedy

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();

        int anum = 0, acou = 0, bnum = 0, bcou = 0;

        for (char c : colors) {
            if (c == 'A') {
                if (bcou >= 3) bnum += bcou - 2;
                bcou = 0;

                acou++;
            }
            else {
                if (acou >= 3) anum += acou - 2;
                acou = 0;

                bcou++;
            }
        }

        if (acou >= 3) anum += acou - 2;
        if (bcou >= 3) bnum += bcou - 2;

        return anum > bnum;
    }
};
