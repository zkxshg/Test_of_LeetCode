// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// sort by numof1 -> sort in same numof1
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        if (arr.size() == 0 || arr.size() == 1) return arr;
        vector<int> numof1(arr.size());
        for (int i = 0; i < arr.size(); i++) numof1[i] = bitset<sizeof(arr[i])*8>(arr[i]).count();
        QuickSort(numof1, 0, arr.size()-1, arr);
        
        int pos = 0;
        int counter = 0;
        for (int i = 0; i < numof1[numof1.size()-1] + 1; i++){
            counter = 0;
            while(pos+counter < arr.size() && numof1[pos+counter] == i) counter++;
            if (counter > 1) QuickSort(arr, pos, pos+counter-1);
            pos = pos + counter;
        }
        return arr;
    }
    
// ================= sort algorithm ===============================
    void QuickSort(vector<int>& B, int f, int l,vector<int>& num){
        int x = B[f];
        int i = f + 1;
        int j = l;
        int temp = 0;
        while (i < j){
            while (j >= f + 1 && B[j] >= x) j--;  // 顺序颠倒会引发 heap-buffer-overflow！！ 
            while (i <= l && B[i] <= x) i++;
            if (i < j){
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        if (B[f] > B[j]){
            B[f] = B[j];
            B[j] = x;
            temp = num[f];
            num[f] = num[j];
            num[j] = temp;
        }
        if (f < j-1) QuickSort(B, f, j-1, num);
        if (j+1 < l) QuickSort(B, j+1, l, num);
    }
    
    void QuickSort(vector<int>& B, int f, int l){
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
