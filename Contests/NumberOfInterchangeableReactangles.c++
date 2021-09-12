#define ll long long int
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        double arr[100000];
        int n = rectangles.size();
        long long int count = 0;
        for(int i=0;i<n;i++) {
            arr[i]=double(rectangles[i][0])/double(rectangles[i][1]);
        }
        map<double, ll> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        for(auto i=mp.begin();i!=mp.end();i++)
            count += ((i->second-1)*i->second)/2;
        
        return count;
    }
};