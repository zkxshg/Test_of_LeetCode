// https://leetcode.com/problems/repeated-dna-sequences
// LCP
class Solution {
public:

    struct suffix {
        int index;  
        int rank[2]; 
    };

    static int cmp(struct suffix a, struct suffix b) {
        return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
            (a.rank[0] < b.rank[0] ? 1 : 0);
    }
    
   vector<int> buildSuffixArray(int* A, int n) {
       struct suffix * suffixes = new suffix[n]; 
       
       for (int i = 0; i < n; i++) {
           suffixes[i].index = i;
           suffixes[i].rank[0] = A[i];
           suffixes[i].rank[1] = ((i + 1) < n) ? (A[i + 1]) : -1;
       }
       sort(suffixes, suffixes + n, cmp);
       
       int * ind = new int[n];   
       for (int k = 4; k < 2 * n; k = k * 2) {
           int rank = 0;
           int prev_rank = suffixes[0].rank[0];
           suffixes[0].rank[0] = rank;   
           ind[suffixes[0].index] = 0;
           
           for (int i = 1; i < n; i++) {
               if (suffixes[i].rank[0] == prev_rank &&
                   suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
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
    
    vector<int> kasai(int* A, vector<int> suffixArr) {
        int n = suffixArr.size();
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
    
    int* str2Arr(string s) {
        int len = s.size();
        int* arr = new int[len];
        for (int i = 0; i < len; i++) {
            char ch = s[i];
            if (ch == 'A') arr[i] = 1;
            else if (ch == 'T') arr[i] = 2;
            else if (ch == 'C') arr[i] = 3;
            else arr[i] = 4;
        }
        return arr;
    }
    
    string arr2str (vector<int> arr) {
        string s = "";
        for (int i : arr) {
            if (i == 1) s += 'A';
            else if (i == '2') s += 'T';
            else if (i == '3') s += 'C';
            else s += 'G';
        } 
        return s;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int len = s.size(); if (len < 11) return result;
        
        string s_inv = s;
        reverse(s_inv.begin(), s_inv.end());
        
        int* arr = str2Arr(s_inv);
        
        vector<int> suffixArr = buildSuffixArray(arr, len);
        int Sn = suffixArr.size();
        
        vector<int>lcp = kasai(arr, suffixArr);
        reverse(lcp.begin(), lcp.end());
        
        //for (int lc : lcp) result.push_back(to_string(lc));
        //return result;
        
        unordered_map<string, int> strDict;
        for (int i = 0; i < len; i++) {
            if(lcp[i] >= 10) {
                string tempS(s.begin() + i - 9, s.begin() + i + 1);

                if (strDict.count(tempS) == 0) {
                    result.push_back(tempS);
                    strDict[tempS] = 1;
                }
            }
        }
        
        return result;
    }
};
