class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int r=land.size();
        int c=land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(land[i][j]==1){
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(true){
                        int size=q.size();
                        bool flag=true;
                        int a,b;
                        while(size--){
                        pair<int,int> temp=q.front();
                            a=temp.first;
                            b=temp.second;
                        q.pop();
                        flag=true;
                        if(temp.first+1<r && land[temp.first+1][temp.second]==1){
                            flag=false;
                             land[temp.first+1][temp.second]=0;
                            q.push({temp.first+1,temp.second});
                        }
                        if(temp.second+1<c && land[temp.first][temp.second+1]==1){
                              flag=false;
                              land[temp.first][temp.second+1]=0;
                            q.push({temp.first,temp.second+1});
                        }
                        }
                         if(q.size()==0){
                            v.push_back(a);
                            v.push_back(b);
                            break;
                        }
                    }
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};