// sort + greedy
class Solution {
public:
    
    static int cmp(vector<int> a, vector<int> b) {
        return (a[0] == b[0]) ? (a[1] >= b[1] ? 1 : 0) : (a[0] < b[0] ? 1 : 0);
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        if (len < 2) return people;
        
        sort(people.begin(), people.end(), cmp);
        
        vector<vector<int>> result(len, vector<int>(2, -1));
        vector<int> index;
        for (int i = 0; i < len; i++) index.push_back(i);
        
        for (int i = 0; i < len; i++) {
            int pos = people[i][1];
            result[index[pos]] = people[i];
            index.erase(index.begin() + pos);
        }
        return result;
    } 
};
