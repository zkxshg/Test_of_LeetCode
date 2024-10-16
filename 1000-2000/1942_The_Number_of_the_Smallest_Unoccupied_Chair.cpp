// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/?envType=daily-question&envId=2024-10-11
// Heap

class Solution {
public:
    #define pii pair<int, int>

    static bool cmp(int x, int y) {
        return x > y;
    }

    static bool pcmp(pii& x, pii& y) {
        if (x.first == y.first) return x.second > y.second;
        return x.first > y.first;
    }

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> chairHeap;
        for (int i = 0; i < n; i++) chairHeap.push_back(i);
        make_heap(chairHeap.begin(), chairHeap.end(), cmp); 

        vector<pii> friendHeap;
        make_heap(friendHeap.begin(), friendHeap.end(), pcmp); 

        int tarArr = times[targetFriend][0];
        sort(times.begin(), times.end());

        unordered_map<int, int> arrTime;
        for (int i = 0; i < n; i++) {
            int tm = times[i][0], leaveTm =  times[i][1];

            while (!friendHeap.empty() && friendHeap.front().first <= tm) {
                chairHeap.push_back(friendHeap.front().second); 
                push_heap(chairHeap.begin(), chairHeap.end(), cmp);

                pop_heap(friendHeap.begin(), friendHeap.end(), pcmp); 
                friendHeap.pop_back();
            }

            int tmChair = chairHeap.front();
            if (tarArr == tm) return tmChair;

            pop_heap(chairHeap.begin(), chairHeap.end(), cmp); 
            chairHeap.pop_back();

            friendHeap.push_back({leaveTm, tmChair}); 
            push_heap(friendHeap.begin(), friendHeap.end(), pcmp);
        }

        return -1;
    }
}; 
