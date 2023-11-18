// https://leetcode.com/problems/last-stone-weight/
// sort
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        QuickSort(stones, 0, stones.size() - 1);
        while (stones.size() > 1){
            int temp = stones.back() - stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            if (temp > 0){
                stones.push_back(temp);
                QuickSort(stones, 0, stones.size() - 1);
            }
        }
        if (stones.size() > 0) return stones[0];
        return 0;
    }
 
 // QuickSort
    void QuickSort(vector<int>& B, int f, int l){
        int x = B[f], i = f + 1, j = l;
        while (i < j){
            while (j >= f + 1 && B[j] >= x) j--;
            while (i <= l && B[i] <= x) i++;
            if (i < j){
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
        if (B[f] > B[j]){
            B[f] = B[j];
            B[j] = x;
        }
        if (f < j-1) QuickSort(B, f, j-1);
        if (j+1 < l) QuickSort(B, j+1, l);
    }
    
};
