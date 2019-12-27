class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        valid_index = []
        nega_index = []
        result = []
        
        for i in range(0, len(nums)):
            if nums[i] <= target and nums[i] >= 0:
                valid_index.append(i)
            else:
                nega_index.append(i)
                
        for j in valid_index:
            for k in valid_index:
                if nums[j] + nums[k] == target:
                    if j != k:
                        result.append(j)
                        result.append(k)
                        return result
                    
        for j in nega_index:
            for k in nega_index:
                if nums[j] + nums[k] == target:
                    if j != k:
                        result.append(j)
                        result.append(k)
                        return result
        return -1
