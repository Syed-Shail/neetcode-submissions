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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>>,greater<>> pq;

        for(ListNode* head : lists){
            if(head){
                pq.push({head->val,head});
            }
        }
        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        while(!pq.empty()){
            auto n = pq.top();
            pq.pop();
            ListNode* no = n.second;
            tail->next = no;
            tail = tail->next;
            if(no->next){
                pq.push({no->next->val,no->next});
            }
        }
        return head->next;
    }
};
