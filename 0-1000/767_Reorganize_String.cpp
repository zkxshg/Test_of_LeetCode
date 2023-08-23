// https://leetcode.com/problems/reorganize-string/description/
// Greedy + heap

class Solution {
public:
    string reorganizeString(string s) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c]++; 
        }

        // Create a max heap to store pairs of (freq, char)
        priority_queue<pair<int, char>> maxHeap;
        for(auto it : freq) {
            maxHeap.push({it.second, it.first}); 
        }

        // Build result string by appending most frequent char first
        string result;

        while(!maxHeap.empty()) {
            auto top = maxHeap.top(); 
            maxHeap.pop();

            result += top.second;
            freq[top.second]--;

            // If next char is same as prev, append next most frequent char
            if(!maxHeap.empty()) {
                auto nextTop = maxHeap.top();
                maxHeap.pop();

                result += nextTop.second;
                freq[nextTop.second]--;

                if(freq[nextTop.second] > 0) {
                    maxHeap.push({freq[nextTop.second], nextTop.second});  
                }
            }
            else if (freq[top.second] > 0) return "";

            // Decrement freq and push back to heap if freq > 0
            if(freq[top.second] > 0) {
                maxHeap.push({freq[top.second], top.second});
            }
        }

        return result.length() == s.length() ? result : "";
    }
};
