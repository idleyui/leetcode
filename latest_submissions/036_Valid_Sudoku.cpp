class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(vector<char>& v: board){
            int check[10]{};
            for(char &c: v){
                if(c == '.')continue;
                if(check[c-'0'] > 0) return false;
                check[c-'0']++;
            }
        }
        
        for(int i = 0; i < 9; i++){
            int check[10]{};
            for(int j = 0; j < 9; j++){
                char c = board[j][i];
                if(c =='.')continue;
                if(check[c-'0'] > 0) return false;
                check[c-'0']++;
            }
        }
        
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                int check[10]{};
                for(int m = i; m < i+3; m++){
                    for(int n = j; n < j+3; n++){
                        char c = board[m][n];
                        if(c == '.')continue;
                        if(check[c-'0'] > 0) return false;
                        check[c-'0']++;
                    }
                }
            }
        }
        return true;
    }
};