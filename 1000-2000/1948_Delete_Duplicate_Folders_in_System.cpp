// 1948. Delete Duplicate Folders in System
// Link: https://leetcode.com/problems/delete-duplicate-folders-in-system/
// Lang: C++
// Date: 2025-08-21 21:00:43.508 UTC

class Solution {
public:
    struct Node {
        string name;
        unordered_map<string, Node*> ch;
        bool del = false;
        string sig; // serialization of subtree (structure only)
        Node(string n=""): name(std::move(n)) {}
    };
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // 1. build trie
        Node* root = new Node("");
        for (auto &p : paths) {
            Node* cur = root;
            for (auto &s : p) {
                if (!cur->ch.count(s)) cur->ch[s] = new Node(s);
                cur = cur->ch[s];
            }
        }
        
        unordered_map<string,int> freq;
        // 2. serialize and count
        serialize(root, freq);
        // 3. mark deletions
        mark(root, freq);
        // 4. collect remaining paths
        vector<vector<string>> ans;
        vector<string> curPath;
        dfsCollect(root, curPath, ans);
        // free memory if needed (ignored here)
        return ans;
    }

    // return signature of subtree (excluding current node's own name)
    // format: "(" + childName + "#" + childSig + ")" ... sorted by childName
    string serialize(Node* node, unordered_map<string,int>& freq) {
        if (node->ch.empty()) {
            node->sig = ""; // empty folder -> empty signature
            return node->sig;
        }
        vector<pair<string,string>> vec;
        vec.reserve(node->ch.size());
        for (auto &kv : node->ch) {
            Node* child = kv.second;
            string cs = serialize(child, freq);
            vec.push_back({child->name, cs});
        }
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){return a.first < b.first;});
        string s;
        for (auto &pr : vec) {
            s += "(" + pr.first + "#" + pr.second + ")";
        }
        node->sig = s;
        // Only count non-empty signatures (as per problem interpretation)
        if (!s.empty()) freq[s]++;
        return node->sig;
    }

    void mark(Node* node, unordered_map<string,int>& freq) {
        if (!node->sig.empty() && freq[node->sig] > 1) {
            node->del = true;
        }
        for (auto &kv : node->ch) {
            mark(kv.second, freq);
        }
    }

    void dfsCollect(Node* node, vector<string>& cur, vector<vector<string>>& ans) {
        for (auto &kv : node->ch) {
            Node* child = kv.second;
            if (child->del) continue;             // whole subtree removed
            cur.push_back(child->name);
            ans.push_back(cur);                    // this folder remains
            dfsCollect(child, cur, ans);
            cur.pop_back();
        }
    }
}; 
