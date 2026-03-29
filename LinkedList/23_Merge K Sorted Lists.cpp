/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recur(ListNode* L1,ListNode* L2){
        if(L1==NULL)
            return L2;
        if(L2==NULL)
            return L1;
        if(L1->val<=L2->val){
            L1->next = recur(L1->next,L2);
            return L1;
        }
        else{
            L2->next = recur(L1,L2->next);
            return L2;
        }
    }
    ListNode* part(int s,int e,vector<ListNode*>& lists){
        if(s==e)
            return lists[s];
        int mid = s + (e-s)/2;
        ListNode* L1 = part(s,mid,lists);
        ListNode* L2 = part(mid+1,e,lists);
        return recur(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        return part(0,n-1,lists);
    }
};
