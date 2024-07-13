//https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2024-07-13
// Sorting + Stack (0.5h)

class Solution {
public:
    #define pii pair<int, int>

    void checkVector(const vector<pii>& vec) {
        cout << "Vector size: " << vec.size() << endl;
        cout << "Vector contents:" << endl;
        for (const auto& p : vec) {
            cout << "(" << p.first << ", " << p.second << ")" << ",";
        }
        cout << endl;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int, int> order;
        
        // Using vector of pii to store robots with adjusted healths
        vector<pii> robots;
        for (int i = 0; i < n; ++i) {
            int pos = positions[i];
            int health = healths[i];
            if (directions[i] == 'R') {
                health = -health; // Reverse health for robots moving right
            }
            robots.push_back({pos, health});

            order[pos] = i;
        } 
        
        // Sort robots
        sort(robots.begin(), robots.end());
        // checkVector(robots);
        
        // Use a stack to simulate surviving robots
        vector<pii> stack;
        
        for (auto& robot : robots) {
            int position = robot.first;
            int health = robot.second;
            
            // While stack not empty and the top robot can collide
            while (!stack.empty() && stack.back().second < 0 && health > 0) {
                // Collide with the top robot in stack
                int& top_health = stack.back().second;
                if (top_health + health < 0) {
                    // Current robot survives, adjust health of top robot
                    top_health += 1;
                    health = 0; // Current robot's health reduced to 0
                    break;
                } else if (top_health + health == 0) {
                    // Both robots are removed
                    stack.pop_back();
                    health = 0;
                    break;
                } else {
                    // Top robot survives, adjust health of current robot
                    health -= 1;
                    stack.pop_back();
                }
            }
            
            if (health != 0) {
                // If current robot survives, push it into the stack
                stack.push_back({position, health});
            }
        }
        
        // Extract surviving robots' healths in the order of their original positions
        for (auto& s : stack) s.first = order[s.first];
        sort(stack.begin(), stack.end());

        vector<int> result;
        for (auto& s : stack) {
            result.push_back(abs(s.second));
        }
        // checkVector(stack);
        
        return result;
    }
};
