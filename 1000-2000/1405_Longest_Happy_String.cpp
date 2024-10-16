// https://leetcode.com/problems/longest-happy-string/?envType=daily-question&envId=2024-10-16
// heap

class Solution {
public:
    #define pii pair<int, int>
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pii> pq;
        if (a > 0) pq.push({a, 0}); 
        if (b > 0) pq.push({b, 1}); 
        if (c > 0) pq.push({c, 2});

        while (!pq.empty()) {
            // cout << pq.size() << endl;

            if (pq.size() == 1) {
                if (!res.empty() && res.back() == pq.top().second + 'a') res += res.back();
                else {
                    res += pq.top().second + 'a';
                    if (pq.top().first > 1) res += pq.top().second + 'a';
                }
                break;
            }

            pii fst = pq.top(); pq.pop();
            pii scd = pq.top(); pq.pop();
            
            int num1 = fst.first, num2 = scd.first;
            char ch1 = 'a' + fst.second, ch2 = 'a' + scd.second;
      
            if (!res.empty() && res.back() == ch1) {
                res += ch1; num1--;
                res += ch2; num2--;
            }
            else {
                res += ch1;
                if (num1 > 1) res += ch1;
                num1 -= 2;

                res += ch2; num2--;
            }

            if (num1 > 0) pq.push({num1, fst.second});
            if (num2 > 0) pq.push({num2, scd.second});
        }

        return res;
    }
};
