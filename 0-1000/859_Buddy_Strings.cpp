// Use cou to rec diff char
// Use dict to rec same char
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A.size() < 2) return false;

        char A1, A2, B1, B2;
        vector<int> dict(26, 0);
        int cou = 0;
        for (int i = 0; i < A.size(); i++){
            if (A[i] != B[i]){
                if (cou > 1) return false;
                if(cou == 0){
                    A1 = A[i];
                    B1 = B[i];
                }
                else if (cou == 1){
                    A2 = A[i];
                    B2 = B[i];
                }
                cou++;
            }
            else dict[A[i]-'a']++;
        }
        if (cou == 0) {
            for (int i = 0; i < dict.size(); i++){
                if(dict[i] > 1) return true;
            }
        }
        else if (A1 == B2 && A2 == B1) return true;
        return false;
    }
};
