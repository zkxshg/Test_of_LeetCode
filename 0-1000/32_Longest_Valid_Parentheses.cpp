// case 1 - ( -> ( : add to temp / tempos, count = 0
// case 2 : ( -> ) : scan tempos
// case 3 : ) -> ( : continue
// case 4 : ) -> ) : clear all
class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        vector<char> stac;
        int count = 0;
        vector<int> temp;
        vector<int> tempos;
        stac.push_back('s');
        
        for (int i = 0; i < s.size(); i++){
            if(s[i] == ')' && stac[stac.size() - 1] == '('){
                count++;
                stac.pop_back();
                if (temp.size() > 0){
                    for (int i = tempos.size() - 1; i >= 0; i--){
                        if (stac.size() < tempos[i]) {
                            count += temp[i];
                            temp.erase(temp.begin()+i);
                            tempos.erase(tempos.begin()+i);
                        }
                        else break;
                    }
                }
                if (count > max) max = count;
            }
            else {
                if(s[i] == ')') {
                    count = 0;
                    vector<int>().swap(temp);
                    vector<int>().swap(tempos);
                }
                else if(count > 0 && s[i] == '(' && i && s[i - 1] == '('){
                    temp.push_back(count);
                    tempos.push_back(stac.size());
                    count = 0;
                }
                stac.push_back(s[i]);
            }
        }
        return max * 2;
    }
};
