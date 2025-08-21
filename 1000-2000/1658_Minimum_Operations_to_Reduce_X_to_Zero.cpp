// hash map
class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
    unordered_map<int, int> left;
    int res = INT_MAX;
    for (auto l = 0, sum = 0; l < nums.size() && sum <= x; ++l) {
        left[sum] = l;
        sum += nums[l];
    }
    for (int r = nums.size() - 1, sum = 0; r >= 0 && sum <= x; --r) {
        auto it = left.find(x - sum);
        if (it != end(left) && r + 1 >= it->second) {
            res = min(res, (int)nums.size() - r - 1 + it->second);
        }
        sum += nums[r];
    }
    return res == INT_MAX ? -1 : res;
}
};

// recursive
class Solution {
public:
    vector<int> solLen;
    map<pair<int, int>, int> posDict;
    
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size(); if (len < 2) return (nums[0] == x);
        
        if (x == 0) return 0;
        if (nums[0] == x || nums.back() == x) return 1;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == x) return len;
        
        int leftSol = -1, rightSol = -1;
        if (sum + nums[0] <= x) {
            vector<int> n1(nums.begin() + 1, nums.end());
            int sol1 = minOperations(n1, x - nums[0]);
            if (sol1 >= 0) leftSol = sol1 + 1;
        }
        if (sum + nums.back() <= x) {
            vector<int> n2(nums.begin(), nums.end() - 1);
            int sol2 = minOperations(n2, x - nums.back());
            if (sol2 >= 0) rightSol = sol2 + 1;
        }
        
        
        if (leftSol < 0) return rightSol;
        if (rightSol < 0) return leftSol;
        
        return min(rightSol, leftSol);   
    }
};

// prune and search

class Solution {
public:
    vector<int> solLen;
    map<pair<int, int>, int> posDict;
    
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size(); if (len < 2) return (nums[0] == x);
        if (accumulate(nums.begin(), nums.end(), 0) == x) return len;
        
        solLen.clear();
        posDict.clear();
        
        int lPos = 0, rPos = len - 1;
        
        vector<int> accu;
        search(nums, x, accu, lPos, rPos, true);
        search(nums, x, accu, lPos, rPos, false);
        
        if (solLen.size() < 1) return -1;
        return *min_element(solLen.begin(), solLen.end());   
    }
    
    void search(vector<int>& nums, int x, vector<int> accu, int lPos, int rPos, bool scanLeft) {
        if (solLen.size() > 0) {
            int tempSol = *min_element(solLen.begin(), solLen.end());
            if (accu.size() >= tempSol) return;
        }
        
        if (scanLeft) {
            accu.push_back(nums[lPos]);
            lPos++;
            posDict[make_pair(lPos, rPos)] = 1; 
        } else {
            accu.push_back(nums[rPos]);
            rPos--;
            posDict[make_pair(lPos, rPos)] = 1; 
        }
        
        int sum = accumulate(accu.begin(), accu.end(), 0);
        
        if (sum == x) solLen.push_back(accu.size());
        else if (sum < x && lPos <= rPos) {
            if (lPos == rPos) {
                if (posDict.count(make_pair(lPos + 1, rPos)) == 0 && posDict.count(make_pair(lPos, rPos - 1)) == 0) 
                    search(nums, x, accu, lPos, rPos, true);
            }
            else {
                if (posDict.count(make_pair(lPos + 1, rPos)) == 0) search(nums, x, accu, lPos, rPos, true);
                if (posDict.count(make_pair(lPos, rPos - 1)) == 0) search(nums, x, accu, lPos, rPos, false);
            }
        }
    }
};
