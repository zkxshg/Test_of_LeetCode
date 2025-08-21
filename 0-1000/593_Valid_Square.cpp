// math
class Solution {
public:
    double euliDis(vector<double>& p1, vector<double>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1[0] == p2[0] && p1[1] == p2[1]) return false;
        if (p1[0] == p3[0] && p1[1] == p3[1]) return false;
        if (p1[0] == p4[0] && p1[1] == p4[1]) return false;
        if (p2[0] == p3[0] && p2[1] == p3[1]) return false;
        if (p2[0] == p4[0] && p2[1] == p4[1]) return false;
        if (p4[0] == p3[0] && p4[1] == p3[1]) return false;
        
        vector<double> po1(2); po1[0] = p1[0]; po1[1] = p1[1];
        vector<double> po2(2); po2[0] = p2[0]; po2[1] = p2[1];
        vector<double> po3(2); po3[0] = p3[0]; po3[1] = p3[1];
        vector<double> po4(2); po4[0] = p4[0]; po4[1] = p4[1];
        
        vector<double> mid(2);
        
        if (euliDis(po1, po2) == euliDis(po1, po3)) {
            mid[0] = (po2[0] + po3[0]) / 2.0; mid[1] = (po2[1] + po3[1]) / 2.0;
        }
        else if (euliDis(po2, po1) == euliDis(po2, po3)) {
            mid[0] = (po1[0] + po3[0]) / 2.0; mid[1] = (po1[1] + po3[1]) / 2.0; 
        }
        else {mid[0] = (po1[0] + po2[0]) / 2.0; mid[1] = (po1[1] + po2[1]) / 2.0;}
        
        if (euliDis(mid, po1) == euliDis(mid, po2) && 
            euliDis(mid, po2) == euliDis(mid, po3) && 
            euliDis(mid, po3) == euliDis(mid, po4)) return true;
        return false;
    }
};
