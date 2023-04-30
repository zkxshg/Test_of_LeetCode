// stack + hash map
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size(); if (len < 2) return true;
        
        unordered_map<int, int> opens; opens[0] = 1;
        
        stack<int> st; 
        for (int i : rooms[0]) st.push(i);
        
        int left = len - 1;
        while(!st.empty()) {
            int n = st.top();
            if (opens[n]) st.pop();
            else {
                st.pop();
                opens[n] = 1; left--;
                for (int i : rooms[n]) {
                    if (!opens[i]) st.push(i);
                }
            }
        }
        return left == 0;
    }
};
