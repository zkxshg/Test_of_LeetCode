// https://leetcode.com/problems/design-browser-history/
// linked list

class BrowserHistory {
public:
    struct ListNode {
        string url;
        ListNode *pre;
        ListNode *next;
        ListNode(string x) : url(x), pre(NULL), next(NULL) {}
    };
    
    ListNode* root;
    
    BrowserHistory(string homepage) {
        root = new ListNode(homepage);;
    }
    
    void visit(string url) {
        if (!root) root = new ListNode(url);
        else {
            ListNode* nex = new ListNode(url);
            nex->pre = root; root->next = nex;
            root = root->next;
        }
    }
    
    string back(int steps) {
        if (!root) return "";
        
        while (root->pre && steps) {
            root = root->pre; steps--;
        } 
        
        return root->url;
    }
    
    string forward(int steps) {
        if (!root) return "";
        
        while (root->next && steps) {
            root = root->next; steps--;
        } 
        
        return root->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
