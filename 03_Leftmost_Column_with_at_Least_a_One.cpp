/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> nm = binaryMatrix.dimensions();
        int n = nm[0], m = nm[1];
        if (n == 1 && m == 1) {
            if(binaryMatrix.get(0, 0)) return 0;
            else return -1;
        } 
        
        int result = m + 1, x = 0, y = m - 1;
        bool stop = false;
        while (!stop) {
            if (binaryMatrix.get(x, y)) {
                result = y;
                y--;
                if (y < 0) break;
            }
            else {
                x++;
                if (x >= n) break;
            }
        }
        if (result >= m) return -1;
        return result;      
        
    }
};
