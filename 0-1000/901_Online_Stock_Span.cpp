// stack
class StockSpanner {
public:
    vector<int> stock;
    vector<int> sCount;
    StockSpanner() {
        stock.clear();
        sCount.clear();
    }
    int next(int price) {
        int cou = 1;
        while (stock.size() > 0 && price >= stock.back()) {
            cou += sCount.back();
            sCount.pop_back();
            stock.pop_back();
        }
        sCount.push_back(cou);
        stock.push_back(price);
        return cou;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
