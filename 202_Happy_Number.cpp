class Solution {
public:
    bool isHappy(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        bool happy = false;
        bool conti = true;
        vector<int> before;
        int len = 0;
        int sum = 0;
        while (conti){
            sum = 0;
            len = getL(n);
            for (int i = 0; i < len; i++) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
            if (n == 1){
                happy = true;
                break;
            }
            for (int j = 0; j < before.size(); j++){
                if (before[j] == sum){
                    conti = false;
                    break;
                }
            }
            if (conti) before.push_back(sum);
        }
        return happy;
    }
    int getL(int n){
        int len = 0;
        while(n){
            n = n/10;
            len++;
        }
        return len;
    }
};
