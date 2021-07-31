class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        int j = s.size() - 1;
        int i = g.size() - 1;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while(i>=0 && j>=0) {
            if(s[j]>=g[i]) {
                i--;
                j--;
                count++;
            } else {
                i--;
            }
        }
        return count;
    }
};