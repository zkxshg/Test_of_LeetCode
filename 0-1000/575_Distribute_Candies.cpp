// hash table
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int kindNum = 0, canNum = candies.size(); 
        unordered_map<int, int> canKind;
        for (int candy : candies) {
            if (!canKind[candy]) {
                canKind[candy]++;
                kindNum++;
            }
        }
        if (kindNum >= canNum / 2) return canNum / 2;
        return kindNum;
    }
};
