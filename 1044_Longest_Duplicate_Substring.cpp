// https://leetcode.com/problems/longest-duplicate-substring/
// suffix array + LCP
class Solution {
public:
    struct suffix {
        int index;  
        int rank[2];
    };
    
    string longestDupSubstring(string S) {
        if (S.size() == 0) return "";
        
        vector<int> suffixArr = buildSuffixArray(S);
        vector<int>lcp = kasai(S, suffixArr);
        
        int maxV = 0, pos = 0;
        for (int i = 0; i < S.size(); i++) {
            if (lcp[i] > maxV) {
                maxV = lcp[i];
                pos = i;
            }
        }
        
        if (maxV == 0) return "";
        return S.substr(pos, maxV);   
    }
    
    static int cmp(struct suffix a, struct suffix b) {
        return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
    }
    
    vector<int> buildSuffixArray(string A) {
        int n = A.size();
        struct suffix * suffixes = new suffix[n];
        for (int i = 0; i < n; i++) {
            suffixes[i].index = i;
            suffixes[i].rank[0] = A[i] - 'a';
            suffixes[i].rank[1] = ((i + 1) < n) ? (A[i + 1] - 'a') : -1;
        }
        
        sort(suffixes, suffixes + n, cmp);

        int * ind = new int[n];  
        for (int k = 4; k < 2 * n; k = k * 2) {
            int rank = 0;
            int prev_rank = suffixes[0].rank[0];
            suffixes[0].rank[0] = rank;   
            ind[suffixes[0].index] = 0;

            for (int i = 1; i < n; i++) {
                if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = rank;
                } else {
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = ++rank;
                }
                ind[suffixes[i].index] = i;
            }

            for (int i = 0; i < n; i++) {
                int nextindex = suffixes[i].index + k / 2;
                suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
            }
            sort(suffixes, suffixes + n, cmp);
        }

        vector<int> suffixArr;
        for (int i = 0; i < n; i++) suffixArr.push_back(suffixes[i].index);

        delete[] ind;
        delete[] suffixes;
        return  suffixArr;
    }
    
    vector<int> kasai(string A, vector<int> suffixArr) {
        int n = A.size();
        vector<int> lcp(n, 0);
        
        vector<int> invSuff(n, 0);
        for (int i = 0; i < n; i++) invSuff[suffixArr[i]] = i;
        
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (invSuff[i] == n - 1) {
                k = 0;
                continue;
            } 
            int j = suffixArr[invSuff[i] + 1];
            while (i + k < n && j + k < n && A[i + k] == A[j + k]) k++;
            lcp[i] = k;  
            if (k > 0) k--;
        }
        return lcp;
    }
};
