// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
// sliding window

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int maxLength = 0;

        for (char target : {'T', 'F'}) {
            int left = 0, right = 0;

            int count = 0;
            while (right < n) {
                if (answerKey[right] != target) count++;
                
                while (count > k) {
                    if (answerKey[left] != target) {
                        count--;
                    }
                    left++;
                }
                
                maxLength = max(maxLength, right - left + 1);
                right++;
            }
        }

        return maxLength;
    }
};
