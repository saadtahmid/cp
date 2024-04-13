#include <bits/stdc++.h>
using namespace std;
void pawn(int r,int c,vector<vector<int>>&boardans){
      if(r+1<8&&c+1<8&&boardans[r+1][c+1]!=1)boardans[r+1][c+1]=2;
      if(r+1<8&&c-1>=0&&boardans[r+1][c-1]!=1)boardans[r+1][c-1]=2;
}
void Pawn(int r,int c,vector<vector<int>>&boardans){
      if(r-1>=0&&c+1<8&&boardans[r-1][c+1]!=1)boardans[r-1][c+1]=2;
      if(r-1>=0&&c-1>=0&&boardans[r-1][c-1]!=1)boardans[r-1][c-1]=2;
}
void rook(int r,int c,vector<vector<int>>&boardans){
   for(int i=1;c+i<8;i++){
    if(boardans[r][c+i]==1)break;
    boardans[r][c+i]=2;
   }
   for(int i=1;c-i>=0;i++){
    if(boardans[r][c-i]==1)break;
    boardans[r][c-i]=2;
   }
   for(int i=1;r-i>=0;i++){
    if(boardans[r-i][c]==1)break;
    boardans[r-i][c]=2;
   }
   for(int i=1;r+i<8;i++){
    if(boardans[r+i][c]==1)break;
    boardans[r+i][c]=2;
   }
}
void knight(int r,int c,vector<vector<int>>&boardans){
      int rdown=r+2;
      int rup=r-2;
      int cright=c+2;
      int cleft=c-2;
      if(rdown<8 &&c+1<8 &&boardans[rdown][c+1]!=1)boardans[rdown][c+1]=2;
      if(rdown<8 &&c-1>=0 &&boardans[rdown][c-1]!=1)boardans[rdown][c-1]=2;
      if(rup>=0 &&c+1<8 &&boardans[rup][c+1]!=1)boardans[rup][c+1]=2;
      if(rup>=0 &&c-1>=0 &&boardans[rup][c-1]!=1)boardans[rup][c-1]=2;
      if(cleft>=0 &&r-1>=0 &&boardans[r-1][cleft]!=1)boardans[r-1][cleft]=2;
      if(cleft>=0 &&r+1<8 &&boardans[r+1][cleft]!=1)boardans[r+1][cleft]=2;
      if(cright<8 &&r+1<8 &&boardans[r+1][cright]!=1)boardans[r+1][cright]=2;
      if(cright<8 &&r-1>=0 &&boardans[r-1][cright]!=1)boardans[r-1][cright]=2;
}
void bishop(int r,int c,vector<vector<int>>&boardans){
    for(int i=1;r+i<8&&c+i<8;i++){
        if(boardans[r+i][c+i]==1)break;
        boardans[r+i][c+i]=2;
      }
      for(int i=1;r-i>=0&&c+i<8;i++){
        if(boardans[r-i][c+i]==1)break;
        boardans[r-i][c+i]=2;
      }
      for(int i=1;r+i<8&&c-i>=0;i++){
        if(boardans[r+i][c-i]==1)break;
        boardans[r+i][c-i]=2;
      }
      for(int i=1;r-i>=0&&c-i>=0;i++){
        if(boardans[r-i][c-i]==1)break;
        boardans[r-i][c-i]=2;
      }
}
void queen(int r,int c,vector<vector<int>>&boardans){
      bishop(r,c,boardans);
      rook(r,c,boardans);
}
void king(int r,int c,vector<vector<int>>&boardans){
       int up=r-1;
       int down=r+1;
       if(up>=0 &&boardans[up][c]!=1)boardans[up][c]=2;
       if(up>=0 &&c+1<8&&boardans[up][c+1]!=1)boardans[up][c+1]=2;
       if(up>=0 &&c-1>=0&&boardans[up][c-1]!=1)boardans[up][c-1]=2;
       if(down<8 &&boardans[down][c]!=1)boardans[down][c]=2;
       if(down<8 &&c+1<8&&boardans[down][c+1]!=1)boardans[down][c+1]=2;
       if(down<8 &&c-1>=0&&boardans[down][c-1]!=1)boardans[down][c-1]=2;
       if(c+1<8&&boardans[r][c+1]!=1)boardans[r][c+1]=2;
       if(c-1>=0&&boardans[r][c-1]!=1)boardans[r][c-1]=2;
}
int main(){
    
    string input;
    while(cin>>ws>>input){
    vector<vector<char>>board(8,vector<char>(8,0));
    vector<vector<int>>boardans(8,vector<int>(8,0));
    int r=0;int col=0;
    for(auto c:input){
        if (c=='/'){r++;col=0;}
        else if(c>='1'&&c<='8')col+=(c-'0');
        else {
            board[r][col]=c;
            boardans[r][col]=1;
            col++;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='p'){
                pawn(i,j,boardans);
            }
            if(board[i][j]=='P'){
                Pawn(i,j,boardans);
            }
            if(board[i][j]=='n'||board[i][j]=='N'){
                knight(i,j,boardans);
            }
            if(board[i][j]=='r'||board[i][j]=='R'){
                rook(i,j,boardans);
            }
            if(board[i][j]=='b'||board[i][j]=='B'){
                bishop(i,j,boardans);
            }
            if(board[i][j]=='q'||board[i][j]=='Q'){
                queen(i,j,boardans);
            }
            if(board[i][j]=='k'||board[i][j]=='K'){
                king(i,j,boardans);
            }
            
        }
    }int ans=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
         if(boardans[i][j]==0)ans++;
        }
    }cout<<ans<<'\n';}
    return 0;
}