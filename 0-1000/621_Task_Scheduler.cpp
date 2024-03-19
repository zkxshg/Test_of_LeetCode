// https://leetcode.com/problems/task-scheduler/?envType=daily-question&envId=2024-03-19
// Heap + Greedy

class Solution {
public:
    #define pii pair<int, int>
    static bool cmp(pii& a, pii& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fre(26);
        for (char c : tasks) fre[c - 'A']++;

        vector<int> freHeap;
        vector<pii> coolHeap;

        for (int i = 0; i < 26; i++) {
            if (fre[i]) freHeap.push_back(fre[i]);
        }
        make_heap(freHeap.begin(), freHeap.end()); 
        make_heap(coolHeap.begin(), coolHeap.end(), cmp);

        int tem = 0;
        while (!freHeap.empty() || !coolHeap.empty()) {
            while (!coolHeap.empty() && coolHeap.front().first < tem) {
                auto p = coolHeap.front();
                pop_heap(coolHeap.begin(), coolHeap.end(), cmp); 
                coolHeap.pop_back(); 

                freHeap.push_back(p.second); 
                push_heap(freHeap.begin(), freHeap.end()); 
            }

            int tsk = freHeap.front();
            pop_heap(freHeap.begin(), freHeap.end()); 
            freHeap.pop_back(); 

            if (tsk > 1) {
                coolHeap.push_back({tem + n, tsk - 1}); 
                push_heap(coolHeap.begin(), coolHeap.end(), cmp); 
            }

            if (freHeap.empty() && !coolHeap.empty()) tem = coolHeap.front().first + 1;
            else tem++;
        }

        return tem;
    }
};
