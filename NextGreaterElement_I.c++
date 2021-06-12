class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> m;
		for(int i = 0; i < nums2.size(); i++){
			int nextGreater;
			int flag = 0;
			for(int j = i + 1; j < nums2.size(); j++){
				if(nums2[j] > nums2[i]){
					nextGreater = nums2[j];
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				m[nums2[i]] = nextGreater;
			}
			else{
				m[nums2[i]] = -1;
			}
		}
		vector<int> res;
		for(int i = 0; i < nums1.size(); i++){
			res.push_back(m[nums1[i]]);
		}
		return res;
	}
};