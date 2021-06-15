class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans{1};
        
        for (int row=1;row<=rowIndex;row++) {
            int pre = ans[0];
            for(int col=0;col<row;col++) {
                int tmp=(col==0)?1:ans[col] + pre;
                pre=ans[col];
                ans[col]=tmp;
            }
            ans.push_back(1);
        }
        return ans;
    }
};