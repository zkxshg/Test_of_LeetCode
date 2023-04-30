// string
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        vector<int> s1;
        vector<int> s2;
        
        // string to array
        int pos = 0, nex = version1.find('.');
        while (pos < len1) {
            if (nex == version1.npos) nex = len1;
            
            int tem = 0;
            for (int i = nex - 1; i >= pos; i--) tem += pow(10, nex - 1 - i) * (version1[i] - '0');
            s1.push_back(tem);
            
            pos = nex + 1;
            nex = version1.find('.', pos);
        }
        
        pos = 0, nex = version2.find('.');
        while (pos < len2) {
            if (nex == version1.npos) nex = len2;
            
            int tem = 0;
            for (int i = nex - 1; i >= pos; i--) tem += pow(10, nex - 1 - i) * (version2[i] - '0');
            s2.push_back(tem);
            
            pos = nex + 1;
            nex = version2.find('.', pos);
        }
        
        // fill the shorter
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2) {
            for (int i = l2; i < l1; i++) s2.push_back(0);
        }
        else if (l1 < l2) {
            for (int i = l1; i < l2; i++) s1.push_back(0);
        }
        
        // compare
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            if (s1[i] > s2[i]) return 1;
            if (s1[i] < s2[i]) return -1;
        }
        
        return 0;   
    }
};
