class Solution {
    int ret_pos;
public:
    int calculate(string s,int i=0) {
        int first=0,sum=0;
        int sign=1 ;
        while(i<s.length() && s[i]!=')')
        {
            while(s[i]==' ')i++;
            if(s[i]=='-' ){sign = -1;i++;}
            if(s[i]=='+'){sign =1;i++;}
            while(s[i]==' ')i++;
            if(s[i]=='(')
            {
                first = calculate(s,i+1);
                i = ret_pos;
            }
            else if(isdigit(s[i]))
            {
                int j=i;
                first =0;
                while(isdigit(s[j]))
                {
                    first*=10;
                    first +=s[j]-'0';
                    j++;
                }
                i=j;
            }
            sum+=sign*first;
            first = 0 ;
            sign=1;
            if(s[i] == ')')
            {
                ret_pos = i+1;
                return sum;
            }
        }
        return sum;
    }
};
