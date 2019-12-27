class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """     
        y = str(x)
        result = ''

        if x < 0:
            result += '-'

        zero_count = 1
        while y[len(y) - zero_count] == '0':
            if zero_count == len(y):
                return 0
            zero_count += 1
            

        for i in range(zero_count, len(y)):
            result += y[len(y) - i]

        if x > 0:
            result += y[0]
            
        if int(result) > 2**31 -1 or int(result) < -2**31:
            return 0
            
        return result
