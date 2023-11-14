// doubly Linked list + hashmap
class FirstUnique {
public:
    struct ListNode {
        int val;
        ListNode *pre;
        ListNode *next;
        ListNode(int x) : val(x), pre(NULL), next(NULL) {}
    };
    
    unordered_map<int, int> valDict;
    unordered_map<int, ListNode *> posDict;
    ListNode * prehead = new ListNode(-1), * tail;
    
    FirstUnique(vector<int>& nums) {
        ListNode * temp = new ListNode(nums[0]);
        prehead->next = temp;
        temp->pre = prehead;
        valDict[nums[0]] = 1;
        posDict[nums[0]] = temp;
        tail = temp;
        
        for (int i = 1; i < nums.size(); i++) {
            if (valDict[nums[i]]) {
                if (posDict[nums[i]]) {
                    ListNode * delL = posDict[nums[i]];
                    
                    delL->pre->next = delL->next;
                    if (delL->next) delL->next->pre = delL->pre;
                    else tail = delL->pre;
                    
                    posDict.erase(nums[i]);
                }
            }
            else {
                ListNode * nex = new ListNode(nums[i]);
                valDict[nums[i]] = 1;
                posDict[nums[i]] = nex;
                temp->next = nex;
                nex->pre = temp;
                temp = nex;
                tail = nex;
            }
        }
    }
    
    int showFirstUnique() {
        if (!prehead->next) return -1;
        return  prehead->next->val;
    }
    
    void add(int value) {
        if (valDict[value]) {
            if (posDict[value]) {
                ListNode * delL = posDict[value];
                
                delL->pre->next = delL->next;
                if (delL->next) delL->next->pre = delL->pre;
                else tail = delL->pre;
                
                posDict.erase(value);
            }
        }
        else {
            ListNode * nex = new ListNode(value);
            valDict[value] = 1;
            posDict[value] = nex;
            tail->next = nex;
            nex->pre = tail;
            tail = nex;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
