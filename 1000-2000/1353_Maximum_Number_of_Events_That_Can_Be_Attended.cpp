// 1353. Maximum Number of Events That Can Be Attended
// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Lang: C++
// Date: 2025-08-21 21:03:59.055 UTC

class Solution {
public:

      int maxEvents(vector<vector<int>>& events) {
        // Sort by start day
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int n = events.size();
        int st = 0;          // index into events
        int day = 0;         // current day
        int attended = 0;    // result
        
        // Process until we've considered all events and the heap is empty
        while (st < n || !minHeap.empty()) {
            // If no pending events to attend, jump day to next event's start
            if (minHeap.empty()) {
                day = max(day, events[st][0]);
            }
            
            // Add all events that have started by 'day'
            while (st < n && events[st][0] <= day) {
                minHeap.push(events[st][1]);
                ++st;
            }
            
            // Remove events that have already ended before 'day'
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            
            // Attend the event that ends the soonest
            if (!minHeap.empty()) {
                minHeap.pop();
                ++attended;
                ++day;
            }
        }
        
        return attended;
    }

};
