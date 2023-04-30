// https://leetcode.com/problems/apply-discount-to-prices/
// string

class Solution {
public:
    string d2str(double d) {
        string res = "";
        string dstr = to_string(d);
        int n = dstr.size(), decPos = 0;
        bool dec = false;
        for (int i = 0; i < n; i++) {
            res += dstr[i];
            
            if (dstr[i] == '.') {
                if (i + 1 < n) res += dstr[i + 1];
                else res += '0';
                
                if (i + 2 < n) res += dstr[i + 2];
                else res += '0';
                
                dec = true; decPos = i; break;
            }
        }
        
        if (!dec) res += ".00";
        else {
            bool carry = false; int i = res.size() - 3;
                
            if (decPos + 3 < n && dstr[decPos + 3] >= '5') {
                if (res[i + 2] < '9') res[i + 2]++;
                else {
                    res[i + 2] = '0'; carry = true;
                }
            }
            if (carry) {
                if (res[i + 1] < '9') res[i + 1]++;
                else {
                    res[i + 1] = '0';

                    int pos = i - 1; 
                    
                    while (pos >= 0) {
                        if (res[pos] < '9') {
                            res[pos]++; carry = false; break;
                        }
                        else res[pos] = '0';
                        pos--;
                    }

                    if ((pos < 0) && carry) res = "1" + res; 
                }
            }
        }
    
        return res;
    }
    
    string discountPrices(string sentence, int discount) {
        int n = sentence.size(), pos = 0;
        vector<double> prices;
        
        // Get prices
        unordered_map<int, int> ppos;
        while (pos < n) {
            if (sentence[pos] == '$' && pos + 1 < n 
                && sentence[pos + 1] > '0' && sentence[pos + 1] <= '9') {
                int en = pos + 1; double p = 0.0;
                
                while (en < n && sentence[en] >= '0' && sentence[en] <= '9') {
                    p = p * 10 + sentence[en] - '0'; en++;
                }
                    
                
                if (en >= n || sentence[en] == ' ') {
                    ppos[pos]++; prices.push_back(p * (100 - discount) / 100);
                }
                else {
                    while (en < n && sentence[en] != ' ') en++;
                }
                
                pos = en + 1;
            }
            else {
                while (pos < n && sentence[pos] != ' ') pos++;
                pos++;
            }
        }
        
        // for (auto& d : prices) cout << d << ","; cout << endl;
        reverse(prices.begin(), prices.end());
        
        // New string
        pos = 0; string res = "";
        while (pos < n) {
            res += sentence[pos];
            
            if (sentence[pos] == '$' && ppos[pos]) {
                string price = d2str(prices.back()); prices.pop_back();
                res += price; // cout << price << endl;
                
                while (pos < n && sentence[pos] != ' ') pos++;
                
                if (pos < n) res += sentence[pos];
            }
            
            pos++;
        }
        
        return res;
    }
};
