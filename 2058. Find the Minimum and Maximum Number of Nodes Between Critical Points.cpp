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
        vector<int>index;
        ListNode* prevNode=head;
        ListNode* curr=head->next;
        ListNode* nextNode=curr->next;
        int cnt=1;

        while(nextNode!=NULL){
            if((prevNode->val < curr->val && curr->val > nextNode->val) || (prevNode->val > curr->val && curr->val < nextNode->val)){
              //  cout<<cnt<<endl;
                index.push_back(cnt);
            }
            
            cnt++;
            prevNode=prevNode->next;
            curr=prevNode->next;
            nextNode=curr->next;

        }

        if(index.size()<2){
            return {-1,-1};
        }

        int miniDist=INT_MAX;
        for(int i=0;i<index.size()-1;i++){
            if(index[i+1]-index[i] < miniDist){
                miniDist=index[i+1]-index[i];
            }
        }

        int maxiDist=index[index.size()-1]-index[0];

        return {miniDist,maxiDist};
    }
};