// https://leetcode.com/problems/validate-binary-tree-nodes/description/
// Graph + Union Find + Binary tree

class Solution {
public:
    unordered_map<int, int> U;
    
    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDeg(n);
        U.clear();
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] >= 0) {
                inDeg[leftChild[i]]++;

                int pari = find(i), parl = find(leftChild[i]);

                if (pari == parl) return false;
                else U[parl] = pari;
            }
            if (rightChild[i] >= 0) {
                inDeg[rightChild[i]]++;

                 int pari = find(i), parr = find(rightChild[i]);

                if (pari == parr) return false;
                else U[parr] = pari;
            }
        }

        bool root = false;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] > 1) return false;

            if (!inDeg[i]) {
                if (!root) root = true;
                else return false;
            }
        }

        return root;
    }
};
