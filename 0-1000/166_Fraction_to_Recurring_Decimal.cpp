// https://leetcode.com/problems/fraction-to-recurring-decimal/
// hash table

class Solution {
public:
    #define ll long long 
    
    string fractionToDecimal(int numerator, int denominator) {
        ll num = numerator;
        ll den = denominator;
        if (!num) return "0";

        unordered_map<int, int> loop; unordered_map<int, int> loopDen;
        bool decP = false, repet = false;;
        string preP = ""; string sucP = "";
        
        bool neg = false;
        if (num < 0 && den < 0) {
            num = -num; den = -den;
        }
        else if(num < 0) {
            neg = true; num = -num;
        }
        else if (den < 0) {
            neg = true; den = -den;
        }
        //cout << num / den << endl;
        int repetPos = 0, counter = 1; ll div = 0; string repStr = "";
        while (num) {
            if (num < den) {
                div = 0;
                if (!decP) {
                    preP += "0."; decP = true;
                }
                else sucP += "0";     
            }
            else {
                div = num / den;
                // cout << div << endl;
                num %= den;
                
                if (!decP) {
                    preP += to_string(div); 
                    if (num) {
                        preP += '.'; decP = true;
                    }
                }
                else sucP += to_string(div);   
            }
            
            if (decP && !sucP.empty() && loop[num] && loopDen[loop[num]] == div) {
                repet = true;
                //cout << counter << " = " << num << endl;
                int len = sucP.size(), loopLen = counter - loop[num];
                //cout << "len = " << len << ", loopLen = " << loopLen << endl;
                repStr = sucP.substr(len - loopLen - 1, loopLen);
                repetPos = len - loopLen - 1;
                
                break;
            }
            // cout << num << endl;
            
            if (decP && !sucP.empty()) {
                loop[num] = counter; // cout << num << "=" << counter << endl;
                loopDen[counter] = div;
                counter++; 
            }
            num *= 10;
            
            //if (sucP.size() > 20) break;
        }
        
        string res = "";
        if (!decP) res = preP;
        else if (!repet) res = preP + sucP;
        else res = preP + sucP.substr(0, repetPos) + '(' + repStr + ')';
        
        if (neg) return "-" + res;
        return res;
    }
};
