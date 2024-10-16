// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/?envType=daily-question&envId=2024-10-13
// Greedy + Heap

class Solution {
public:
    #define pii pair<int, int>

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pii, vector<pii>, greater<pii>> minHeap; // 最小堆
        int currentMax = INT_MIN; // 当前范围的最大值
        
        // 初始化堆并更新当前最大值
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i}); // 将每个列表的第一个元素放入堆
            currentMax = max(currentMax, nums[i][0]); // 更新当前最大值
        }

        int rangeStart = 0, rangeEnd = INT_MAX; // 记录最小范围
        vector<int> index(nums.size(), 0); // 跟踪每个列表的当前索引

        // 处理堆中的元素
        while (minHeap.size() == nums.size()) {
            // 获取堆顶的最小元素
            pii currentMin = minHeap.top();
            minHeap.pop(); // 移除最小元素
            
            // 更新范围
            if (currentMax - currentMin.first < rangeEnd - rangeStart) {
                rangeStart = currentMin.first; // 更新范围起始值
                rangeEnd = currentMax; // 更新范围结束值
            }
            
            // 移动到同一列表的下一个元素
            int listIndex = currentMin.second; // 获取列表索引
            if (++index[listIndex] < nums[listIndex].size()) {
                minHeap.push({nums[listIndex][index[listIndex]], listIndex}); // 加入下一个元素
                currentMax = max(currentMax, nums[listIndex][index[listIndex]]); // 更新当前最大值
            }
        }
        
        return {rangeStart, rangeEnd}; // 返回最小范围
    }
};
