class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        for(int i=0;i<n;i++){
            unordered_set<int> s;
            for(int j=0;j<n;j++){
                if(board[i][j] == '.')
                    continue;
                if(board[i][j] > '9' || board[i][j] < '1')
                    return false;
                int val = board[i][j] - '0';
                if(s.contains(val))
                    return false;
                s.insert(val);
            }
            s.clear();
            for(int j=0;j<n;j++){
                if(board[j][i] == '.')
                    continue;
                if(board[j][i] > '9' || board[j][i] < '1')
                    return false;
                int val = board[j][i] - '0';
                if(s.contains(val))
                    return false;
                s.insert(val);
            }
        }
        for(int c1 = 1; c1 <8 ; c1+=3){
            for(int c2 = 1; c2 < 8; c2+=3){
            unordered_set<int> s;
                for(int i=-1; i<2; i++){
                    for(int j=-1; j<2; j++){
                        if(board[c1+i][c2+j] == '.')
                            continue;
                        if(board[c1+i][c2+j] > '9' || board[c1+i][c2+j] < '1')
                            return false;
                        int val = board[c1+i][c2+j] - '0';
                        if(s.contains(val))
                            return false;
                        s.insert(val);
                    }
                }
            }
        }
        return true;
    }
};
