//COMPLETE C++ SOLUTION
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            temp = temp -> next;
            n++;
        }
        if(n==1)
            return NULL;

        int size = 0;
        if(n%2==0)
            size = (n/2)-1;
        else
            size = n/2-1;
        ListNode* temp1 = head;
        for(int i = 1;i<=size;i++){
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        return head;

    }
};

// Python Solution
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n = 0
        temp = head
        while temp != None:
            temp = temp.next
            n+=1
        if n == 1:
            return None
        size = int(n/2)-1
        temp1 = head
        for i in range(size):
            temp1 = temp1.next
        temp1.next = temp1.next.next
        return head
