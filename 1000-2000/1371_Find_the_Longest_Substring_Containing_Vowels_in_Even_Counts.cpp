// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-01
// Prefix Sum + Bit Mask

class Solution {
public:
     int findTheLongestSubstring(string s) {
        unordered_map<int, int> first_occurrence;
        bitset<32> state;
        first_occurrence[0] = -1; // Base case: empty substring with all even counts

        int max_length = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == 'a') state.flip(0);
            else if (c == 'e') state.flip(1);
            else if (c == 'i') state.flip(2);
            else if (c == 'o') state.flip(3);
            else if (c == 'u') state.flip(4);

            int state_key = state.to_ulong();
            if (first_occurrence.find(state_key) != first_occurrence.end()) {
                max_length = max(max_length, i - first_occurrence[state_key]);
            } else {
                first_occurrence[state_key] = i;
            }
        }
        
        return max_length;
    }
};
