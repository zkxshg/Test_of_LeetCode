// https://leetcode.com/problems/flatten-nested-list-iterator/
// design + recursive
class NestedIterator {
public:
    vector<NestedInteger> aim;
    vector<int> flat;
    int pos;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        aim = nestedList;
        
        flat.clear();
        flatten(aim);
        
        pos = 0;
    }
    
    int next() {
        pos++;
        return flat[pos - 1];
    }
    
    bool hasNext() {
        if (pos < flat.size()) return true;
        return false;
    }
    
    void flatten(vector<NestedInteger>& NL) {
        for (NestedInteger NI : NL) {
            if (NI.isInteger()) flat.push_back(NI.getInteger());
            else flatten(NI.getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
