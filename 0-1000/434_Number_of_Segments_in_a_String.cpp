// while(pos2 != string::npos && pos2 - pos1 < 2)
// {  pos1 = pos2;
//    pos2 = s.find(' ', pos1 + 1);}

class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        if(len == 0) return 0;
        
        int counter = 0;
        
        string::size_type pos1 = s.find(' ');
        string::size_type pos2 = s.find(' ', pos1 + 1);
        if (pos1 > 0) counter++;
        
        while (pos2 != string::npos)
        {
            while(pos2 != string::npos && pos2 - pos1 < 2)
            {
                pos1 = pos2;
                pos2 = s.find(' ', pos1 + 1);
            }
            if (pos2 == string::npos)
            {
                if (pos1 >= len - 1) return counter;
                else {
                    counter++;
                    return counter;
                }
            }
            counter++;
            pos1 = pos2;
            pos2 = s.find(' ', pos1 + 1);    
        }
        if (pos1 < len - 1) counter++;
        return counter;
    }
};

// =========================================
//Demo
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
bool validPalindrome(string s);

int main()
{
    string S = "foo    bar";
    
    int len = S.size();
    if(len == 0)
    {
        cout << "Null!";
        return 0;
    }
    int counter = 0;
    
    string::size_type pos1 = S.find(' ');
    string::size_type pos2 = S.find(' ', pos1 + 1);
    if (pos1 > 0) counter++;

    while (pos2 != string::npos)
    {
        while(pos2 != string::npos && pos2 - pos1 < 2)
        {
            pos1 = pos2;
            pos2 = S.find(' ', pos1 + 1);
        }
        if (pos2 == string::npos)
        {
            if (pos1 = len - 1) break;
            else {
                counter++;
                break;
            }
        }
            
            counter++;
            pos1 = pos2;
            pos2 = S.find(' ', pos1 + 1);
        }
        if (pos1 < len - 1) counter++;
        cout << "Counter : " << counter << endl;
    return 0;
}
