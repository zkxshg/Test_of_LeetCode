// greedy
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size(); if (len < 2 || k == 0) return 0;
        
        // differ for profit
        vector<int> profit(len - 1);
        for (int i = len - 1; i > 0; i--) profit[i - 1] = prices[i] - prices[i-1];
        len--;
        
        // cal first maxPro
        vector<int> res = maxProf(profit); if (k == 1) return res[0];
        k--;
        
        // store the existing maxPro interval
        vector<pair<int, int>> proIn; proIn.push_back(make_pair(res[1], res[2]));
        
        // store the left interval
        vector<pair<int, int>> leftIn;
        if (res[1] > 0) leftIn.push_back(make_pair(0, res[1] - 1)); 
        if (res[2] < len - 1) leftIn.push_back(make_pair(res[2] + 1, len - 1));
        
        int sum = res[0];
        while (k > 0) {
            // if cut the existing maxPro intervals
            int cutPro = -1, cutSt = -1, cutEnd = -1, cutPos = -1;
            for (int i = 0; i < proIn.size(); i++) {
                pair<int, int> pa = proIn[i];
                
                if (pa.first == pa.second) continue;
                else {
                    // cut the interval
                    vector<int> temPro(profit.begin() + pa.first, profit.begin() + pa.second + 1);
                    vector<int> cutP = cutProf(temPro);
                    // save the profit and positions
                    if (cutP[0] <= 0) continue;
                    if (cutP[0] > cutPro) {
                        cutPro = cutP[0];  cutPos = i;
                        cutSt = pa.first + cutP[1]; cutEnd = pa.first + cutP[2];
                    }
                } 
            }
            
            // if split the left intervals
            int leftPro = -1, leftSt = -1, leftEnd = -1, lefttPos = -1;
            for (int i = 0; i < leftIn.size(); i++) {
                pair<int, int> pa = leftIn[i];
                
                if (pa.first == pa.second) {
                    if (profit[pa.first] > leftPro) {
                        leftPro = profit[pa.first];  lefttPos = i;
                        leftSt = pa.first; leftEnd = pa.first;
                    }
                }
                else {
                    // calculate the maxPro in left interval
                    vector<int> temPro(profit.begin() + pa.first, profit.begin() + pa.second + 1);
                    vector<int> cutP = maxProf(temPro);
                    
                    if (cutP[0] <= 0) continue;
                    if (cutP[0] > leftPro) {
                        leftPro = cutP[0];  lefttPos = i;
                        leftSt = pa.first + cutP[1]; leftEnd = pa.first + cutP[2];
                    }
                }
            }
            // stop when no plus
            if (cutPro <= 0 && leftPro <= 0) break;
            
            if (cutPro > leftPro) {
                sum += cutPro;
                
                pair<int, int> pa = proIn[cutPos];
                // cut the intervals
                if (cutSt > pa.first) proIn.push_back(make_pair(pa.first, cutSt - 1));
                if (pa.second > cutEnd) proIn.push_back(make_pair(cutEnd + 1, pa.second));
                // remove origin interval
                proIn.erase(proIn.begin() + cutPos);
            } 
            else {
                sum += leftPro;
                
                // add the splitted intervals
                pair<int, int> pa = leftIn[lefttPos];
                proIn.push_back(make_pair(leftSt, leftEnd));
  
                // add the left intervals
                if (leftSt > pa.first) leftIn.push_back(make_pair(pa.first, leftSt - 1));
                if (pa.second > leftEnd) proIn.push_back(make_pair(leftEnd + 1, pa.second));
  
                // remove origin interval
                leftIn.erase(leftIn.begin() + lefttPos);
            }
            
            k--;
        }
        
        return sum;
        
    }
    
     vector<int> maxProf(vector<int>& profit) {
        int len = profit.size();
        int start = 0, end = 0, tempPro = profit[0];
        int maxStart = 0, maxEnd = 0, maxPro = profit[0];
        
        for (int i = 1; i < len; i++) {
            if (tempPro + profit[i] > profit[i]) tempPro = tempPro + profit[i];
            else {
                tempPro = profit[i];
                start = i;
            }
            end = i;
            if (tempPro > maxPro) {
                maxStart = start;
                maxEnd = end;
                maxPro = tempPro;
            }
        }
        
        vector<int> result;
        result.push_back(maxPro); result.push_back(maxStart); result.push_back(maxEnd);
        return result;
    }
    
    vector<int> cutProf(vector<int> profit) {
        for (int i = 0; i < profit.size(); i++) profit[i] = -profit[i];
        vector<int> minPro = maxProf(profit);
        return minPro;
    }
};
