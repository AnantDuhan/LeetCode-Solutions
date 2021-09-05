class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());
        int ans=0, size=properties.size(), a = properties[size-1][0], b=properties[size-1][1], lmax=properties[size-1][1];
        for(int i=size-2;i>=0;i--) {
            if(properties[i][0]<properties[i+1][0]) {
                b=max(lmax,b);
                lmax = max(b,properties[i][1]);
            }
            if(properties[i][0]<a && properties[i][1]<b)
                ans++;
        }
        return ans;
    }
};