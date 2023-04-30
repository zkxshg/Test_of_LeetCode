// https://leetcode.com/problems/reconstruct-original-digits-from-english/
// char map
class Solution {
public:
    string originalDigits(string s) {
        if (s.size() < 1) return "";
        
        unordered_map<char, int> dict;
        for (char c : s) dict[c]++;
        
        int fre = 0;
        vector<int> intRes;
        
        // z -> zero  
        if (dict['z'] > 0) {
            fre = dict['z'];
            addInt(intRes, fre, 0);
            dict['z'] -= fre; dict['e'] -= fre; dict['r'] -= fre; dict['o'] -= fre; 
        }
        // w -> two
        if (dict['w'] > 0) {
            fre = dict['w'];
            addInt(intRes, fre, 2);
            dict['t'] -= fre; dict['w'] -= fre; dict['o'] -= fre; 
        }
        // g -> eight
        if (dict['g'] > 0) {
            fre = dict['g'];
            addInt(intRes, fre, 8);
            dict['e'] -= fre; dict['i'] -= fre; dict['g'] -= fre; dict['h'] -= fre; dict['t'] -= fre; 
        }
        // x -> six
        if (dict['x'] > 0) {
            fre = dict['x'];
            addInt(intRes, fre, 6);
            dict['s'] -= fre; dict['i'] -= fre; dict['x'] -= fre;
        }
        // s -> seven
        if (dict['s'] > 0) {
            fre = dict['s'];
            addInt(intRes, fre, 7);
            dict['s'] -= fre; dict['e'] -= 2 * fre; dict['v'] -= fre; dict['n'] -= fre; 
        }
        // v -> five
        if (dict['v'] > 0) {
            fre = dict['v'];
            addInt(intRes, fre, 5);
            dict['f'] -= fre; dict['i'] -= fre; dict['v'] -= fre; dict['e'] -= fre; 
        }
        // f -> four
        if (dict['f'] > 0) {
            fre = dict['f'];
            addInt(intRes, fre, 4);
            dict['f'] -= fre; dict['o'] -= fre; dict['u'] -= fre; dict['r'] -= fre; 
        }
        // o -> one
        if (dict['o'] > 0) {
            fre = dict['o'];
            addInt(intRes, fre, 1);
            dict['o'] -= fre; dict['n'] -= fre; dict['e'] -= fre;
        }
        // t -> three
        if (dict['t'] > 0) {
            fre = dict['t'];
            addInt(intRes, fre, 3);
            dict['t'] -= fre; dict['h'] -= fre; dict['r'] -= fre; dict['e'] -= 2 * fre; 
        }
        // e -> nine
        if (dict['e'] > 0) {
            fre = dict['e'];
            addInt(intRes, fre, 9);
            dict['n'] -= 2 * fre; dict['i'] -= fre; dict['e'] -= fre;
        }
        
        sort(intRes.begin(), intRes.end());
        
        string res = "";
        for (int i : intRes) res += to_string(i);
        
        return res;
    }
    
    void addInt(vector<int>& v, int fre, int aim) {
        for (int i = 0; i < fre; i++) v.push_back(aim);
    }
};
