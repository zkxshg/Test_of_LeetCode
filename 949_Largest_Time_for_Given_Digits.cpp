// permutation
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> maxA;
        int maxV = -1;  
        sort(A.begin(), A.end());
        if (ifTime(A)) {
            maxA = A;
            maxV = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
        } 
        while (next_permutation(A.begin(),A.end())) {
            if (ifTime(A)) {
                int tempV = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
                if (tempV > maxV) {
                    maxA = A;
                    maxV = tempV;
                }
            }
        }
        if (maxV < 0) return ""; 
        string result = "";
        result += to_string(maxA[0]); result += to_string(maxA[1]);
        result += ":"; result += to_string(maxA[2]); result += to_string(maxA[3]);
        return result;
    }
    bool ifTime(vector<int>& A) {
        if (((A[0] == 2 && A[1] <= 3) || A[0] < 2) && A[2] <= 5) return true;
        return false;
    }
};

// greedy
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        if (A[0] > 2) return "";
        
        string result = "";
        
        int t1 = findTime(2, A), t2, t3;
        if (t1 < 0) return "";
        result += to_string(t1);
        
        if (t1 == 2) {
            t2 =  findTime(3, A);
            
            if (t2 >= 0) result += to_string(t2);
            else {
                t1 = findTime(1, A);
                if (t1 < 0) return "";
                
                A.push_back(2);
                sort(A.begin(), A.end());
                
                result = to_string(t1) + to_string(A.back());
                A.pop_back();
            }
        } else {
            result += to_string(A.back());
            A.pop_back();
        }
        
        result += ":";
        
        t3 = findTime(5, A);
        if (t3 < 0) return "";
        
        result += to_string(t3);
        result += to_string(A.back());
        
        return result;
    }
    
    int findTime(int aim, vector<int>& A) {
        auto pos = find(A.begin(), A.end(), aim);
        while (aim >= 0 && pos == A.end()) {
            aim--;
            pos = find(A.begin(), A.end(), aim);
        }
        
        if (aim < 0) return -1;
        
        A.erase(pos);
        return aim;
    }
};
