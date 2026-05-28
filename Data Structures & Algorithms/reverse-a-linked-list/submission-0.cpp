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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            next= curr->next; //next mai current k next ki value
            curr->next=prev;  //current next mai previous ki value
            prev=curr;          //prev ek step aage badke ho jaega curr
            curr=next;          // or current ek step aage badh k next ho jaega
        }
        return prev;
    }
};
