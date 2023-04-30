// https://leetcode.com/problems/strong-password-checker/
// Greedy

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
    
    int strongPasswordChecker(string password) {
        int n = password.size(); cout << "n = " << n << endl;
        if (n < 4) return 6 - n;
        
        bool low = false, up = false, dig = false; 
        
        // Condition 3
        bool cont = false; int conNum = 0; vector<int> blocks;
        for (int i = 0; i < n; i++) {
            if (password[i] >= 'a' && password[i] <= 'z') low = true;
            else if (password[i] >= 'A' && password[i] <= 'Z') up = true;
            else if (password[i] >= '0' && password[i] <= '9') dig = true;
            
            if (i >= 2 && password[i] == password[i - 1] && password[i] == password[i - 2]) {
                if (!cont) {
                    cont = true; conNum = 3;
                }
                else conNum++;
            }
            else if (cont) {
                cont = false; blocks.push_back(conNum); conNum = 0;
            }
        }
        
        if (cont) blocks.push_back(conNum);
        
        // Condition 2
        int vali = 0;
        if (!low) vali++; if (!up) vali++; if (!dig) vali++;
        
        // Condition 1
        if (n == 4) return max(vali, 2); 
        
        if (n == 5) {
            if (blocks.empty() || blocks[0] < 5) return max(vali, 1);
            else return max(vali, 2);
        }
        
        int rep = 0, total = 0; // for (int num : blocks) cout << num << ","; cout << endl;
        for (int num : blocks) {rep += (num / 3); total += num;}
        
        if (n >= 6 && n <= 20) return max(vali, rep);
        
        int sub = n - 20; 
        
        int left = 0, pos = 0, tvali = vali;
        
        // Vali Round 1
        while (pos < blocks.size() && tvali > 0) {
            while (blocks[pos] > 4 && tvali > 0) {
                blocks[pos] -= 3; tvali--;
            }
            pos++;
        }
        // for (int num : blocks) cout << num << ","; cout << endl;
        
        // Vali Round 2
        if (tvali > 0) {
            sort(blocks.begin(), blocks.end());
            while (tvali > 0 && !blocks.empty()) {
                if (blocks.back() >= 3) tvali--;
                blocks.pop_back(); 
            }
        }
        
        while (!blocks.empty() && blocks.back() < 3) blocks.pop_back();
        if (blocks.empty()) return sub + vali;
        
        // Sub Round 1
        vector<pair<int, int>> m_b;
        for (int num : blocks) {
            m_b.push_back({num % 3, num});
        }
        
        make_heap(m_b.begin(), m_b.end(), cmp);
        // cout << m_b.front().first << ":" << m_b.front().second << endl;
        
        int tsub = sub;
        while (tsub > 0 && !m_b.empty()) {
            
            if (tsub >= m_b.front().first + 1) {
                tsub -= m_b.front().first + 1; 
                
                int f1 = 2, f2 = m_b.front().second - m_b.front().first - 1;
                
                pop_heap(m_b.begin(), m_b.end(), cmp); m_b.pop_back();
                if (f2 >= 3) {
                    m_b.push_back({f1, f2}); push_heap(m_b.begin(), m_b.end(), cmp);
                }
            }
            else  tsub = 0;
        }
        
        if (m_b.empty()) return sub + vali;
        // for (auto& num : m_b) cout << num.first << ":" << num.second << ","; cout << endl;
        
        // Rep round
        rep = 0;
        for (auto& num : m_b) rep += (num.second / 3); 
        
        return sub + vali + rep;
    }
};
