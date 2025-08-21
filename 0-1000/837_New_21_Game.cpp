// DP - array
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;
        if (W == 1) return 1.0;
        
        vector<double> pros(K + 1);
        double sumPro = 0.0;
        pros[0] = 0.0;
        
        pros[1] = double(N - K + 1) / W;
        if (pros[1] > 1.0) pros[1] = 1.0;
        sumPro += pros[1];

        for (int i = 2; i <= K; i++) {
            int N_i = N - K + i;
            
            if (i <= W) {
                pros[i] = sumPro / W;
                
                if (N_i <= W) pros[i] += double(N - K + 1) / W;
                else pros[i] += double(W - i + 1) / W;
                
                sumPro += pros[i];
            }
            else {
                pros[i] = sumPro / W;
                sumPro += pros[i];
                sumPro -= pros[i - W];
            }
        }
        
        return pros[K];
    }
};
