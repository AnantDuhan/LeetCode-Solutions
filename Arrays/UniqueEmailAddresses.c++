class Solution {
public:
    int numUniqueEmails(vector<string>& arr) {
        set<string> st; 
        int n = arr.size();       
        for(int i=0;i<n;i++){
            string email = arr[i]; 
            int pos = email.find('@');
            string domain = email.substr(pos);
            string local = "";
            int j = 0;
            while(j < pos){
                if(email[j] == '.'){
                    j++;
                    continue;
                }else if(email[j] == '+')
                        break;
                    else
                        local += email[j];
                j++;
            }
            st.insert(local+domain);
        }
        return st.size();
    }
};