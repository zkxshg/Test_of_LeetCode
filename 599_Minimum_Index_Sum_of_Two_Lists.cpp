class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() <= 1) return list1;
        if (list2.size() <= 1) return list2;
        
        vector<string> listsum = list1;
        listsum.insert(listsum.end(), list2.begin(), list2.end());
        sort(listsum.begin(), listsum.end());
        
        vector<string> cominter;
        for (int i = 0; i < listsum.size() - 1; i++) {
            if (listsum[i] == listsum[i+1]) {
                cominter.push_back(listsum[i]);
                i += 1;
            }
        }
        
        if (cominter.size() == 1) return cominter;
        
        vector<int> comindex(cominter.size(), 2001);
        for (int i = 0; i < cominter.size(); i++){
            for (int j = 0; j < list1.size(); j++){
                if (cominter[i] == list1[j]) comindex[i] = j;
            }
            for (int j = 0; j < list2.size(); j++){
                if (cominter[i] == list2[j]) comindex[i] += j;
            }
        }
        
        int min = 2001;
        for (int i = 0; i < comindex.size(); i++){
            if (comindex[i] < min) min = comindex[i];
        }
        vector<string> result;
        for (int i = 0; i < comindex.size(); i++){
            if (comindex[i] == min) result.push_back(cominter[i]);
        }
        return result;
    }
};
