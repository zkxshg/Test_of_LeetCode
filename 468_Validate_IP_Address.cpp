// brute-force
class Solution {
public:
    string validIPAddress(string IP) {
        int head = 0, pos;
        pos = IP.find('.'); string result = "";
        
        if (pos != IP.npos) {
            if (IP.find(':') != IP.npos) return "Neither";
            
            string subadd = IP.substr(head, pos - head);
            for (char ch : subadd) {if (ch < '0' || ch > '9') return "Neither";}
            if (subadd[0] == '0' && subadd.size() > 1) return "Neither";
            if (subadd.size() < 1 || subadd.size() > 3 || stoi(subadd) > 255) return "Neither";
            
            
            head = pos + 1; pos = IP.find('.', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head);
            for (char ch : subadd) {if (ch < '0' || ch > '9') return "Neither";}
            if (subadd[0] == '0' && subadd.size() > 1) return "Neither";
            if (subadd.size() < 1 || subadd.size() > 3 || stoi(subadd) > 255) return "Neither";
            
            
            head = pos + 1; pos = IP.find('.', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head);
            for (char ch : subadd) {if (ch < '0' || ch > '9') return "Neither";}
            if (subadd[0] == '0' && subadd.size() > 1) return "Neither";
            if (subadd.size() < 1 || subadd.size() > 3 || stoi(subadd) > 255) return "Neither";
            
            
            head = pos + 1; pos = IP.find('.', head); if (pos != IP.npos) return "Neither";
            subadd = IP.substr(head, IP.size() - head);
            for (char ch : subadd) {if (ch < '0' || ch > '9') return "Neither";}
            if (subadd[0] == '0' && subadd.size() > 1) return "Neither";
            if (subadd.size() < 1 || subadd.size() > 3 || stoi(subadd) > 255) return "Neither";
            
            
            return "IPv4";
            
        }
        else {
            pos = IP.find(':');
            if (pos == IP.npos) return "Neither";
            
            string subadd = IP.substr(head, pos - head);
            if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
            for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            head = pos + 1; pos = IP.find(':', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head); if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
            for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            head = pos + 1; pos = IP.find(':', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head); if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
            for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            head = pos + 1; pos = IP.find(':', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head); if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
            for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            head = pos + 1; pos = IP.find(':', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head); if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
            for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            head = pos + 1; pos = IP.find(':', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head); if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
            for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            head = pos + 1; pos = IP.find(':', head); if (pos == IP.npos) return "Neither";
            subadd = IP.substr(head, pos - head); if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
            for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            head = pos + 1; pos = IP.find(':', head); if (pos != IP.npos) return "Neither";
            subadd = IP.substr(head, IP.size() - head); 
            if (subadd.size() < 1 || subadd.size() > 4) return "Neither";
           for (char ch : subadd) {
                if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'f')||(ch >= 'A' && ch <= 'F')) continue; 
                else return "Neither";}
            
            return "IPv6";
            
        }
        return "Neither";
    }
};
