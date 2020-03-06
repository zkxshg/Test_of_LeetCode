// Iterations
class Solution {
public:
    string countAndSay(int n) {
        string result = "111221";
        readoff(n, &result);
        return result;
    }
    void readoff(int n, string * res){
        if (n == 1) (*res) = "1";
        else if (n == 2) (*res) = "11";
        else if (n == 3) (*res) = "21";
        else if (n == 4) (*res) = "1211";
        else if (n == 5) (*res) = "111221";
        else{
            readoff(n-1, res);
            string pre = (*res);
            int len = pre.size();
        
            string rest = "";
            int start = 0;
            int pos = 1;
            while (pos < len){
                while (pos < len && pre[start] == pre[pos]) pos++;
                rest += to_string(pos - start);
                rest += pre[start];
                start = pos;
                pos++;
                if (start == len - 1){
                    rest += "1";
                    rest += pre[start];
                }
            }
            (*res) = rest;
        }
    }
};
