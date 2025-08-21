// https://leetcode.com/problems/smallest-number-in-infinite-set/description/
// heap

class SmallestInfiniteSet {
public:
    vector<int> hp;
    int cnt;
    unordered_map<int, int> fre;

    SmallestInfiniteSet() {
        cnt = 1;
        
        hp.push_back(cnt);
        make_heap(hp.begin(), hp.end(), greater<int>());

        fre[cnt]++; 
    }
    
    int popSmallest() {
        int res = hp.front();

        pop_heap(hp.begin(), hp.end(), greater<int>()); 
        hp.pop_back(); 
        fre[res] = 0;

        if (res == cnt) {
            cnt++;
            hp.push_back(cnt);
            push_heap(hp.begin(), hp.end(), greater<int>());
            fre[cnt]++;
        }

        return res;
    }
    
    void addBack(int num) {
        if (num < cnt && !fre[num]) {
            hp.push_back(num);
            push_heap(hp.begin(), hp.end(), greater<int>());
            fre[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
