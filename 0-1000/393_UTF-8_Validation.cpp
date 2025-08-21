// https://leetcode.com/problems/utf-8-validation/
// Bit Maniputation

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        
        vector<string> dataB(n);
        for (int i = 0; i < n; i++) dataB[i] = (bitset<8> (data[i])).to_string();
        // for (int i = 0; i < n; i++) cout << dataB[i] << ","; cout << endl;
        
        int pos = 0;
        while (pos < n) {
            string& s = dataB[pos];
            // cout << pos << ":" << s << endl;
            
            if (s[0] == '0') pos++; // 1B
            else if (s.substr(0, 3) == "110") { // 2B
                if (pos + 1 >= n || dataB[pos + 1].substr(0, 2) != "10") return false;
                pos += 2;
            }
            else if (s.substr(0, 4) == "1110") { // 3B
                if (pos + 2 >= n) return false;
                else if (dataB[pos + 1].substr(0, 2) != "10" || 
                         dataB[pos + 2].substr(0, 2) != "10")
                    return false;
                pos += 3;
            }
            else if (s.substr(0, 5) == "11110") { // 4B
                if (pos + 3 >= n) return false;
                else if (dataB[pos + 1].substr(0, 2) != "10" || 
                         dataB[pos + 2].substr(0, 2) != "10" ||
                         dataB[pos + 3].substr(0, 2) != "10" )
                    return false;
                
                pos += 4;
            }
            else return false;
        }
        
        
        return true;
    }
};
