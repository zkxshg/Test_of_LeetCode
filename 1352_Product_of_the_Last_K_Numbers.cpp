// https://leetcode.com/problems/product-of-the-last-k-numbers/
// Design

class ProductOfNumbers {
public:
    #define ll long long
    vector<ll> PP;
    
    ProductOfNumbers() {
        PP.clear();
    }
    
    void add(int num) {
        if (!num) PP.clear();
        else {
            if (PP.empty()) PP.push_back(num);
            else PP.push_back(PP.back() * num);
        }
        // for (int i : PP) cout << i << ","; cout << endl;
    }
    
    int getProduct(int k) {
        if (PP.size() < k) return 0;
        
        if (PP.size() == k) return PP.back();
        
        return PP.back() / PP[PP.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
