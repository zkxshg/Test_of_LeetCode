// two pointers
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int pos = 0, num = 1, len = arr.size();
        while (k > 0) {
            if (pos >= len) {
                k--; if (k == 0) return num;
                num++; 
            }
            else {
                if (arr[pos] == num) {
                    num++; pos++;
                }
                else {
                    k--; if (k == 0) return num;
                    num++; 
                }
            }
        }
        return num;
        
    }
};
