class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        set<int> row;
        set<int> col;
        set<int> block;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                int c=board[i][j]-'1';
                if(c!='.'-'1')
                {
                    if(col.find(c)!=col.end())
                    {
                        return false;
                    }
                        col.insert(c);
                }
               int r=board[j][i]-'1';
                if(r!='.'-'1')
                {
                    if(row.find(r)!=row.end())
                    {
                        return false;
                    }
                        row.insert(r);
                }
                int a=(i%3)*3+j/3;
                int b=(i/3)*3+j%3;
                int br=board[a][b]-'1';
                if(br!='.'-'1')
                {
                    if(block.find(br)!=block.end())
                    {
                        return false;
                    }
                        block.insert(br);
                }
                if(j==8)
                {
                    row.clear();
                    col.clear();
                    block.clear();
                }


            }
        return true;
    }
};
