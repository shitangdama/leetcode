class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen = 0, blen = 0;
        ListNode *tmpA = headA, *tmpB = headB;

        // get the length of A, B
        while (tmpA != NULL) {
            alen++;
            tmpA = tmpA->next;
        }
        while (tmpB != NULL) {
            blen++;
            tmpB = tmpB->next;
        }
        if (tmpA || tmpB)
            return NULL;

        // set A be the longer one
        if (alen < blen) {
            swap(headA, headB);
            swap(alen, blen);
        }

        tmpA = headA;
        tmpB = headB;
        // cut A
        while (alen > blen) {
            alen--;
            tmpA = tmpA->next;
        }
        while (blen--) {
            if (tmpA == tmpB)
                return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return NULL;
    }
};
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            //caculate the length of each List
            int lenA = getListLength(headA);
            int lenB = getListLength(headB);

            if (lenA<=0 || lenB<=0 ) return NULL;

            //let List A is the longest List;
            if (lenA < lenB){
                swap(headA, headB);
            }

            //move head of List A, make both of Lists are same length 
            for (int i=0; i<abs(lenA-lenB); i++){
                headA = headA->next;
            }

            //synced travel both of Lists and check their nodes are same or not 
            while (headA != headB){
                headA = headA->next;
                headB = headB->next;
            }

            return headA;
        }
    private:    
        inline int getListLength(ListNode *head){
            int len=0;
            while(head!=NULL){
                head = head->next;
                len++;
            }
            return len;
        }
};