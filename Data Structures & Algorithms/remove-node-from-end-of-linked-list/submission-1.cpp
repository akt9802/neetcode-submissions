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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we can find the length first
        int len = 0;
        ListNode* mover = head;
        while(mover!=NULL){
            len++;
            mover = mover->next;
        }

        int startingPosition = len-n+1;
        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i=0;i<startingPosition-1;i++){
            prev = curr;
            curr = curr->next;
        }

        if(len == 1 && n==1){
            return NULL;
        }

        if(prev == NULL){
            return curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        return head;

    }
};
