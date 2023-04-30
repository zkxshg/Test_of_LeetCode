// https://leetcode.com/problems/find-k-closest-elements/
// sort
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        vector<pair<int, int> > sarr;
        for (int i : arr) sarr.push_back(make_pair(abs(i - x), (i > x) ) );
        sort(sarr.begin(), sarr.end());
        
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(-sarr[i].first * pow(-1, sarr[i].second) + x);
        sort(res.begin(), res.end());
        
        return res;
        
    }
};

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

// Demo
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {1,2,5,5,6,6,7,7,8,9};

    int k = 7;
    int x = 7;
    int len = arr.size();

        vector<int> subs(len);
        for (int i = 0; i < len; i++) subs[i] = abs(x - arr[i]);

        int mini = 0;
        while (mini + 1 <len && subs[mini] >= subs[mini+1]) mini += 1;

        if (mini == 0) {
            vector<int> res(arr.begin(), arr.begin()+k);
        }
        else if (mini == len - 1){
            vector<int> res(arr.end()-k, arr.end());
        }

        cout << "arr[mini] = " << arr[mini] << " and mini = " << mini << endl;

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
        for (int i = 0; i < res.size(); i++) cout << res[i] << ", ";
    return 0;
}
