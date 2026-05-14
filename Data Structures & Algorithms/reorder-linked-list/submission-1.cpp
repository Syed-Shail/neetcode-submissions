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
    void reorderList(ListNode* head) {
        ListNode* head2 = head;
        vector<ListNode*> v;
        while(head2->next){
            v.push_back(head2);
            head2=head2->next;
        }
        v.push_back(head2);
        int n = v.size();
        int l =1;
        int r = n-1;
        head2=head;
        while(l<r){
            head2->next=v[r];
            r--;
            head2=head2->next;
            head2->next=v[l];
            l++;
            head2=head2->next;
        }
        if(l==r){head2->next = v[l];
        head2=head2->next;}
        head2->next=nullptr;
        
    }
};
