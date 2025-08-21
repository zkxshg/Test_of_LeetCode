// stack
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string res = "";
        int len = S.size(); if (K == 1) return res + S[0];
        
        vector<char> st; st.push_back(S[0]);
        vector<long> stLen; stLen.push_back(1);
        
        for (int i = 1; i < len; i++) {
            char ch = S[i];
            st.push_back(ch);
            
            if (ch >= 'a' && ch <= 'z') stLen.push_back(stLen[i - 1] + 1);
            else stLen.push_back(stLen[i - 1] * (ch - '0'));
            
            if (stLen[i] >= K) break;
        }
        
        while (isdigit(st.back()) || stLen.back() > K) {
            if (isdigit(st.back())) {
                if (K > stLen[st.size() - 2]) K -= stLen[st.size() - 2];

                if (st.back() == '2') {
                    st.pop_back();
                    stLen.pop_back();
                }
                else {
                    st.back()--;
                    stLen.back() -= stLen[st.size() - 2];
                }
            }
            else {
                if (stLen.back() == K) return res + st.back();
                st.pop_back();
                stLen.pop_back();
            }
        }
        
        return res + st.back();
    }
};
