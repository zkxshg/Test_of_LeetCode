// binary sort + two pointer
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len < 2) return intervals;
        vector<vector<int>> result;
        QuickSort(intervals, 0, len - 1);
        int pos = 0, nex = 1;
        while (nex < intervals.size()) {
            if (intervals[pos][1] < intervals[nex][0]){
                result.push_back(intervals[pos]);
                pos = nex++;
            } 
            else if (intervals[pos][1] >= intervals[nex][1]) nex++;
            else {
                intervals[pos][1] = intervals[nex][1];
                nex++;
            }  
        }
        result.push_back(intervals[pos]);
        return result;
    }
    
    void QuickSort(vector<vector<int>>& B, int f, int l){
        int x = B[f][0];
        int i = f + 1;
        int j = l;
        while (i < j){
            while (j >= f + 1 && B[j][0] >= x) j--;  // 顺序颠倒会引发 heap-buffer-overflow！！ 
            while (i <= l && B[i][0] <= x) i++;
            if (i < j){
                vector<int> temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
        if (B[f] > B[j]){
            vector<int> temp = B[f];
            B[f] = B[j];
            B[j] = temp;
        }
        if (f < j-1) QuickSort(B, f, j-1);
        if (j+1 < l) QuickSort(B, j+1, l);
    }
};
