// https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-16
// Math + Greedy

class Solution {
public:
    int maximumSwap(int num) {
        string strNum = to_string(num);
        vector<int> lastIndex(10, -1); 
        
        for (int i = 0; i < strNum.size(); i++) {
            lastIndex[strNum[i] - '0'] = i;
        }
        
        for (int i = 0; i < strNum.size(); i++) {
            for (int d = 9; d > strNum[i] - '0'; d--) {
                if (lastIndex[d] > i) {
                    swap(strNum[i], strNum[lastIndex[d]]);
                    return stoi(strNum);
                }
            }
        }

        return num;
    }
};
