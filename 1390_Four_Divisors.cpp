// https://leetcode.com/problems/four-divisors
// loop
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        if (len == 0) return sum;
        for (int i = 0; i < len; i++){
            if (nums[i] < 6) continue;
            // even number
            if(nums[i] % 2 == 0){
                if (nums[i] == 8) {
                    sum += 15;
                    continue;
                }
                // even * even
                int nd2 = nums[i]/2;
                if(nd2 % 2 == 0) continue;
                // even * odd
                int nsq = sqrt(nd2) + 1;
                bool nomore = true;
                for (int i = 3; i <= nsq; i += 2){
                    if (nd2 % i == 0){
                        nomore = false;
                        break;
                    }
                }
                if (nomore) {
                    sum += 3;
                    sum += nd2;
                    sum += nums[i];
                }
            }
            else{
                int nd2 = nums[i];
                int nsq = sqrt(nd2);
                // test sqrt
                if (nd2 == nsq * nsq) continue;
                int count = 0;
                int divi = 0;
                for (int i = 3; i <= nsq; i += 2){
                    if (nd2 % i == 0){
                        count++;
                        if (count > 1) break;
                        divi = i; 
                    }
                }
                if (count == 1) {
                    sum += 1;
                    sum += nd2;
                    sum += divi;
                    sum += nd2/divi;
                }
            }
        }
        return sum; 
    }
};
