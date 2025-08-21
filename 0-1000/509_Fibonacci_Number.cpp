// DP algo
class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        vector<int> fibo(N);
        fibo[0] = 0;
        fibo[1] = 1;
        for (int i = 2; i < N; i++) fibo[i] = fibo[i-2] + fibo[i-1];
        return (fibo[N-2] + fibo[N-1]);   
    }
};
