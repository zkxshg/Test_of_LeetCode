// Rejection Sampling
class Solution {
public:
    int rand10() {
        int n = rand7(), m = rand7();
        while(n > 5) n = rand7();
        while(m == 7) m = rand7();
        return (m % 2 ? 5 : 0) + n;
    }
};
