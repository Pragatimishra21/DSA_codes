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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int l = 0;
        ListNode* temp = head;
        ListNode* first = head;
        ListNode* sec = head;
        while(temp)
        {
            temp = temp->next;
            l++;
        }
        for(int i=1 ; i<k ; i++)
        {
          first = first->next;
        }
        for(int i=1 ; i<=l-k ; i++)
        {
            sec = sec->next;
        }
        swap(first->val , sec->val);
        return head;
    }
};