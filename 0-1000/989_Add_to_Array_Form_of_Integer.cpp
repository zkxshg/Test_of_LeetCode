// when lena < 10: tansform to int
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if (K == 0) return A;
        int lenk = int(log10(K)) + 1;
        int lena = A.size();
        
        if (lena < 10){
            long long a = 0;
            for (int i = 0; i < lena; i++) a += A[i] * round(pow(10, lena - i - 1)); 
            a += K;
            int len = int(log10(a)) + 1;
            string as = to_string(a);
            vector<int> result(len);
            for (int i = 0; i < len; i++) result[i] = (as[i] - '0');
            return result;
        }
        
        int len = lena + 1;
        vector<int> result(len, 0);
        string num2 = to_string(K);
        
        for (int i = 1; i < lenk + 1; i++){
            int temp = A[lena - i] + (num2[lenk - i] - '0') + result[len - i];
            if (temp > 9) {   
                result[len - i] = temp % 10;
                result[len - i - 1] = 1;
            }
            else result[len - i] = temp;
        }
        for (int i = lenk + 1; i < lena + 1; i++){
            int temp = A[lena - i] + result[len - i];
            if (temp > 9) {
                result[len - i] = temp % 10;
                result[len - i - 1] = 1;
            }
            else result[len - i] = temp;
        }
        if (result[0] == 0) {
            vector<int> A2(result.begin()+1, result.end());
            result = A2;
        }
        return result;
    }
};
