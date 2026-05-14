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
        int size =1;

        ListNode* tail = head;
         while(tail->next){
            tail = tail->next;
            size++;
        }
        if(size==1)return nullptr;
        tail = head;
        size = size-n;
        if(size==0)return head->next;
        while(tail->next){
            size--;
            if(size<=0){
                if(tail->next->next)tail->next = tail->next->next;
                else{
                    tail->next=nullptr;
                }
                return head;
            }
            else{
                tail=tail->next;
            }
        }
        return head;
    }
};
