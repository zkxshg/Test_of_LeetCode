// Calculate subs = abs(arr-x) -> compare by subs
#include <cmath>
#include <algorithm>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        if (k >= len) return arr;
        
        vector<int> subs(len);
        for (int i = 0; i < len; i++) subs[i] = abs(x - arr[i]);
        
        int mini = 0;
        while (mini + 1 <len && subs[mini] >= subs[mini+1]) mini += 1;
        
        if (mini == 0) {
            vector<int> res(arr.begin(), arr.begin()+k);
            return res;
        }
        else if (mini == len - 1){
            vector<int> res(arr.end()-k, arr.end());
            return res;
        }
        
        int counter = k-1;
        vector<int> res;
        res.push_back(arr[mini]);
                      
        int left = mini-1;
        int right = mini+1;
        while (counter > 0){
            if (left < 0) {
                for(int i = 0; i < counter; i++) res.push_back(arr[right+i]);
                break;
            }
            else if (right >= len) {
                for(int i = 0; i < counter; i++) res.push_back(arr[left-i]);
                break;
            }
            if (subs[left] <= subs[right]) {
                res.push_back(arr[left]);
                left--;
                counter--;
            }
            else {
                res.push_back(arr[right]);
                right++;
                counter--;
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
