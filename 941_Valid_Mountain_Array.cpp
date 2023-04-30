// array
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size(); if (len < 3) return false;
        if (arr[0] >= arr[1] || arr[len - 1] >= arr[len - 2]) return false;
        
        int pos = 0;
        bool up = true;
        while (pos < len - 1) {
            if (arr[pos] == arr[pos + 1]) return false;
            else if (arr[pos] < arr[pos + 1]) {
                if (!up) return false; 
            }
            else {
                if (up) up = false;
            } 
            pos++;
        }
        return true;
    }
};
