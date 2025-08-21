// math - high dimensions
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int N = buckets, M =  minutesToDie, P = minutesToTest;
        if (N <= 1) return 0;
        
        int T = P / M; if (T < 1) return -1;
        if (N - 1 <= T) return 1;
        
        for (int x = 2; x < N - 1; x++) {
            if (ifTest(N, T, x)) return x;
        }
        
        return N - 1;
    }
    
    bool ifTest(int N, int T, int X) {
        if (pow(T + 1, X) >= N) return true;
        return false;
    }
};
