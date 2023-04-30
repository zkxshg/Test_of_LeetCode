// https://leetcode.com/problems/single-threaded-cpu/
// heap
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1] ;
    }
    
    static bool cmp2(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0] ;
    }
    
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int len = tasks.size();
        
        vector<int> res;
        
        // rec the index of tasks
        for (int i = 0; i < len; i++)  tasks[i].push_back(i);
        
        // Heap tp save the left tasks
        make_heap(tasks.begin(), tasks.end(), cmp2);
        
        // Heap to save the available tasks
        vector<vector<int> > meet;
        make_heap(meet.begin(), meet.end(), cmp);
        
        long long st = tasks.front()[0];
        int num = 0;
        
        while (num < len) {
            
            // Check the enqueTime
            while (!tasks.empty() && tasks.front()[0] <= st) {
                tasks.front()[0] = tasks.front()[2]; 
                meet.push_back(tasks.front()); 
                push_heap(meet.begin(), meet.end(), cmp);
                
                pop_heap(tasks.begin(), tasks.end(), cmp2); tasks.pop_back();
            }
            
            // empty
            if (meet.empty()) {
                st = tasks.front()[0];
                continue;
            }
            
            // selection
            res.push_back(meet.front()[0]);
            st += meet.front()[1];
            
            pop_heap(meet.begin(), meet.end(), cmp); 
            meet.pop_back(); 
            
            // process
            num++;
        }
        
        return res;
    }
};

// sort
class Solution {
public:
    
    void QuickSortWithIndex(vector<vector<int> >& B, vector<int>& BI, int f, int l) {
        int x = B[f][0];
        int i = f + 1;
        int j = l;
        while (i < j) {
            while (j >= f + 1 && B[j][0] >= x) j--;
            while (i <= l && B[i][0] <= x) i++;
            if (i < j) {
                vector<int> temp = B[i];
                B[i] = B[j];
                B[j] = temp;

                int tempI = BI[i];
                BI[i] = BI[j];
                BI[j] = tempI;
            }
        } 
        if (B[f][1] > B[j][0]) {
            vector<int> temp = B[f];
            B[f] = B[j];
            B[j] = temp;

            int tempI = BI[f];
            BI[f] = BI[j];
            BI[j] = tempI;
        }
        if (f < j - 1) QuickSortWithIndex(B, BI, f, j - 1);
        if (j + 1 < l) QuickSortWithIndex(B, BI, j + 1, l);
    }
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int len = tasks.size();
        
        vector<int> res;
        long long st = tasks[0][0]; 
        int num = 0;
        
        // set the min start time
        for (vector<int>& v : tasks) 
            if (st > v[0]) st = v[0];
        
        vector<vector<int> > avS; vector<int> avI;
        
        vector<int> leftI(len); for (int i = 0; i < len; i++) leftI[i] = i;

        while (num < len) {
            // Find available
            vector<vector<int> > tem; vector<int> temI;
            
            for (int i = 0; i < tasks.size(); i++) {
                if (tasks[i][0] <= st) { // available set
                    for (int j = 0; j < avS.size(); j++) {
                        if (avS[j][1] < tasks[i][1]) {
                            avS.insert(avS.begin() + j, tasks[i]); 
                            avI.insert(avI.begin() + j, leftI[i]);
                            break;
                        }
                        if (j == avS.size()) {
                            avS.push_back(tasks[i]); avI.push_back(leftI[i]); break;
                        }
                    }
                }
                else {
                   tem.push_back(tasks[i]);  temI.push_back(leftI[i]); // left set
                }
            }
            
            tasks = tem; leftI = temI;
            
            // no available
             if (avS.empty()) {
                int nt = 1e9 + 1;
                for (int i = 0; i < tasks.size(); i++) 
                    nt = min(nt, tasks[i][0]);
                st = nt; 
                continue;
            }

            // process
            st += avS.back()[1]; res.push_back(avI.back());
            
            // remove
            avS.pop_back(); avI.pop_back();
            
            num++;
        }
        return res;
    }
};
