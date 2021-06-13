class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        stack<int>stk;
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            stk.push(i);
            ans.push_back("Push");
            if(target[index] == stk.top())
            {
                index++;
            }
            else
            {
                stk.pop();
                ans.push_back("Pop");
            }
            if(index == target.size())
            {
                break;
            }
        }
        return ans;
    }
};