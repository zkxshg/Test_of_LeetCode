// https://leetcode.com/problems/maximum-score-words-formed-by-letters/?envType=daily-question&envId=2024-05-24
// Bit mask

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();

        vector<int> letterFreq(26, 0); // 储存letters中每个字母的frequency
        for (char letter : letters) {
            letterFreq[letter - 'a']++;
        }
        
        // 储存每个words中每个index对应的string对应的每个字母的frequency
        unordered_map<int, vector<int>> wordFreq;
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            for (char letter : words[i]) {
                freq[letter - 'a']++;
            }
            wordFreq[i] = freq;
        }
        
        int maxScore = 0;
        // bit mask
        for (int i = 0; i < (1 << n); i++) { 
            vector<int> tempFreq = letterFreq; // 复制一份letters的频率
            int currScore = 0;
            bool isValid = true;
            for (int j = 0; j < words.size(); ++j) {
                if ((i & (1 << j)) != 0) { // 当前word被选中
                    for (int k = 0; k < 26; ++k) {
                        tempFreq[k] -= wordFreq[j][k]; // 减去当前word的频率
                        if (tempFreq[k] < 0) { // 如果letters中某个字母的频率小于0，说明无法组成当前word
                            isValid = false;
                            break;
                        }
                        currScore += wordFreq[j][k] * score[k]; // 更新当前得分
                    }
                }
                if (!isValid) {
                    break;
                }
            }
            if (isValid) {
                maxScore = max(maxScore, currScore);
            }
        }
        
        return maxScore;
    }
};
