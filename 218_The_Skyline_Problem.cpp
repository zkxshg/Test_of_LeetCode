// https://leetcode.com/problems/the-skyline-problem
// divide and conquer
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        
        int num = buildings.size(); 
        if (num < 1) return result;
        
        vector<vector<int>> unionSet;
        unionSet.push_back(buildings[0]);
        
        for (int i = 1; i < num; i++) {
            int pos = 0;
            while (pos < unionSet.size()) {
                
                if (buildings[i][0] >= unionSet[pos][1]) pos++;
                else if (buildings[i][1] <= unionSet[pos][1]) {
                    
                    if (buildings[i][2] > unionSet[pos][2]) {
                        vector<int> newBuild(3); 
                        newBuild[0] = buildings[i][1];
                        newBuild[1] = unionSet[pos][1];
                        newBuild[2] = unionSet[pos][2];
                        
                        if (newBuild[0] < newBuild[1]) unionSet.insert(unionSet.begin() + pos + 1, newBuild);
                        unionSet.insert(unionSet.begin() + pos + 1,buildings[i]);
                        
                        unionSet[pos][1] = buildings[i][0]; 
                        if (unionSet[pos][1] == unionSet[pos][0]) unionSet.erase(unionSet.begin() + pos);
                    }
                    break;
                }
                else {
                    
                    if (buildings[i][2] <= unionSet[pos][2]) buildings[i][0] = unionSet[pos][1];
                    else {
                        vector<int> newBuild(3); 
                        newBuild[0] = buildings[i][0];
                        newBuild[1] = unionSet[pos][1];
                        newBuild[2] = buildings[i][2];
                        
                        int temp = unionSet[pos][1];
                        unionSet[pos][1] = buildings[i][0];
                        buildings[i][0] = temp;
                        
                        if (newBuild[0] < newBuild[1]) unionSet.insert(unionSet.begin() + pos + 1, newBuild);
                        
                        if (unionSet[pos][1] == unionSet[pos][0]) unionSet.erase(unionSet.begin() + pos);

                        if (buildings[i][0] == buildings[i][1]) break;
                    }
                    
                    pos++;
                }
                
                if (pos == unionSet.size()) unionSet.push_back(buildings[i]);
            }   
        }
        
        int len = unionSet.size();
        result.push_back({unionSet[0][0], unionSet[0][2]});

        for (int i = 1; i < len; i++) {
            if (unionSet[i][0] > unionSet[i - 1][1]) result.push_back({unionSet[i - 1][1], 0});
            if (unionSet[i][2] != unionSet[i - 1][2]) result.push_back({unionSet[i][0], unionSet[i][2]});
        }
        result.push_back({unionSet[len - 1][1], 0});
        
        return result;
    }
};
