// string
class Solution {
public:
    string reformatNumber(string number) {
        vector<char> pureNum;
        for (char ch : number) {
            if (ch >='0' && ch <= '9') pureNum.push_back(ch);
        }
        
        int len = pureNum.size();
        vector<string> blocks;
        for (int i = 0; i < len; i+=3) {
            if (i + 3 >= len) {
                string tem = "";
                for (int j = i; j <len; j++) tem += pureNum[j];
                blocks.push_back(tem);
            }
            else {
                string tem = "";
                tem += pureNum[i]; tem += pureNum[i + 1]; tem += pureNum[i + 2];
                blocks.push_back(tem);
            }
        }
        
        if (blocks.back().size() < 2 && blocks.size() > 1)  {
            blocks.back() = blocks[blocks.size() - 2][2] + blocks.back();
            blocks[blocks.size() - 2] =  blocks[blocks.size() - 2].substr(0, 2);
        }
        
        string res = "";
        for (int i = 0; i < blocks.size() - 1; i++) {
            res += blocks[i];
            res += "-";
        }
        res += blocks.back();
        return res;
    }
};
