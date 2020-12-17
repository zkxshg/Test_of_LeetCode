// divide-and-conquer: O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size(); if (len < 1) return 0;
            
        
        unordered_map<int, int> abDict;
        for (int a : A) {
            for (int b : B) abDict[a + b]++;
        }
        
        unordered_map<int, int> cdDict;
        for (int c : C) {
            for (int d : D) cdDict[c + d]++;
        }
        
        int res = 0;
        for (auto& v : abDict) res += v.second * cdDict[-v.first];
        
        return res;
    }
};

// hash map: O(n^3)
class Solution {
public:
    int res;
    unordered_map<int, int> Ddict;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size(); if (len < 1) return 0;
    
        res = 0;
        Ddict.clear();
        for (int d : D) Ddict[d]++;
        
        for (int a : A) Bcout(0 - a, B, C, D);
        return res;
    }
    
    void Bcout(int aim, vector<int>& B, vector<int>& C, vector<int>& D) {
        for (int b :B) Ccout(aim - b, C, D);
    }
    
    void Ccout(int aim, vector<int>& C, vector<int>& D) {
        for (int c : C) Dcout(aim - c, D);
    }
    
    void Dcout(int aim, vector<int>& D) {
        res += Ddict[aim];
    }
};
