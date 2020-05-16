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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        
        if(!evenHead)
            return head;
        
        bool oddList = true;
        while(head && head->next && head->next->next)
        {
            ListNode* nextNode = head->next;
            head->next = head->next->next;
            head = nextNode;
            oddList = (oddList!=true);
        }
        
        // ListNode* temp = evenHead;
        // while(temp)
        // {
        //     cout<<temp->val<<" ";
        //     temp = temp->next;
        // }
        
        if(!oddList)
        {
            head->next->next = evenHead;
            head->next = NULL;
        }
        else
        {
            head->next->next = NULL;
            head->next = evenHead;
        }
        
        return oddHead;
    }
};