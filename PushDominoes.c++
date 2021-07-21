class Solution {
public:
    string pushDominoes(string dominoes) {
        int lastR = -1;
        int n = dominoes.size();
        
        for(int i=0; i<dominoes.size(); i++)
        {
            if(dominoes[i] == 'L')
            {
                if(lastR == -1)
                {
                    int j=i-1;
                    while(j>=0 && dominoes[j] == '.') 
                    {
                        dominoes[j] = 'L';
                        j--;
                    }
                }
                else
                {
                    int diff = i - lastR - 1;
                    if(diff == 0)
                    {
                        lastR = -1;
                        continue;
                    }
                    int j;
                    for(j=1; j<=diff/2; j++)
                        dominoes[i-j] = 'L';
                    if(diff%2 == 1)
                        dominoes[(i+lastR)/2] = '.';
                    for(j=(lastR+diff/2);j>lastR;j--)
                        dominoes[j]='R';
                    lastR = -1;
                }
            }
            else if(dominoes[i] == 'R'){
                if(lastR!=-1){
                    while(lastR<i){
                        dominoes[lastR]='R';
                        lastR+=1;
                    }   
                }else{
                    lastR = i;
                }
            }
        }
        if(lastR!=-1){
            while(lastR<n){dominoes[lastR]='R';lastR+=1;}
        }
        
        return dominoes;
    }
};