// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2024-09-15
// Trie + Hash Table

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // Generate all prefixes for numbers in arr1
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num); 
                num /= 10;
            }
        }

        int maxVal = -1;
        // Check prefixes for numbers in arr2
        for (int num : arr2) {
            while (num > 0) {
                if (prefixes.find(num) != prefixes.end()) {
                    maxVal = max(maxVal, num); // Update max length
                }
                num /= 10; // Remove the last digit
            }
        }

        int maxLength = 0;
        
        while (maxVal > 0) {
            maxLength++;
            maxVal /= 10;
        }

        return maxLength;
    }
};
