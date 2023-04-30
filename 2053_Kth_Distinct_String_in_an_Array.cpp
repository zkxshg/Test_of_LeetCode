// https://leetcode.com/problems/kth-distinct-string-in-an-array/
// hash table

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> dict;
        
        for (string& s : arr) dict[s]++;
        
        int cou = 0; string res = "";
        
        for (string& s : arr) 
            if (dict[s] < 2) {
                cou++;
                if (cou == k) {
                    res = s;
                    break;
                }
            }
        
        return res;
    }
};
