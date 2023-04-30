// https://leetcode.com/problems/jump-game-iii/
// BFS + hash map
class Solution {
public:
    unordered_map<int, int> posRec;
    unordered_map<int, set<int>> path;
    
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size(); if (len == 1) return true;
        
        if (arr[start] == 0) return true;
        
        path.clear();
        for (int i = 0; i < len; i++) {
            if (i - arr[i] >= 0)  path[i - arr[i]].insert(i);
            if (i + arr[i] < len) path[i + arr[i]].insert(i);
        }
        
        vector<int> zeroPos;
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0) zeroPos.push_back(i);
        }
        
        for (int zero : zeroPos) {
            posRec.clear();
            if (ifReach(zero, arr, start)) return true;
        }
        
        return false;
    }
    
    bool ifReach(int pos, vector<int>& arr, int start) {
        int len = arr.size();
        
        vector<int> nextPos;
        
        for (auto& s : path[pos]) {
            if (s == start) return true;
            
            if (!posRec[s]) {
                posRec[s]++;
                if (ifReach(s, arr, start)) return true;
            }
        }
    
        return false;
    }   
};

// BFS
class Solution {
public:
    unordered_map<int, int> posRec;
    
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size(); if (len == 1) return true;
        
        if (arr[start] == 0) return true;
        
        vector<int> zeroPos;
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0) zeroPos.push_back(i);
        }
        
        for (int zero : zeroPos) {
            posRec.clear();
            if (ifReach(zero, arr, start)) return true;
        }
        
        return false;
    }
    
    bool ifReach(int pos, vector<int>& arr, int start) {
        int len = arr.size();
        
        vector<int> nextPos;
        
        int left = 1;
        while (pos - left >= 0) {
            if (arr[pos - left] == left) {
                if (posRec[pos - left] < 2) {
                    nextPos.push_back(pos - left);
                    posRec[pos - left]++;
                }
                if (start == pos - left) return true;
            }
            left++;
        }
        
        int right = 1;
        while (pos + right < len) {
            if (arr[pos + right] == right) {
                if (posRec[pos + right] < 2) {
                    nextPos.push_back(pos + right);
                    posRec[pos + right]++;
                }
                if (start == pos + right) return true;
            } 
            right++;
        }
        
        for (int aim : nextPos) {
            if (start == aim) return true;
            if (ifReach(aim, arr, start)) return true;
        }
    
        return false;
    }
};
