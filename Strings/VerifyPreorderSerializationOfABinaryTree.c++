class Solution {
public:
    bool isValidSerialization(string preorder) {
        int emptySpaces = 1;
        
        preorder += ',';
        
        for(int i=0;i<preorder.size(); i++) {
            if(preorder[i] != ',') 
                continue;
            
            emptySpaces -= 1;
            if(emptySpaces < 0) {
                return false;
            }
            if(preorder[i-1] != '#') {
                emptySpaces += 2;
            }
        }
        return  emptySpaces == 0;
    }
};