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
    ListNode* SplitAtMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast !=NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL){
            prev->next =NULL;
        }
        return slow;

    }
    ListNode* reverse( ListNode* head){
        ListNode* prev =NULL;
        ListNode* curr = head;
        ListNode* next = head ->next;

        while(curr != NULL){
            next = curr->next;
            curr ->next = prev;

            prev = curr;
            curr =next;

        }

        return prev;
    }

    void AlternateMerging(ListNode* left , ListNode* right){
        

        while(left != NULL && right != NULL) {
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;


            left->next = right ;
            right->next = nextLeft;

            if(nextLeft ==NULL && nextRight !=NULL){
                right->next = nextRight;
                break;
            }

            left = nextLeft;
            right = nextRight;
        }
        
    }
    
    void reorderList(ListNode* head) {
        
        ListNode* rightHead = SplitAtMid(head);
        ListNode* right = reverse(rightHead);
        AlternateMerging(head ,right);
        
    }
};