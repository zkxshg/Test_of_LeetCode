// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
// Math + Trie

class Solution {
public:

    int getReqNum(long a, long b, long &n){
        int gap = 0; 

        while (a <= n) {
            gap += min(n+1, b) - a;
            a *= 10;
            b *= 10;
        }

        return gap;
    } 

    int findKthNumber(long n, int k) {
        long num = 1;
        int pos = 1;
        while (pos < k){
            int req = getReqNum(num, num+1, n);

            if (pos + req <= k) {
                pos += req; 
                num++;
            } 
            else{
                pos++;
                num *= 10;
            }
        }
        return num;
    }
};
