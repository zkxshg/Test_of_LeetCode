// https://leetcode.com/problems/relative-sort-array/?envType=daily-question&envId=2024-06-11
// hash table

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();
        
        unordered_map<int, int> ind;
        for (int i = 0; i < n; i++) ind[arr2[i]] = i;

        vector<int> left;
        vector<int> fre(n);
        for (int i : arr1) {
            if (ind.find(i) != ind.end()) fre[ind[i]]++;
            else left.push_back(i);
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < fre[i]; j++) res.push_back(arr2[i]);
        }

        sort(left.begin(), left.end());
        for (int i : left) res.push_back(i);

        return res;
    }
};
