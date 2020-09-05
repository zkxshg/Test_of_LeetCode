// isPrimes -> countPrimes -> numPrimeArrangements
class Solution {
public:
    int numPrimeArrangements(int n) {
        if (n < 2) return n;
        int priN = countPrimes(n);
        int comN = n - priN;
        
        long long multi = 1, UB = pow(10, 9) + 7;
        for (int i = 1; i <= priN; i++) {
            multi *= i; 
            if (multi > UB) multi %= UB;
        }
        for (int i = 1; i <= comN; i++) {
            multi *= i; 
            if (multi > UB) multi %= UB;
        }
        return multi;
    }
    
    int countPrimes(int n) {
        if (n <= 2) return 1;
        else if (n == 3) return 2;
        int counter = 2;
        for(int i = 4; i < n + 1; i++){
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
