// numTrees(n) = sum \limit_{i in [1,n]} {numTrees(i-1) * numTrees(n-i)}
class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        int sum = 0;
        sum += 2 * numTrees(n-1);
        sum += 2 * numTrees(n-2);
        for (int i = 3; i < n - 1; i++){
            sum += numTrees(i-1) * numTrees(n-i);
        }
        return sum;
    }
};
