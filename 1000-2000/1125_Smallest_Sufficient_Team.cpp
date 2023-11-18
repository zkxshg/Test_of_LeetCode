// https://leetcode.com/problems/smallest-sufficient-team/
// DP + hash table

class Solution {
public:
    int sl, pl;
    unordered_map<string, int> sk;
    vector<int> res;
    unordered_map<int, set<int> > s2p;
    
    void recur(vector<int> inc, vector<int> tRes, vector<vector<string>>& people, int aim) {
        if (aim >= sl) {
            // for (int i : res) cout << i << ","; cout << endl;
            if (tRes.size() < res.size()) res = tRes;
            return;
        }
        
        for (auto &s : s2p[aim]) {
            vector<int> ninc = inc;
            vector<int> ttRes = tRes;
            int taim = aim;
            
            
            ttRes.push_back(s);
            if (ttRes.size() >= res.size()) continue;
            
            for (auto& str : people[s]) ninc[sk[str]] = 1;
            
            // for (int i : ninc) cout << i << ","; cout << endl;
            // for (int i : ttRes) cout << i << ","; cout << endl; cout << endl;
            
            while(taim < sl && ninc[taim]) taim++;
            
            recur(ninc, ttRes, people, taim);
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        sl = req_skills.size(); 
        pl = people.size();
        
        // string to int
        for (int i = 0; i < sl; i++) sk[req_skills[i]] = i;
        
        // maxLen result
        res.clear();
        for (int i = 0; i < pl; i++) res.push_back(i);
        
        // reverse p2s to s2p
        for (int i = 0; i < pl; i++) 
            for (auto& str : people[i]) 
                s2p[sk[str]].insert(i);
        
        vector<int> inc(sl);
        vector<int> tRes;
        
        recur(inc, tRes, people, 0);
        
        return res;
        
    }
};
