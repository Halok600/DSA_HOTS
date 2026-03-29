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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        int prefix = 0;
        ListNode* dummy = new ListNode(0);
        mp[0] = dummy;
        dummy->next = head;
        while(head!=NULL){
            prefix += head->val;
            if(mp.find(prefix)!=mp.end()){
                int cur = prefix;
                ListNode* start = mp[prefix];
                ListNode* temp = start;
                while(temp!=head){
                    temp = temp->next;
                    cur+=temp->val;
                    if(head!=temp)
                        mp.erase(cur);
                }
                start->next = head->next;
            }
            else
                mp[prefix] = head;
            head = head->next;
        }
        return dummy->next;
    }
};
