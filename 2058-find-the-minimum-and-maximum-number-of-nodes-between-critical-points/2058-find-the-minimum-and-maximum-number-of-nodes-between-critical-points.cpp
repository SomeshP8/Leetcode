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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return {-1,-1};
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        int index=1;
        int first=-1,previndex=-1,mini=INT_MAX;
        while(curr->next!=nullptr){
            bool isMaxima = (curr->val > prev->val && curr->val > curr->next->val);
            bool isMinima = (curr->val < prev->val && curr->val < curr->next->val);
            if(isMaxima || isMinima){
                if(first==-1){
                    first=index;
                }
                else{
                    mini=min(mini,index-previndex);
                }
                previndex=index;
            }
            prev=curr;
            curr=curr->next;
            index++;
        }
        if(first==previndex){
            return {-1,-1};
        }
        int maxi=previndex-first;
        return {mini,maxi};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna