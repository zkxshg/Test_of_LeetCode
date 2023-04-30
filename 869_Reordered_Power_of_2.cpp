// Map
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int Nlen = intLen(N);
        vector<int> Nset = getDig(N);
        
        long long p2 = 1;
        int plen = 1;
        
        
        while (plen <= Nlen) { 
            if (plen == Nlen) {
                vector<int> Pset = getDig(p2);
                if (ifEqVec(Nset, Pset)) return true;
            }
            
            p2 *= 2;
            plen = intLen(p2);
        }
        
        return false;
    }
    
    bool if2p(long long n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    int intLen(long long n) {
        int len = 0;
        while (n > 0) {
            len++; n /= 10; 
        }
        return len;
    }
    
    vector<int> getDig(int n) {
        vector<int> chas(10);
        while (n > 0) {
            chas[n % 10]++; n /= 10;
        }
        return chas;
    }
    
    bool ifEqVec(vector<int>& A, vector<int>& B) {
        for (int i = 0; i < 10; i++)
            if (A[i] != B[i])
                return  false;
        return true;
    }
};
