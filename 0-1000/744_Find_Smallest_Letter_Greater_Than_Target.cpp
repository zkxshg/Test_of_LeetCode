// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// binary search

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        unordered_map<char, int> dict;
        for (char c : letters) dict[c]++;
        
        for (int i = 1; i < 26; i++) 
            if (dict[(target - 'a' + i) % 26 + 'a'])
                return (target - 'a' + i) % 26 + 'a';
        
        return target;
    }
};
