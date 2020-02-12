// case 1: len <= k; case 2 : len <= 2*k; case 3 : len > 2*k
#include <algorithm>
class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        string s2;
        if (k >= length)
        {
            reverse(s.begin(), s.end());
            return s;
        }
        else if (2 * k >= length)
        {
            string s_left = s.substr(0, k);
            reverse(s_left.begin(), s_left.end());
            string s_1 = s_left + s.substr(k, length);
            return s_1;
        }
        else
        {
            string s_left = s.substr(0, k);
            reverse(s_left.begin(), s_left.end());
            string s2 = s_left + s.substr(k, k);
            s2 += reverseStr(s.substr(2*k, length), k);
            return s2;
        }      
    } 
};

// ==========================================================
// Demo
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
string reverseStr(string s, int k);

int main()
{
	string s = "0123 4567 89asd fghj kl";
    cout << s << endl;
	cout << reverseStr(s, 5) << endl;
    return 0;
}

string reverseStr(string s, int k) {
        int length = s.size();
        cout << "start s : \n" << s << endl;
        string s2;

        if (k >= length)
        {
            reverse(s.begin(), s.end());
            cout << "case 1: " << s << endl;
            return s;
        }
        else if (2 * k >= length)
        {
            string s_left = s.substr(0, k);
            reverse(s_left.begin(), s_left.end());
            string s_1 = s_left + s.substr(k, length);
            cout << "case 2: " << s_1 << endl;
            return s_1;
        }
        else
        {
            string s_left = s.substr(0, k);
            reverse(s_left.begin(), s_left.end());
            string s2 = s_left + s.substr(k, k);
            s2 += reverseStr(s.substr(2*k, length), k);
            cout << "s2: \n" << s2 << endl;
            return s2;
        }
    }
