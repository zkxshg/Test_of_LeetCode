class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> result;
        if (len == 0) return result;
        if (len == 1) {
            result.push_back(strs);
            return result;
        }
        
        vector<int> slen(len);
        for (int i = 0; i < len; i++) slen[i] = strs[i].size();
        QuickSort(slen, strs, 0, len - 1);
    
        vector<string> resSort;
        
        vector<string> tempstr;
        tempstr.push_back(strs[0]);
        result.push_back(tempstr);
        
        sort(strs[0].begin(), strs[0].end());
        resSort.push_back(strs[0]);
        strs.erase(strs.begin());
            
        for (int i = 0; i < strs.size(); i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            
            bool exis = false;
            for (int j = 0; j < resSort.size(); j++){
                if (t == resSort[j]){
                    result[j].push_back(strs[i]);
                    exis = true;
                    break;
                }
                else if (strs[i].size() < resSort[j].size()) break;
            }
            
            if (exis) continue;
            
            vector<string> tempstr2;
            tempstr2.push_back(strs[i]);
            result.push_back(tempstr2);
            
            sort(strs[i].begin(), strs[i].end());
            resSort.push_back(strs[i]);
        }
        return result;
    }
    
     void QuickSort(vector<int>& B, vector<string>& strs, int f, int l){
        int x = B[f];
        int i = f + 1;
        int j = l;
        while (i < j){
            while (j >= f + 1 && B[j] >= x) j--;  // 顺序颠倒会引发 heap-buffer-overflow！！ 
            while (i <= l && B[i] <= x) i++;
            if (i < j){
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
                
                string temstr = strs[i];
                strs[i] = strs[j];
                strs[j] = temstr;
            }
        }
        if (B[f] > B[j]){
            B[f] = B[j];
            B[j] = x;
            
            string temstr2 = strs[f];
            strs[f] = strs[j];
            strs[j] = temstr2;
        }
        if (f < j-1) QuickSort(B, strs, f, j-1);
        if (j+1 < l) QuickSort(B, strs, j+1, l);
    }
};
