// design
class OrderedStream {
public:
    vector<string> Stream;
    int ptr;
    
    OrderedStream(int n) {
        Stream.clear();
        Stream.resize(n);   
        ptr = 0;
    }
    
    vector<string> insert(int id, string value) {
        Stream[id - 1] = value;
        
        vector<string> res;
        while(ptr < Stream.size() && Stream[ptr].size() > 0) {
            res.push_back(Stream[ptr]);
            ptr++;
        }
        
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
