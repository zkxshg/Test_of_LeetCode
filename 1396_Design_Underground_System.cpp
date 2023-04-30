// https://leetcode.com/problems/design-underground-system/
// Design + hash_map
class UndergroundSystem {
public:
    map<string, int> st2num;
    
    unordered_map<int, int> checkL;
    unordered_map<int, int> checkS;
    
    map<pair<int, int>, int> stTime;
    map<pair<int, int>, int> stNum;
    int stID = 0;
    
    UndergroundSystem() {
        st2num.clear(); 
        checkL.clear(); checkS.clear();
        stTime.clear(); stNum.clear();
        stID = 0;
    }
    
    void checkIn(int id, string stationName, int t) {
        if (st2num.find(stationName) == st2num.end()) {
            st2num[stationName] = stID; stID++;
        }
        
        int stN = st2num[stationName];
        checkL[id] = t;
        checkS[id] = stN;
    }
    
    void checkOut(int id, string stationName, int t) {
        if (st2num.find(stationName) == st2num.end()) {
            st2num[stationName] = stID; stID++;
        }
        
        int st1 = checkS[id], st2 = st2num[stationName];
        int stime = t - checkL[id];
        
        stTime[make_pair(st1, st2)] += stime;
        stNum[make_pair(st1, st2)]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        int st1 = st2num[startStation], st2 = st2num[endStation];
        return double(stTime[make_pair(st1, st2)]) / stNum[make_pair(st1, st2)];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
