// same to 275. H-Index II
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        
        if (len == 0) return 0;
        
        if (len == 1) {
            if (citations[0] >= 1) return 1;
            else return 0;
        }
        
        sort(citations.begin(), citations.end());
        
        int result = searchH(citations, 0, len - 1, len);
        return result;
        
    }
    
    int searchH(vector<int>& cits, int start, int last, int len) {
        if (start == last) {
            if (len - start <= cits[start]) return len - start;
            return 0;
        }
        
        unsigned int mid = (last + start) / 2;
        int tempH = 0;
        
        if (len - mid == cits[mid]) return len - mid;
        else if (len - mid < cits[mid]) {
            tempH = len - mid;
            int leftH = searchH(cits, start, mid, len);
            if (leftH > tempH) tempH = leftH;
        }
        else tempH = searchH(cits, mid+1, last, len);
        
        return tempH;
    }
};
