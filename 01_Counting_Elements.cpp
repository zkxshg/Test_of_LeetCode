class Solution {
public:
    int countElements(vector<int>& arr) {
        if (arr.size() == 1) return 0;
        vector<int> rec(1002, 0);
        vector<int> recplus(1001, 0);
        for (int i = 0; i < arr.size(); i++) rec[arr[i]+1]++;
        for (int i = 0; i < arr.size(); i++) {
            if (rec[arr[i]] > recplus[arr[i]]) recplus[arr[i]] = rec[arr[i]];
        }
        int result = 0;
        for (int i = 0; i < recplus.size(); i++) result += recplus[i];
        return result;
    }
};
