class Solution {
public:
    int findLength(ListNode* &head){
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL){
            length++;
            temp = temp -> next;
        }
        return length;
    }

    
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int remLength = findLength(head) - 1;
        int ans = 0;
        while(temp != NULL){
            int val = pow( 2, remLength ) * temp -> val;
            ans += val;
            temp = temp -> next;
            remLength--;
        }
        return ans;
    }
};