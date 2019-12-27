class Solution(object):
    def findNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in nums:            
            str_i = str(i)
            count = len(str_i)
            if count % 2 == 0 :
                result += 1
        return result 
