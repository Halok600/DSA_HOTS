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
    ListNode* recur(ListNode* list1, ListNode* list2){
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        if(list1->val<=list2->val){
            list1->next = recur(list1->next,list2);
            return list1;
        }
        else{
            list2->next = recur(list1,list2->next);
            return list2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = recur(list1,list2);
        return ans;
    }
};
