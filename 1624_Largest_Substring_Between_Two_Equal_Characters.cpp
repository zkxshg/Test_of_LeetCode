// hash map
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = s.size(); 
        if (len < 2) return -1;
        
        unordered_map<char, int> pre_dict;
        unordered_map<char, int> last_dict;
        for (int i = 0; i < len; i++) {
            char ch = s[i];
            if (pre_dict.count(ch) == 0) {
                pre_dict[ch] = i;
                last_dict[ch] = i;
            } else last_dict[ch] = i;
        }
        
        int result = -1;
        for (auto& v : pre_dict) {
            int dis = last_dict[v.first] - pre_dict[v.first] - 1;
            if (dis > result) result = dis;
        }
        return result;
    }
};
