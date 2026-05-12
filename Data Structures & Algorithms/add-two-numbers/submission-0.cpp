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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(0);
        ListNode* dum = curr;
        int carry =0;
        while(l1!=nullptr || l2!=nullptr ||carry!=0){
            int res= carry;
            if(l1!=nullptr){
                res+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                res+=l2->val;
                l2=l2->next;
            }
            carry = res/10;
            res=res%10;
            curr->next = new ListNode(res);
            curr = curr->next;
        }
        return dum->next;
    }
};
