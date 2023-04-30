// Delete all elements searched.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        
        vector<int> sec = nums;
        vector<int> tem;
        bool getM = false;
        int aim = sec[0];
        int counter = 1;
        
        while(!getM){
            aim = sec[0];
            counter = 1;
            for (int i = 1; i < sec.size(); i++){
                if (sec[i] == aim) counter++;
                else tem.push_back(sec[i]);
                if (counter > len / 2) break;
            }
            if (counter > len / 2) getM = true;
            else{
                sec = tem;
                tem.clear();
            }
        }
        return aim;
    }
};
