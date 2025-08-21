// string
class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
         for (int i = 1; i <= N; i++)
             if (ifRo(i)) res++;
        return res;
    }
    
    bool ifRo(int n) {
        bool rot = false;
        while (n > 0) {
            int i = n % 10; 
            if (i == 3 || i == 4 || i==7) return false;
            if (i == 2 || i == 5 || i == 6 || i == 9) rot = true;
            
            n /= 10;
        }
        return rot;
    }
};
