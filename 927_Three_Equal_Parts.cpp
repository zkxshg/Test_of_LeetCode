// https://leetcode.com/problems/three-equal-parts/
// two pointers

class Solution {
public:
    int ifEql(int a1, int a2, int b1, int b2, vector<int>& A) {
        int n = a2 - a1 + 1, m = b2 - b1 + 1;
        if (n < m) {
            for (int i = 0; i < m - n; i++) 
                if (A[b1 + i])
                    return -1;
            
            for (int i = n - 1; i >= 0; i--)
                if (A[a2 - i] != A[b2 - i])
                    return A[a2 - i] ? 1 : -1;
        }
        else {
            for (int i = 0; i < n - m; i++) 
                if (A[a1 + i])
                    return 1;
            
            for (int i = m - 1; i >= 0; i--)
                if (A[a2 - i] != A[b2 - i])
                    return A[a2 - i] ? 1 : -1;
        }
        return 0;
    }
    
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        
        int i = 0, j = n - 1;
        
        while (i + 1 < j) {
            int iq = ifEql(0, i, j, n - 1, arr); 
            //cout << iq << ":" << i << "," << j << endl;
            
            if (iq < 0)  i++;
            else if (!iq && !ifEql(0, i, i + 1, j - 1, arr)) return {i, j};
            else j--;
            
        }
        
        return {-1,-1};
        
    }
};

// Tracing back
class Solution {
public:
    int ifEql(string& a, string& b) {
        int n = a.size(), m = b.size();
        if (n < m) {
            for (int i = n + 1; i <= m; i++) 
                if (b[m - i] - '0')
                    return -1;
            for (int i = n; i >= 1; i--)
                if (a[n - i] != b[m - i])
                    return (a[n - i]  - '0') ? 1 : -1;
        }
        else {
            for (int i = m + 1; i <= n; i++) 
                if (a[n - i] - '0')
                    return 1;
            for (int i = m; i >= 1; i--)
                if (a[n - i] != b[m - i])
                    return (a[n - i]  - '0') ? 1 : -1;
        }
        return 0;
    }
    
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        
        int i = 0, j = 2;
        string a = "", b = "", c = "";
        
        a += '0' + arr[i];
        for (int k = i + 1; k < j; k++) b += '0' + arr[k];
        for (int k = j; k < n; k++) c += '0' + arr[k];
        
        while (j < n) {
            
            while (i + 1 >= j && j < n) {
                b += '0' + arr[j]; 
                c = c.substr(1);
                j++;
            }
            //cout << a << "," << b << "," << c << endl;
            int iq = ifEql(a, b); 
            while (iq > 0 && j < n) { 
                b += '0' + arr[j];  
                c = c.substr(1);
                j++;
                iq = ifEql(a, b); 
            }
            
            if (!ifEql(a, b) && !ifEql(a, c)) return {i, j};

            i++; 
            a += '0' + arr[i]; 
            b = b.substr(1);
            //cout << i << "," << j << endl;
        }
        
        return {-1,-1};
        
    }
};
