// https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-01
// Matrix + Linked List
// Using 4 points: l/r/t/b
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        ListNode* current = head;
        
        while (top <= bottom && left <= right) {
            // Fill the top row
            for (int i = left; i <= right && current != nullptr; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            top++;
            
            // Fill the right column
            for (int i = top; i <= bottom && current != nullptr; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;
            
            // Fill the bottom row
            for (int i = right; i >= left && top <= bottom && current != nullptr; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            bottom--;
            
            // Fill the left column
            for (int i = bottom; i >= top && left <= right && current != nullptr; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            left++;
        }
        
        return matrix;
    }

};

// Check matrix[next_x][next_y] != -1
class Solution_2 {
public:
     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Direction vectors for right, down, left, and up
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int dir = 0; // Start by moving to the right
        
        int x = 0, y = 0; // Start position
        ListNode* current = head;
        
        while (current != nullptr) {
            matrix[x][y] = current->val;
            current = current->next;
            
            // Calculate the next position
            int next_x = x + dx[dir];
            int next_y = y + dy[dir];
            
            // Check if the next position is valid
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || matrix[next_x][next_y] != -1) {
                // Change direction
                dir = (dir + 1) % 4; // Move to the next direction
                next_x = x + dx[dir];
                next_y = y + dy[dir];
            }
            
            // Update to the next position
            x = next_x;
            y = next_y;
        }
        
        return matrix;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
