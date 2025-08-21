// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// stack

class Solution {
public:

    bool isValidSerialization(string preorder) {
        if (preorder[0] == '#') {
            if (preorder.size() <= 1) return true;
            else return false;
        } 

        vector<int> tree;
        
        vector<int> arr;
        int tem = 0;
        for (char c : preorder) {
            if (c == ',') {
                arr.push_back(tem); tem = 0;
            }
            else if (c == '#') tem = -1;
            else tem = tem * 10 + (c - '0'); 
        }
        arr.push_back(tem);
        
        tree.push_back(2);
        for (int in = 1; in < arr.size(); in++) {
            int i = arr[in];
            
            //for (int j : tree) cout << j << ","; cout << endl;
            
            if (tree.empty()) return false;
            
            if (i < 0) {
                tree.back()--;
                while (!tree.empty() && tree.back() <= 0) {
                    tree.pop_back();
                    if (!tree.empty()) tree.back()--;
                }
            }
            else tree.push_back(2);
        }
        
        
        return tree.empty();
        
    }
};
