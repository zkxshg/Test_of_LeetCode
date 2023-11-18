// https://leetcode.com/problems/defanging-an-ip-address/
// string::size_type pos = line.find('.');
// line=line.replace(pos,1,"[.]");
class Solution {
public:
    string defangIPaddr(string line) {
        string::size_type pos = line.find('.');
	line=line.replace(pos,1,"[.]");
	    
	string::size_type pos2 = line.find('.', pos+2);
        line=line.replace(pos2,1,"[.]");
	    
        string::size_type pos3 = line.find('.', pos2+2);
        line=line.replace(pos3,1,"[.]");
        return line;
    }
};
