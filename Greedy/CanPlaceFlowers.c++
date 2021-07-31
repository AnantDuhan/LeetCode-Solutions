// 605
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        int count=0;
        if(size==1){
            if(flowerbed[0]+n<=1){
                return true;
            } else{
                return false;
            }
        }
        for(int i=0;i<size;i++){
            if(flowerbed[i])continue;
            if(i==0  && flowerbed[i+1]==0){
                flowerbed[i]=1;
                count++;
            } else if(i==size-1 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                count++;
            } else {
                if(i==0 || i==size-1)
                    continue;
                    if(flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                        count++;
                        flowerbed[i]=1;
                    }
            }
        }
        if(count >=n)return true;
        return false;       
    }
};