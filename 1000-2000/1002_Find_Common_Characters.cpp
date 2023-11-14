// https://leetcode.com/problems/find-common-characters/
// for (int i = 2; i < A.size(); i++) res = intersect(res, A[i]);
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        if (len == 1) return A;
        
        vector<string> answer;
        string AinB = intersect(A[0], A[1]);
        if (len == 2) {
            for (int i = 0; i < AinB.size(); i++) answer.push_back(AinB.substr(i,1));
            return answer;
        }
        
        string res = AinB;
        for (int i = 2; i < A.size(); i++) {
            res = intersect(res, A[i]);
            if (res.size() == 0) break;
        }
                
        for (int i = 0; i < res.size(); i++) answer.push_back(res.substr(i,1));
        return answer;
    }
    
    string intersect(string A, string B) {
        string result;
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < B.size(); j++){
                if (A[i] == B[j]) {
                    result += A[i];
                    B.erase(j,1);
                    break;
                }
            }
        }
        return result;
    }
};
