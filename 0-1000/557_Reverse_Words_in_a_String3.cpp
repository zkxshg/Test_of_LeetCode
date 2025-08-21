// reverse(s.begin(), s.end());
// pos = s2.find(' ', pos+1);
// for (int i = start; i < pos; i++) s2[i] = s[len];

#include <algorithm>
class Solution {
public:
    string reverseWords(string s) {
        int length = s.size();
        string s2 = s;
        reverse(s.begin(), s.end());
        int start = 0;
	    string::size_type pos = s2.find(' ');

	    while (pos < length)
        {
            int len = 0;
            for (int i = start; i < pos; i++)
            {
                s2[i] = s[length-pos+len];
                len++;
            }
            start = pos + 1;
            pos = s2.find(' ', pos+1);
        }
        int len = 0;
        for (int i = start; i < length; i++)
        {
            s2[i] = s[len];
            len++;
        }
        return s2;
    }
};

//=================================================
// Demo

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
bool validPalindrome(string s);

int main()
{
	string s = "0123 4567 89asd fghj kl";
	string s2 = s;
	//cout << s << endl;
	reverse(s.begin(), s.end());
	cout << s << endl;
	cout << s2 << endl;
	int length = s.size();

	int start = 0;
	string::size_type pos = s2.find(' ');

	while (pos < length)
    {
        int len = 0;
        for (int i = start; i < pos; i++)
        {
            s2[i] = s[length-pos+len];
            len++;
        }
        start = pos + 1;
        pos = s2.find(' ', pos+1);
    }
    int len = 0;
    for (int i = start; i < length; i++)
    {
        s2[i] = s[len];
        len++;
    }
    cout << s2 << endl;
    return 0;
}
