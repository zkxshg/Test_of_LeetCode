// same to 169. Majority Element
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1 || len == 0) return nums;
        vector<int> result;
        bool getM = false;
        int aim = nums[0];
        int counter = 1;
        int pos = 0;
        while(nums.size() > len / 3){
            aim = nums[0];
            counter = 0;
            pos = 0;
            while (pos < nums.size()){
                if (nums[pos] == aim){
                    counter++;
                    nums.erase(nums.begin()+pos);
                }
                else pos++;
            }
            if (counter > len / 3) result.push_back(aim);
        }
        return result;
    }
};
