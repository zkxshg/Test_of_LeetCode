// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10
// Sorting + Simulation

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end()); // Sort the deck to reveal in increasing order
        int n = deck.size();
        deque<int> indices;
        vector<int> result(n);
        
        // Initialize indices with 0, 1, ..., n-1
        for (int i = 0; i < n; ++i) {
            indices.push_back(i);
        }
        
        // Simulate the card revealing process
        for (int card : deck) {
            result[indices.front()] = card; // Place the next smallest card at the front
            indices.pop_front(); // Remove the revealed index
            
            if (!indices.empty()) {
                // Move the next index to the back of the deque
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        
        return result;
    }
};
