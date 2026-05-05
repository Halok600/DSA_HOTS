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
//PYTHON SOLUTION
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k==0:
            return head
        list_size = 1
        tail = head
        while tail.next:
            list_size+=1
            tail = tail.next
        k = k % list_size
        tail.next = head
        newTail = head
        for i in range(list_size-k-1):
            newTail = newTail.next
        newHead = newTail.next
        newTail.next = None
        return newHead

