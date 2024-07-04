// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
// String + RLE + Greedy

class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Run Length Encoding (RLE)
        deque<pair<char, int>> rle;
        for (char c : s) {
            if (rle.empty() || rle.back().first != c) {
                rle.push_back({c, 1});
            } else {
                rle.back().second++;
            }
        }
        
        // Step 2: Greedy removal
        while (rle.size() >= 2 && rle.front().first == rle.back().first) {
            rle.pop_front();
            rle.pop_back();
        }

        if (rle.size() == 1 && rle.back().second > 1) rle.pop_back();
        
        // Step 3: Compute minimum length
        int minLen = 0;
        for (auto& p : rle) {
            minLen += p.second;
        }
        
        return minLen; 
    }
};

