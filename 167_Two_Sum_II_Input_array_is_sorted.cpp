// O(nlogn) binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        int pos = -1;
        for (int i = 0; i < numbers.size(); i++){
            pos = firstVersion(numbers, target - numbers[i], i, numbers.size()-1);
            if (pos >= 0){
                result[0] = i + 1;
                result[1] = pos + 1;
                break;
            }
        }
        return result;
    }
    
    int firstVersion(vector<int>& numbers, int target, int start, int least) {
        if (start == least) {
            if (numbers[start] == target) return start;
            else return -1;
        }
        else{
            unsigned int k = (least + start) / 2;
            if (numbers[k] == target) return k;
            else if(numbers[k] > target) return firstVersion(numbers, target, start, k);
            else return firstVersion(numbers, target, k+1, least);
        }
        return -1;
    }
};
