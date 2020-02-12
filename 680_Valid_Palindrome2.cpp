// case 1 : Del left; case 2 : Del right.
class Solution {
public:
    bool validPalindrome(string s) {
        int length = s.size();
        if (length <= 2) return true; 
        bool pali_l = true;
        bool pali_r = true;
        bool ifdel = false;
        int lp = 0;
        int rp = length - 1;
        // Left
        while (lp < rp)
        {
            if (s[lp] != s[rp])
            {
                if (ifdel)
                {
                    pali_l = false;
                    break;
                }
                else if (s[lp+1] == s[rp])
                {
                    ifdel = true;
                    cout << "lp + 1: " << lp+1 << " s[lp+1]: " << s[lp+1] << endl;
                    lp += 1;
                }
                else
                {
                    pali_l = false;
                    break;
                }
            }
            lp++;
            rp--;
        }
        // Right
        ifdel = false;
        lp = 0;
        rp = length - 1;
        while (lp < rp)
        {
            if (s[lp] != s[rp])
            {
                if (ifdel)
                {
                    pali_r = false;
                    break;
                }
                else if (s[lp] == s[rp-1])
                {
                    ifdel = true;
                    cout << "rp - 1: " << rp-1 << " s[rp-1]: " << s[rp-1] << endl;
                    rp -= 1;

                }
                else
                {
                    pali_r = false;
                    break;
                }
            }
            lp++;
            rp--;
        }
        bool pali = pali_l || pali_r;
        return pali;
    }
};

//=====================================================
// Demo

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool validPalindrome(string s);

int main()
{
    string str;
    cin >> str;
    cout << validPalindrome(str) << endl;
    return 0;
}

    bool validPalindrome(string s) {
        int length = s.size();
        if (length <= 2) return true;
        cout << "length: " << length << endl;

        //bool pali = true;
        bool pali_l = true;
        bool pali_r = true;
        bool ifdel = false;

        int lp = 0;
        int rp = length - 1;
        // Left
        while (lp < rp)
        {
            if (s[lp] != s[rp])
            {
                if (ifdel)
                {
                    pali_l = false;
                    break;
                }
                else if (s[lp+1] == s[rp])
                {
                    ifdel = true;
                    cout << "lp + 1: " << lp+1 << " s[lp+1]: " << s[lp+1] << endl;
                    lp += 1;
                }
                else
                {
                    pali_l = false;
                    break;
                }
            }
            lp++;
            rp--;
        }
        // Right
        ifdel = false;
        lp = 0;
        rp = length - 1;
        while (lp < rp)
        {
            if (s[lp] != s[rp])
            {
                if (ifdel)
                {
                    pali_r = false;
                    break;
                }
                else if (s[lp] == s[rp-1])
                {
                    ifdel = true;
                    cout << "rp - 1: " << rp-1 << " s[rp-1]: " << s[rp-1] << endl;
                    rp -= 1;

                }
                else
                {
                    pali_r = false;
                    break;
                }
            }
            lp++;
            rp--;
        }
        bool pali = pali_l || pali_r;
        return pali;
    }

    //  aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga
