// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
// Prefix sum

class Solution {
public:
    #define GB garbage
    #define TR travel

    vector<int> countGarbage(const string& garbage) {
        vector<int> counts(3, 0); 

        for (char c : garbage) {
            if (c == 'M') counts[0]++;  
            else if (c == 'P') counts[1]++; 
            else if (c == 'G') counts[2]++;
        }

        return counts;
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = GB.size();

        vector<int> gb0 = countGarbage(GB[0]);
        vector<int> preM(n); preM[0] = gb0[0];
        vector<int> preP(n); preP[0] = gb0[1];
        vector<int> preG(n); preG[0] = gb0[2];
        vector<int> preT(n);

        int lastM = gb0[0] ? 0 : -1;
        int lastP = gb0[1] ? 0 : -1;
        int lastG = gb0[2] ? 0 : -1;
        for (int i = 1; i < n; i++) {
            vector<int> gbs = countGarbage(GB[i]);

            if (gbs[0] > 0) lastM = i;
            preM[i] = preM[i - 1] + gbs[0];
            if (gbs[1] > 0) lastP = i;
            preP[i] = preP[i - 1] + gbs[1];
            if (gbs[2] > 0) lastG = i;
            preG[i] = preG[i - 1] + gbs[2];

            preT[i] = preT[i - 1] + TR[i - 1];
        }
        cout << lastM << "," << lastP << "," << lastG << endl;
        int res = 0;
        if (lastM >= 0) res += preT[lastM] + preM[lastM];
        if (lastP >= 0) res += preT[lastP] + preP[lastP];
        if (lastG >= 0) res += preT[lastG] + preG[lastG];

        return res;
    }
};
