//CODE C++
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head;
        if(head==NULL || head->next== NULL)
            return head;
        int listSize = 1;
        
        while(tail->next != NULL){
            listSize++;
            tail = tail->next;
        }
        k = k%listSize;
        ListNode* newTail = head;
        tail->next = head;
        for(int i = 0;i<listSize-k-1;i++)
            newTail = newTail->next;
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};


