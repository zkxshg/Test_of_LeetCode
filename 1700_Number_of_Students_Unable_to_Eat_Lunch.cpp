// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
// Queue

class Solution {
public:
    #define st students
    #define sa sandwiches
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = st.size(), zero = 0, one = 0;
        
        queue<int> stq, saq;
        for (int i = 0; i < n; i++) {
            stq.push(st[i]); saq.push(sa[i]);
            
            if (st[i]) one++;
            else zero++;
        }
        
        while (!stq.empty()) {
            if (saq.front() == stq.front()) {
                if (stq.front()) one--;
                else zero--;
                
                saq.pop(); stq.pop();
            }
            else {
                if (saq.front() == 0 && zero == 0) break;
                if (saq.front() == 1 && one == 0) break;
                
                stq.push(stq.front()); stq.pop();
            }
        }
        
        return stq.size();
    }
};
