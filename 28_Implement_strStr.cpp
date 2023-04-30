// https://leetcode.com/problems/implement-strstr/
// KMP algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenh = haystack.size();
        int lens = needle.size();
        // Special case
        if (!lens) return 0; 
        else if (lenh < lens) return -1; 
        if (lenh == lens){
            int eql = 0;
            for (int j = 0; j < lens; j++){
                if (haystack[j] != needle[j]){
                    eql = -1;
                    break;
                }
            }
            return eql;
        }
        // Calculate the Partial-match table Ti
        vector<int> Ti(lens+1, 0);
        Ti[0] = -1;
        int i = 1;
        while (i < lens) {
            if (needle[i] == needle[0]){
                int j = 0;
                int count = 1;
                if (Ti[i+1] < 1) Ti[i+1] = 1;  // Save the bigger one 
                while (i+count < lens - 1 && needle[j+count] == needle[i+count]) {
                    if ((count+1) > Ti[i+count+1]) Ti[i+count+1] = count+1;   // Save the bigger one 
                    count++;
                }
            }
            i++;
        }
        // Use match table to search
        int result = -1;
        i = 0;
        while (i < lenh){
            if (haystack[i] == needle[0]){
                if (lens == 1) return i;  // special case
                int count = 1;
                while (haystack[i+count] == needle[count]) {
                    count++;
                    if (count == lens) return i;  // Get the match pair
                    else if (i + count >= lenh) return -1;  // No match exist
                }
                i = i + count - Ti[count];  // Use match table to step forward
            }
            else i++;
        }
        return result;    
    }
};
