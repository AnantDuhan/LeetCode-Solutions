class Solution {
public:
    
    vector<vector<int>> d;
    int rows;
    int cols;
    int pivot = 1;
    
	// Key function
	//
    int getCur(int cur, int next) {
        return min(cur, min(0, cur + next));
    }
    
    void init(vector<vector<int>>& dungeon) {
        d = dungeon;
        rows = d.size();
        cols = d[0].size();
    }
    
    void sol() {
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                int tmp = d[i][j];
                int r = pivot;
                int r2 = pivot;
                
                // has down side
                if (i < rows - 1)
                    r = getCur(tmp, d[i + 1][j]);
                
                // has right side
                if (j < cols - 1)
                    r2 = getCur(tmp, d[i][j + 1]);
                
				// key step
				//
                if (r == pivot and r2 == pivot)
                    continue;
                else if (r == pivot)
                    d[i][j] = r2;
                else if (r2 == pivot)
                    d[i][j] = r;
                else 
                    d[i][j] = max(r, r2);

            }
        }
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        init(dungeon);
        sol();
        
        if (d[0][0] > 0)
            return 1;
        else
            return 1 - d[0][0];

    }
};