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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* beforegroup = &dummy;

        while(true){
            ListNode* groupEnd = beforegroup;
            for(int i=0 ; i<k && groupEnd ; i++){
                groupEnd = groupEnd->next; 
            }
            if(!groupEnd)break;

            ListNode* nextGroupStart = groupEnd->next;

            ListNode* previous = nextGroupStart;
            ListNode* current = beforegroup->next;  

            while(current!=nextGroupStart){
                ListNode* nextNode = current->next;
                current->next= previous;
                previous = current ;
                current = nextNode; 
            }

            ListNode* groupStart=beforegroup->next;
            beforegroup->next = groupEnd;
            beforegroup = groupStart;
        }
        return dummy.next;
    }
};
