class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        x_len = len(matrix)
        y_len = len(matrix[0])
        x_index = []
        y_index = []
        
        for i in range(0, x_len):
            for j in range(0, y_len):
                if matrix[i][j] == 0:
                    x_index.append(i)
                    y_index.append(j)
        
        for k in range(0, len(x_index)):
            for k1 in range(0, x_len):
                matrix[k1][y_index[k]] = 0
            for k2 in range(0, y_len):
                matrix[x_index[k]][k2] = 0
