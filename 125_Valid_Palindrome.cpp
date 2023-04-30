// https://leetcode.com/problems/valid-palindrome/
// Filter("a-z", "A-Z", "0-9")
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.size();
        if (length == 0) return true;
        int len = 0;
        string alphastr[length];
        for (int i = 0; i < length; i++)
        {
            if ('a' <= char(s[i]) && char(s[i]) <= 'z') 
            {
                alphastr[len] = s[i];
                len++;
            } 
            else if ('A' <= char(s[i]) && char(s[i]) <= 'Z')
            {
                alphastr[len] = tolower(s[i]);
                len++;
            }
            else if ('0' <= char(s[i]) && char(s[i]) <= '9')
            {
                alphastr[len] = s[i];
                len++;
            }
        }
        if (len == 0 || len == 1) return true;
        bool pali = true;
        for (int i = 0; i < len / 2; i++) 
        {
           if (alphastr[i] != alphastr[len - i - 1]) 
           {
               pali = false;
               break;
           } 
        }
        return pali;    
    }
};

//===============================================
// Demo
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool isPalindrome(string s);

int main()
{
    string str;
    cout << int('0') << " " << int('1') << " " << int('9') << " \n" ;
    //cin >> str;
    //cout << isPalindrome(str) << endl;
    return 0;
}

    bool isPalindrome(string s) {

        int length = s.size();
        if (length == 0) return true;

        int len = 0;
        string alphastr[length];

        for (int i = 0; i < length; i++)
        {
            if ('a' <= char(s[i]) && char(s[i]) <= 'z')
            {
                alphastr[len] = s[i];
                len++;
            }
            else if ('A' <= char(s[i]) && char(s[i]) <= 'Z')
            {
                alphastr[len] = tolower(s[i]);
                len++;
            }
            else if ('0' <= char(s[i]) && char(s[i]) <= '9')
            {
                alphastr[len] = s[i];
                len++;
            }
        }

        if (len == 0 || len == 1) return true;

        bool pali = true;
        cout << alphastr;
        for (int i = 0; i < len / 2; i++)
        {
           if (alphastr[i] != alphastr[len - i - 1])
           {
               pali = false;
               break;
           }
        }

        return pali;
    }

