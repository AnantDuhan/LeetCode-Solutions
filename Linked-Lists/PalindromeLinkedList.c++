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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
          ListNode *help=head;
          while(help!=nullptr){
              v.push_back(help->val);
              help=help->next;
          }
          reverse(v.begin(),v.end());
          help=head;
          for(auto a:v){
            if(help->val==a)
            {
                help=help->next;
            }
            else
            {
                return false;
            }
          }
         
          return true;
    }
};