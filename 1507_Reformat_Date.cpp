// https://leetcode.com/problems/reformat-date/
// string

class Solution {
public:
    string reformatDate(string date) {
        string days, mons, yeas;
        
        int pos = 0, nex, n = date.size();
        while (date[pos] != ' ') pos++; days = date.substr(0, pos); nex = pos + 1;
        while (date[nex] != ' ') nex++; mons = date.substr(pos + 1, nex - pos - 1);
        yeas = date.substr(nex + 1);
        
        //cout << days << "-" << mons << "-" << yeas << endl;
        
        while(days.back() < '0' || days.back() > '9') days.pop_back();
        
        unordered_map<string, int> s2i;
        vector<string> ms = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int cou = 1;
        for (auto& s : ms) {s2i[s] = cou; cou++;}
        
        mons = to_string(s2i[mons]); 
        
        if (mons.size() < 2) mons = "0" + mons;
        if (days.size() < 2) days = "0" + days;
        
        string res = yeas + "-" + mons + "-" + days;
        
        return res;
    }
};
