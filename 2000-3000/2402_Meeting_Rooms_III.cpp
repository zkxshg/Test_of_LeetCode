// https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2024-02-18
// Heap

class Solution {
public:
    using ll = long long;
    using pii = pair<ll, int>;

    // 用于hp_used的比较函数，确保按照会议结束时间升序排列
    struct Compare {
        bool operator()(const pii& a, const pii& b) {
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        }
    };

    int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> fre(n, 0);

        // 使用priority_queue来管理空闲房间，确保总是使用编号最小的房间
        priority_queue<int, vector<int>, greater<int>> hp_unused;
        for (int i = 0; i < n; ++i) hp_unused.push(i);

        // 使用priority_queue来管理正在使用的房间
        priority_queue<pii, vector<pii>, Compare> hp_used;

        ll temp = 0;
        for (auto& meet : meetings) {
            ll st = meet[0], en = meet[1];

            temp = std::max(st, temp); // 更新temp时间

            // 将已经结束的会议房间重新加入空闲房间堆
            while (!hp_used.empty() && hp_used.top().first <= temp) {
                hp_unused.push(hp_used.top().second);
                hp_used.pop();
            }

            if (!hp_unused.empty()) {
                int room = hp_unused.top(); hp_unused.pop();
                hp_used.push({temp + (en - st), room});
                fre[room]++;
            } else {
                auto next = hp_used.top(); hp_used.pop();
                temp = next.first;
                hp_used.push({temp + (en - st), next.second});
                fre[next.second]++;
            }
        }

        int maxMeetings = 0, roomNumber = 0;
        for (int i = 0; i < n; ++i) {
            if (fre[i] > maxMeetings) {
                maxMeetings = fre[i];
                roomNumber = i;
            }
        }

        return roomNumber;
    }
};
