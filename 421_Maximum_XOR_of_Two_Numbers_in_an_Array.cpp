// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// prefix trie
class Solution {
public:
    struct TreeNode {
        TreeNode * zeroR;
        TreeNode * oneR;
        TreeNode() : zeroR(nullptr), oneR(nullptr) {}
    };
    
    int findMaximumXOR(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        
        TreeNode * root = new TreeNode();
        
        for (int i = 0; i < len; i++) insert(nums[i], root);
        
        int layer = 0, temp = 0;
        TreeNode * nex = root;
        while (!(nex->zeroR && nex->oneR)) {
            layer++;
            if (nex->oneR) nex = nex->oneR;
            else if(nex->zeroR) nex = nex->zeroR;
            else break;
        }

        if (layer == 33) return 0;

        return maxxor(root, nums);
    }
    
int maxxor(TreeNode* head, vector<int> nums) {
    int maxans = INT_MIN;
    
    for(int i=0; i<nums.size(); i++) {
        TreeNode* curr = head;
        int value = nums[i], currxor = 0;

        for(int j = 31; j >= 0; j--) {
            int bit = (value>>j)&1;
            
            if(!bit) {
                if (curr->oneR) {
                    currxor += pow(2, j);
                    curr = curr->oneR;
                } else {
                    curr = curr->zeroR;
                }
            } else {
                if (curr->zeroR) {
                    currxor += pow(2, j);
                    curr = curr->zeroR;
                } else {
                    curr = curr->oneR;
                }
            }  
        }
        maxans = max(maxans, currxor);  
    }
    
    return maxans;
}
    
    void insert(int num, TreeNode * root) {
        TreeNode * nex = root;
        
        for (int i = 31; i >=0; i--) {
            int bit = (num>>i)&1;
            
            if (bit) {
                if (!nex->oneR) nex->oneR = new TreeNode();
                nex = nex->oneR;
            } else {
                if (!nex->zeroR) nex->zeroR = new TreeNode();
                nex = nex->zeroR;
            }
        }
    }
};

// divide and conquer
class Solution {
public:
    struct TreeNode {
        TreeNode * zeroR;
        TreeNode * oneR;
        TreeNode() : zeroR(nullptr), oneR(nullptr) {}
    };
    
    int findMaximumXOR(vector<int>& nums) {
        int len = nums.size();
        if (len < 1) return 0;
        if (len < 2) return nums[0];
        
        TreeNode * root = new TreeNode();
        
        for (int i = 0; i < len; i++) insert(nums[i], root);
        
        int layer = 0, temp = 0;
        TreeNode * nex = root;
        while (!(nex->zeroR && nex->oneR)) {
            layer++;
            if (nex->oneR) nex = nex->oneR;
            else if(nex->zeroR) nex = nex->zeroR;
            else break;
        }

        if (layer == 33) return 0;

        return maxxor(nex->zeroR, nex->oneR, layer, temp);
    }
    
    int maxxor(TreeNode * left, TreeNode * right, int layer, int temp) {
        if (layer == 31) {
            if ((left->oneR && right->zeroR) || (right->oneR && left->zeroR)) return temp + 1;
            else return temp;
        }

        if ((left->oneR && right->zeroR) || (right->oneR && left->zeroR)) {
            temp += pow(2, 31 - layer);
            int maxV = temp;
            
            if (left->oneR && right->zeroR) 
                maxV = max(maxV, maxxor(left->oneR, right->zeroR, layer + 1, temp));
            
            if (left->zeroR && right->oneR)
                maxV = max(maxV, maxxor(left->zeroR, right->oneR, layer + 1, temp));
            
            return maxV;
        } 
        
        int maxV = temp;
        if (left->oneR && right->oneR) 
            maxV = max(maxV, maxxor(right->oneR, left->oneR, layer + 1, temp));
        
        if (right->zeroR && left->zeroR) 
            maxV = max(maxV, maxxor(left->zeroR, right->zeroR, layer + 1, temp));
        
        return maxV;
    }
    
    void insert(int num, TreeNode * root) {
        TreeNode * nex = root;
        
        for (int i = 31; i >=0; i--) {
            int bit = (num>>i)&1;
            
            if (bit) {
                if (!nex->oneR) nex->oneR = new TreeNode();
                nex = nex->oneR;
            } else {
                if (!nex->zeroR) nex->zeroR = new TreeNode();
                nex = nex->zeroR;
            }
        }
    }
};
