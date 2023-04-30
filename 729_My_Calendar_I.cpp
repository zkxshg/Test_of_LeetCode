// https://leetcode.com/problems/my-calendar-i/
// pair
class MyCalendar {
public:
    vector<pair<int, int> > cal;
    
    MyCalendar() {
        cal.clear(); 
    }
    
    bool book(int start, int end) {
        int n = cal.size();
        
        if (n == 0) {
            cal.push_back(make_pair(start, end));
            return true;
        }
        
        for (int i = 0; i < n; i++) {
            if (cal[i].first >= end) {
                cal.insert(cal.begin() + i, make_pair(start, end));
                return true;
            }
            else if (cal[i].second <= start) {
                if (i == n - 1) {
                    cal.push_back(make_pair(start, end));
                    return true;
                }
            }
            else return false;
        }
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
