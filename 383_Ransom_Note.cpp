// while(ransomNote.size() > 0 && pos != string::npos)  pos = magazine.find(ransomNote[0]);
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() == 0) return true;
        if(magazine.size() == 0) return false;
        bool canConst = true;
        string::size_type pos = magazine.find(ransomNote[0]);
        while(ransomNote.size() > 0 && pos != string::npos)
        {
            ransomNote = ransomNote.substr(1, ransomNote.size()-1);
            magazine=magazine.substr(0,pos) + magazine.substr(pos+1, magazine.size()-pos-1);
            pos = magazine.find(ransomNote[0]);
        }
        if (ransomNote.size()==0) return true;
        else return false; 
    }
};
