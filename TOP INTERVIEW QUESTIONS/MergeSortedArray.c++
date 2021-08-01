class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        for (auto it=nums1.begin(); it != nums1.end();) {
            if (*it == 0)
                nums1.erase(it);
            else
                it++;
            
            if(nums1.size() == m+n)
                break;
        }
    }
};