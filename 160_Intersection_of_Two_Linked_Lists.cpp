// rec the list* -> backtracing
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || ! headB) return NULL;
        if (headA == headB) return headA;
        
        vector<ListNode *> valA; 
        vector<ListNode *> valB;
        ListNode *nex;
        
        nex = headA;
        while(nex){
            valA.push_back(nex);
            nex = nex->next;
        }
        
        nex = headB;
        while(nex){
            valB.push_back(nex);
            nex = nex->next;
        }
        
        int lenA = valA.size();
        int lenB = valB.size();
        
        if (valA[lenA-1] != valB[lenB-1]) return NULL;
        
        int pos = 1;
        bool findInter = false;
        
        while((lenA - pos >= 0) && (lenB - pos >= 0)){
            if (valA[lenA - pos] == valB[lenB - pos]){
                if (lenA - pos == 0) return headA;
                else if (lenB - pos == 0) return headB;   
            }
            else {
                findInter= true;
                break;
            }
            pos++;
        }
        
        if (findInter){
            int cou = 0;
            nex = headA;
            while(nex){
                if(cou == lenA - pos + 1) return nex;
                else{
                    nex = nex->next;
                    cou++;
                }
            }
        }
        
        return NULL;
    }
};
