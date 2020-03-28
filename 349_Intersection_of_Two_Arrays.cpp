// loop
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) return result;
        for (int i = 0; i < nums1.size(); i++){
            for (int j = 0; j < nums2.size(); j++){
                if (nums1[i] == nums2[j]) findVec(result, nums1[i]);
            }
        }
        return result;
    }
    
    
    void findVec(vector<int> & res, int aim){
        bool findAim = false;
        for (int i = 0; i < res.size(); i++){
            if (res[i] == aim) {
                findAim = true;
                break;
            }
        }
        if (!findAim) res.push_back(aim);
    }
};

// DP
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) return result;
        DP(nums1, nums2, nums1.size() - 1, nums2.size() - 1, result);
        return result;
    }
    
    void DP(vector<int>& n1, vector<int>& n2, int n1e, int n2e, vector<int> & res){
        if (n1e >= 0 && n2e >= 0){
            if (n1[n1e] == n2[n2e]){
                findVec(res, n1[n1e]);
                DP(n1, n2, n1e - 1, n2e - 1, res);
            }
            else {
                DP(n1, n2, n1e, n2e - 1, res);
                DP(n1, n2, n1e - 1, n2e, res);
            }
        }
    }
    
    void findVec(vector<int> & res, int aim){
        bool findAim = false;
        for (int i = 0; i < res.size(); i++){
            if (res[i] == aim) {
                findAim = true;
                break;
            }
            
        }
        if (!findAim) res.push_back(aim);
    }
};
