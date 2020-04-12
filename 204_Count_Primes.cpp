class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        else if (n == 3) return 1;
        
        int counter = 1;
        for(int i = 3; i < n; i++){
            if (isPrimes(i)) counter++;
        }
        return counter;
    }
    
    bool isPrimes(int n){
        int sn = sqrt(n);
        for (int i = 2; i < sn + 1; i++){
            if (n % i == 0) return false;
        }
        return true;
    }
};
