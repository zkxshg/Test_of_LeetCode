// stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int len = asteroids.size(); if (len < 2) return asteroids;
        
        vector<int> result; result.push_back(asteroids[0]);
        
        int i = 1;
        while (i < len) {
            if (result.empty()) result.push_back(asteroids[i]);
            else if (Sgn(result.back()) == Sgn(asteroids[i])) result.push_back(asteroids[i]);
            else if (!Sgn(result.back()) && Sgn(asteroids[i]))  result.push_back(asteroids[i]);
            else if (abs(result.back()) == abs(asteroids[i])) result.pop_back();
            else if (!ifColl(result.back(), asteroids[i])){
                result.pop_back();
                i--;
            }
            
            i++;
        }
        
        return result;
    }
    
    bool Sgn(int a) {
        return (a >= 0);
    }
    
    bool ifColl(int a, int b) {
        return (abs(a) > abs(b));
    }
};
