class Solution {
public:
    string convertToTitle(int n) {
        string result;

        while (n > 0){
            int temp = n % 26;
            if (temp == 0) temp = 26;
            char temc = 'A' + temp - 1;
            result.push_back(temc);
            if (temp == 26) n = (n / 26) - 1;
            else n = n / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
