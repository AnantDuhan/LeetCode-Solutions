#define pb push_back
typedef long long ll;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> vec;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    int maxi = -1;
                    for (int k = j; k < n; k++)
                    {
                        if (nums2[k] > nums2[j])
                        {
                            maxi = nums2[k];
                            break;
                        }
                    }
                    vec.pb(maxi);
                }
            }
        }
        return vec;
    }
};