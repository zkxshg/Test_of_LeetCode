// MAX search
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> box;
        for (int i = lowLimit; i <= highLimit; i++) box[sumD(i)]++;
        int fre = 0, res = 0;
        for (auto& v : box) 
            if (v.second > fre) 
                fre = v.second;
        return fre;
        
    }
    int sumD(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};
