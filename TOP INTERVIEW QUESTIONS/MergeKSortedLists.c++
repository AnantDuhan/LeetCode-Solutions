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
        vector<int> a;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            while(temp!=NULL)
            {
                a.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(a.begin(),a.end());
        ListNode* head=NULL;
        ListNode* temp=NULL;
        for(int i=0;i<a.size();i++)
        {
            if(head==NULL)
            {
                head=new ListNode(a[i]);
                temp=head;
            }
            else
            {
                temp->next=new ListNode(a[i]);
                temp=temp->next;                
            }
        }
        return head;
    }
};