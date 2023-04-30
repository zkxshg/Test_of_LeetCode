// greedy + stack
class Solution {
public:
    
    string smallestSubsequence(string text) {
        
        vector<bool> seen(26, false);
        vector<int> freq(26, 0);

        for(char ch : text)
            freq[ch - 'a']++;

        stack<char> st;

        for(int i=0; i<text.size(); i++){
            char ch = text[i];

            freq[ch - 'a']--;
            if(seen[ch - 'a'])
                continue;

            while(st.size() != 0 && st.top() > ch && freq[st.top() - 'a'] > 0){
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            seen[ch - 'a'] = true;
            st.push(ch);
        }

        string ans = "";
        while(st.size() != 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// linear scan
class Solution {
public:
    
    string minSub(string s, char ch, int fre) {
        vector<string> subs(fre, "");
        int order = 0;
        for (char chs : s) {
            if (chs == ch) {
                subs[order] += chs;
                order++;
            }
            else {
                for (int i = 0; i < fre; i++) subs[i] += chs;
            }
        } 
        string minStr = subs[0];
        for (string str : subs) {
            if (str < minStr) minStr = str;
        }
        return minStr;   
    }
    
    string smallestSubsequence(string s) {
        int len = s.size();
        if (len < 2) return s;
        unordered_map<char, int> chDict;
        for (char ch : s) chDict[ch] = 0;
        for (char ch : s) chDict[ch]++;

        for (char ch = 'z'; ch >='a'; ch--) {
            if (chDict[ch] > 1) {
                s = minSub(s, ch, chDict[ch]);
                chDict[ch] = 1;  
            }
        }
        return s;
    }
};

// bit-mask
class Solution {
public:
    
    bool check(string s, int kind) {
        unordered_map<char, int> chDict;
        for (char ch : s) chDict[ch] = 0;
        
        int temKind = 0;
        for (char ch : s) {
            chDict[ch]++;
            if (chDict[ch] > 1) return false;
            if (chDict[ch] == 1) temKind++;
        }
        
        if (temKind == kind) return true;
        return false;
    }
    
    string smallestSubsequence(string s) {
        int len = s.size();
        if (len < 2) return s;
        
        unordered_map<char, int> chDict;
        for (char ch : s) chDict[ch] = 0;
        
        int kind = 0;
        for (char ch : s) {
            chDict[ch]++;
            if (chDict[ch] == 1) kind++;
        }
        
        string minStr = "";
        for (int i = 0; i < len; i++) minStr += 'z';
        
        long long totalNum = pow(2, len);
        
        for (int i = 0; i < totalNum; i++) {
            bitset<32> bits(i);
            
            string str = "";
            for (int j = 0; j < len; j++) {
                if (bits[j]) str += s[j];
            }
            if (str.size() != kind) continue;
            if (check(str, kind) && str < minStr) minStr = str;
        }
        return minStr;
    }
};
