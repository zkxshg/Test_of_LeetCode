// vowel.find(temp[0]) != string::npos

class Solution {
public:
    string toGoatLatin(string S) {
        int length = S.size();
        string vowel = "aeiouAEIOU";
        string result = "";
        int start = 0;
        string::size_type pos = S.find(' ');
        int cletter = 1;
        while (pos != string::npos)
        {
            string temp = S.substr(start, pos - start);
            if (vowel.find(temp[0]) != string::npos)
                temp += "ma";
            else
                temp = temp.substr(1, temp.size() - 1) + temp[0] + "ma";
            for (int i = 0; i < cletter; i++)
                temp += 'a';
            result += temp;
            result += " ";
            start = pos + 1;
            pos = S.find(' ', pos+1);
            cletter += 1;
        }
        string temp = S.substr(start, length - start);
        if (vowel.find(temp[0]) != string::npos)
            temp += "ma";
        else
            temp = temp.substr(1, temp.size() - 1) + temp[0] + "ma";
        for (int i = 0; i < cletter; i++)
            temp += 'a';
        result += temp;
        return result;
    }
};

// ===================================================
// Demo
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
bool validPalindrome(string s);

int main()
{
        string S = "The quick brown fox jumped over the lazy dog";
        cout << S << endl;
        int length = S.size();

        string vowel = "aeiouAEIOU";
        string result = "";

        int start = 0;
        string::size_type pos = S.find(' ');
        int cletter = 1;

        while (pos != string::npos)
        {
            string temp = S.substr(start, pos - start);

            if (vowel.find(temp[0]) != string::npos)
                temp += "ma";
            else
                temp = temp.substr(1, temp.size() - 1) + temp[0] + "ma";
            for (int i = 0; i < cletter; i++)
                temp += 'a';
            cout << "temp : \n" << temp << endl;
            result += temp;
            result += " ";

            start = pos + 1;
            pos = S.find(' ', pos+1);
            cletter += 1;
        }

        string temp = S.substr(start, length - start);

        if (vowel.find(temp[0]) != string::npos)
            temp += "ma";
        else
            temp = temp.substr(1, temp.size() - 1) + temp[0] + "ma";
        for (int i = 0; i < cletter; i++)
            temp += 'a';
        cout << "temp : \n" << temp << endl;
        result += temp;
        result += " ";

        cout << "Result : \n" << result << endl;
    return 0;
}

