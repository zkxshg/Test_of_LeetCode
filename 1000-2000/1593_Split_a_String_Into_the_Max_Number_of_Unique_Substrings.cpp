// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/?envType=daily-question&envId=2024-10-21
// Bitmask
class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.length();
        
        int res = 1;
        for (int mask = 1; mask < (1 << n - 1); mask++) {
            int subStrNum = 0;
            unordered_map<string, int> substrCou;
            string currentSubstr = ""; currentSubstr += s[0];

            bool unique = true;
            for (int i = 0; i < n - 1; i++) {
                if (mask & (1 << i)) {
                    if (substrCou.count(currentSubstr) != 0) {
                        unique = false;
                        break;
                    }

                    substrCou[currentSubstr]++;
                    currentSubstr = ""; currentSubstr += s[i + 1]; 
                    subStrNum++;
                }
                else {
                    currentSubstr += s[i + 1]; 
                }
            }

            if (substrCou.count(currentSubstr) != 0) unique = false;
            else subStrNum++;

            if (unique) res = max(res, subStrNum);
        }
        
        return res;
    }
};

// Backtracking
class Solution {
public:
    int maxUniqueSplit(std::string s) {
        int n = s.length();
        std::unordered_set<std::string> uniqueSubstrings;
        return backtrack(s, 0, uniqueSubstrings);
    }

    int backtrack(const std::string &s, int start, std::unordered_set<std::string> &uniqueSubstrings) {
        if (start == s.length()) {
            return uniqueSubstrings.size();
        }

        int maxCount = 0;
        std::string currentSubstring;

        for (int end = start; end < s.length(); ++end) {
            currentSubstring += s[end]; // Build the substring character by character
            if (uniqueSubstrings.find(currentSubstring) == uniqueSubstrings.end()) {
                // If the substring is unique, add it to the set
                uniqueSubstrings.insert(currentSubstring);
                // Recurse to the next position
                maxCount = std::max(maxCount, backtrack(s, end + 1, uniqueSubstrings));
                // Backtrack: remove the substring from the set
                uniqueSubstrings.erase(currentSubstring);
            }
        }

        return maxCount;
    }
};
