// https://leetcode.com/problems/find-the-closest-palindrome/description/
// Math

class Solution {
public:
    string createPalindrome(const string& prefix, bool oddLength) {
        int l = prefix.size();

        string palindrome = prefix;
        for (int i = (oddLength ? l - 2 : l - 1); i >= 0; --i) {
            palindrome.push_back(prefix[i]);
        }
        return palindrome;
    }

    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();

        // Candidates for the nearest palindrome
        vector<long long> candidates;
        
        string prefix = n.substr(0, (len + 1) / 2);
        candidates.push_back(stoll(createPalindrome(prefix, len % 2 == 1)));
        candidates.push_back(stoll(createPalindrome(to_string(stoll(prefix) - 1), len % 2 == 1)));
        candidates.push_back(stoll(createPalindrome(to_string(stoll(prefix) + 1), len % 2 == 1)));
        
        // Palindromes with length one less and one more
        candidates.push_back(pow(10, len - 1) - 1);  // e.g., 999 for length 1000
        candidates.push_back(pow(10, len) + 1);      // e.g., 10001 for length 9999
        
        // 3. Find the closest palindrome
        long long closest = numeric_limits<long long>::max();
        long long minDiff = numeric_limits<long long>::max();
        
        for (auto candidate : candidates) {
            if (candidate != num) {
                long long diff = abs(candidate - num);
                if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                    minDiff = diff;
                    closest = candidate;
                }
            }
        }
        
        return to_string(closest);
    }
};
