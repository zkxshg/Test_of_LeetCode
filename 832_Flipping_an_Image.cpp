// array
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        
        int pos = n / 2;
        for(int j = 0; j < m; j++) {
            vector<int>& arr = A[j];
            for (int i = 0; i < pos; i++) {
                int temp = arr[i];
                arr[i] = arr[n - 1 - i];
                arr[n - 1 - i] = temp;
            }
            
            for (int i = 0; i < n; i++) arr[i] = 1 - arr[i];
        }   
        return A;
    }
};
