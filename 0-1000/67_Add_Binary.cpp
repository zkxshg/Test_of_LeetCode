// brute-force if-else
class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size();
        int lenb = b.size();
        if (lena == 0) return b;
        else if (lenb == 0) return a;
        
        if (lena < lenb){
            string temp = b;
            b = a;
            a = temp; 
        }
        
        lena = a.size();
        lenb = b.size();
        
        string bplus((lena - lenb), '0');
        b = bplus + b;
        
        string c(lena+1, '0');
        
        for (int i2 = 1; i2 < lena + 1; i2++){
            int i = lena - i2;
            if (a[i] == '1' && b[i] == '0' && c[i+1] == '0') c[i+1] = '1';
            else if (a[i] == '0' && b[i] == '1' && c[i+1] == '0') c[i+1] = '1';
            else if (a[i] == '1' && b[i] == '1' && c[i+1] == '0') c[i] = '1';
            else if (a[i] == '1' && b[i] == '0' && c[i+1] == '1') {
                c[i+1] = '0';
                c[i] = '1';
            }
            else if (a[i] == '0' && b[i] == '1' && c[i+1] == '1') {
                c[i+1] = '0';
                c[i] = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && c[i+1] == '1') {
                c[i+1] = '1';
                c[i] = '1';
            }
        }
        if (c[0] == '0') c = c.substr(1, c.size()-1);
        return c;
    }
};
