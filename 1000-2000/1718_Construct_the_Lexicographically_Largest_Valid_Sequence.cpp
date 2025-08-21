// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
// Backtracking

class Solution {
public:
    bool addSeq(vector<int>& arr, int pos, vector<int>& dic) {
        int a = arr.size(), d = dic.size() - 1;
        // for (int i : arr) cout << i << ","; cout << endl;
        if (pos >= a) return true;
        
        if (arr[pos]) return addSeq(arr, pos + 1, dic);
        
        bool vali = false;
        for (int i = d; i >= 1; i--) {
            if (dic[i]) continue;
            
            if (i == 1) {
                 arr[pos] = i; dic[i] = 1;
            }
            else if (pos + i >= a || arr[pos + i]) continue;
            else {
                arr[pos] = i; arr[pos + i] = i; dic[i] = 1;
            }
            
            if (addSeq(arr, pos + 1, dic)) return true;
            
            arr[pos] = 0; dic[i] = 0;
            if (i > 1) arr[pos + i] = 0;
        }
        
        return vali;
    }
    vector<int> constructDistancedSequence(int n) {
        if (n == 1) return {1};
        if (n == 2) return {2,1,2};
        if (n == 3) return {3,1,2,3,2};
        if (n == 4) return {4,2,3,2,4,3,1};
        if (n == 5) return {5,3,1,4,3,5,2,4,2};
        
        vector<int> label(2*n - 1);
        vector<int> dict(n + 1);
        bool res = addSeq(label, 0, dict);
        
        return label;
    }
};
