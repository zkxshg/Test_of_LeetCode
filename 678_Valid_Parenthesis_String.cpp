class Solution {
public:
    bool checkValidString(string s) {
        if (s.size() == 0) return true;
        if (s.size() == 1){
            if (s[0] == '*') return true;
            else return false;
        }
        
        vector<char> stac;
        int couleft = 0;
        vector<int> leftPos;
        // scan s with [*,(,)]
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') {
                stac.push_back(s[i]);
                leftPos.push_back(stac.size() - 1);
                couleft++;
            }
            else if (s[i] == '*') stac.push_back(s[i]);
            else { 
                if (stac.size() == 0) return false;
                else if (stac.back() == '(') {
                    stac.pop_back();
                    leftPos.pop_back();
                    couleft--;
                }
                else {
                    if (couleft == 0) stac.pop_back();
                    else {
                        stac.erase(stac.begin() + leftPos.back());
                        leftPos.pop_back();
                        couleft--;
                    }
                }
            }
        }
        
        if (stac.size() == 0 || couleft == 0) return true;
        if (stac.back() == '(') return false;
        
        // second scan stac with [*,(]
        couleft = 0;
        for (int i = 0; i < stac.size(); i++){
            if (stac[i] == '(') couleft++;
            else if (couleft > 0) couleft--;
        }
        
        if (couleft > 0) return false;
        
        return true;
    }
};
