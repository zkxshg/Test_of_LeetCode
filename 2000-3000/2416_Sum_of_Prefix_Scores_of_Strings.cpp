// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/?envType=daily-question&envId=2024-09-15
// Trie

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int count = 0; // 以当前节点为前缀的字符串数量
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    // 插入字符串的所有前缀
    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++; // 更新以当前前缀的计数
        }
    }

    // 计算给定字符串的所有前缀的分数
    int calculateScore(const std::string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c];
            score += node->count; // 累加当前前缀的计数
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        for (const auto& word : words) {
            trie.insert(word);
        }

        vector<int> res(words.size());
        
        for (int i = 0; i < words.size(); i++) {
            res[i] = trie.calculateScore(words[i]);
        }

        return res;
    }
};
