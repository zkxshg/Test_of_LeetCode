// Math
class Solution {
public:

    int mirrorReflection(int p, int q) {
        if (q == 0) return 0;
        if (q == p) return 1;
        if (2 * q == p) return 2;
        
        pair<double, double> st(0.0, 0.0);
        pair<double, double> en(p, q);
        //return 2;
        bool find = false; int angl = 1;
        while (!find) {
            double k = -(en.second - st.second) / (en.first - st.first);
            double b = en.second  - k * en.first;
            
            st.first = en.first; st.second = en.second;

            pair<double, double> p1 = angle((angl + 1) % 4, k, b, p);
            pair<double, double> p2 = angle((angl + 2) % 4, k, b, p);
            pair<double, double> p3 = angle((angl + 3) % 4, k, b, p);
                
            if (p1.first <= p && p1.first >= 0 && p1.second <= p && p1.second >= 0) {
                en.first = p1.first;
                en.second = p1.second; 
                angl = (angl + 1) % 4;
            }
            else if (p2.first <= p && p2.first >= 0 && p2.second <= p && p2.second >= 0) {
                en.first = p2.first;
                en.second = p2.second; 
                angl = (angl + 2) % 4;
            }
            else {
                en.first = p3.first;
                en.second = p3.second;
                angl = (angl + 3) % 4;
            }
                
            if (abs(en.first - p) < 0.01 && en.second == 0) return 0;
            if (abs(en.first - p) < 0.01 && abs(en.second - p) < 0.01) return 1;
            if (en.first == 0 && abs(en.second - p) < 0.01) return 2;
            if (en.first == 0 && en.second == 0) return -1;
        }
        
        return -1;
    }
    
    pair<double, double> angle(int ang, double k, double b, int p) {
        pair<double, double> res(0.0, 0.0);
        
        if (ang == 0) {
            res.first = -b / k;
            res.second = 0.0;
        } 
        else if (ang == 1) {
            res.first = p;
            res.second = k * p + b;
        } 
        else if (ang == 2) {
            res.first = (p - b) / k;
            res.second = p;
        }
        else {
            res.first = 0.0;
            res.second = b;
        }
        
        return res;
    }
};
