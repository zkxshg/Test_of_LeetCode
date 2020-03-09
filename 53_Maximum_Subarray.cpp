// brute-force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> posi;
        for (int i = 0; i < len; i++){
            if (nums[i] > 0) posi.push_back(i);
        }
        int lenpo  = posi.size();
        vector<int>::iterator p = max_element(nums.begin(), nums.end());
        int sinmax = *p;
        if (lenpo == 0 || lenpo == 1) return *p;

        int glomax = 0;
        int counter = 1;
        int pos = 0;
        while (counter < lenpo){
            int tsum = sumArr(pos, counter, nums, posi);
            if (tsum > 0){
                tsum += nums[posi[counter]];
                if (tsum > glomax) glomax = tsum;
            }
            else pos = counter;
            counter++;
        }
        if (sinmax > glomax) glomax = sinmax;
        return glomax;
    }
   
    int sumArr(int start, int end1, vector<int> num, vector<int> pos){
        int sum = 0;
        int s1 = pos[start];
        int l1 = pos[end1];
        for (int i = s1; i < l1; i++) sum += num[i];
        return sum;
    }
    
};

// divide-and-conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> posi;
        for (int i = 0; i < len; i++){
            if (nums[i] > 0) posi.push_back(i);
        }
        int lenpo  = posi.size();
        vector<int>::iterator p = max_element(nums.begin(), nums.end());
        int sinmax = *p;
        int glomax = 0;
        if (lenpo == 0 || lenpo == 1) return *p;

        vector<int> maxSub(3);
        maxSub = dcComp(0, lenpo-1, nums, posi, &glomax);
        if (sinmax > maxSub[2]) maxSub[2] = sinmax;
        if (glomax > maxSub[2]) maxSub[2] = glomax;
        return maxSub[2];
    }
    
    vector<int> dcComp(int start, int last, vector<int> num, vector<int> pos, int * gmax){

        int s1 = pos[start];
        int l1 = pos[last];
        vector<int> result(3);

        if (last - start == 1) {
            int sum = sumArr(start, last, num, pos);
            if (sum > *gmax) *gmax = sum;
            result = {start, last, sum};
            if (sum < 0) {
                if (start == 0) result = {last, last, num[l1]};
                else result = {start, start, num[s1]};
            }
            return result;
        }

        int median = (start + last) / 2;
        vector<int> left1 = dcComp(start, median, num, pos, gmax);
        vector<int> right1 = dcComp(median, last, num, pos, gmax);

        int sum = 0;
        sum = sumArr(left1[0], right1[1], num, pos);
        if (sum > *gmax) *gmax = sum;
        if (sum < 0) result = left1;
        else if (sum > left1[2] && sum > right1[2]) result = {left1[0],  right1[1], sum};
        else if (left1[2] > right1[2]) result = left1;
        else result = right1;

        return result;
    }
    
    int sumArr(int start, int end1, vector<int> num, vector<int> pos){
        int sum = 0;
        int s1 = pos[start];
        int l1 = pos[end1];
        for (int i = s1; i < l1 + 1; i++) sum += num[i];
        return sum;
    }
    
};
