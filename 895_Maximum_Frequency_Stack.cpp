// hash table + stacks
class FreqStack {
public:
    unordered_map<int, int> fre;
    vector<vector<int> > sts;
    int maxV;
    
    
    FreqStack() {
        fre.clear(); 
        sts.clear(); 
        sts.resize(10000);
        maxV = 0;
    }
    
    void push(int x) {
        fre[x]++;
        sts[fre[x]].push_back(x);
        if (fre[x] > maxV) maxV = fre[x];
    }
    
    int pop() {
        int mx = sts[maxV].back();
        sts[maxV].pop_back();
        fre[mx]--;
        
        while (maxV >= 0 && sts[maxV].empty()) maxV--;
        
        return mx;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
