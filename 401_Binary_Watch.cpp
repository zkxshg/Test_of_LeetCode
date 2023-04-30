// https://leetcode.com/problems/binary-watch/
// brute-force
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        string proto = "00:00";
        vector<string> result;
        if (num == 0) {
            result.push_back(proto.substr(1,4));
            return result;
        }

        vector<string> topR;
        vector<string> bottR;
        
        for (int i = 0; i <= num; i++){
            topR = calTop(i);
            if (topR.size() == 0) break;
            bottR = calBott(num-i);
            if (bottR.size() == 0) continue;
            for (int j = 0; j < topR.size(); j++){
                for (int k = 0; k < bottR.size(); k++)
                    result.push_back(topR[j] + bottR[k]);
            }
        }
        
        return result;
    }
    
    vector<string> calTop(int num){
        vector<string> result;
        if (num == 0) result.push_back("0:");
        else if (num == 1){
            result.push_back("1:");
            result.push_back("2:");
            result.push_back("4:");
            result.push_back("8:");
        }
        else if (num == 2){
            result.push_back("3:");
            result.push_back("5:");
            result.push_back("9:");
            result.push_back("6:");
            result.push_back("10:");
        }
        else if (num == 3){
            result.push_back("7:");
            result.push_back("11:");
        }
        
        return result;
}
    
    vector<string> calBott(int num){
        vector<string> result;
        if (num == 0) result.push_back("00");
        else if (num == 1){
            result.push_back("01");result.push_back("02");result.push_back("04");
            result.push_back("08");result.push_back("16");result.push_back("32");
        }
        else if (num == 2){
            result.push_back("03");result.push_back("05");result.push_back("06");
            result.push_back("09");result.push_back("10");result.push_back("12");
            result.push_back("17");result.push_back("18");result.push_back("20");
            result.push_back("24");result.push_back("33");result.push_back("34");
            result.push_back("36");result.push_back("40");result.push_back("48");
        }
        else if (num == 3){
            result.push_back("07");result.push_back("11");result.push_back("13");
            result.push_back("14");result.push_back("19");result.push_back("21");
            result.push_back("22");result.push_back("25");result.push_back("26");
            result.push_back("28");result.push_back("35");result.push_back("37");
            result.push_back("38");result.push_back("41");result.push_back("42");
            result.push_back("44");result.push_back("49");result.push_back("50");
            result.push_back("52");result.push_back("56");
        }
        else if (num == 4){
            result.push_back("15");result.push_back("23");result.push_back("27");
            result.push_back("29");result.push_back("30");result.push_back("39");
            result.push_back("43");result.push_back("45");result.push_back("46");
            result.push_back("51");result.push_back("53");result.push_back("54");
            result.push_back("57");result.push_back("58");
        }
        else if (num == 5){
            result.push_back("31");result.push_back("47");result.push_back("55");
            result.push_back("59");
        }
        return result;
}
    
};
