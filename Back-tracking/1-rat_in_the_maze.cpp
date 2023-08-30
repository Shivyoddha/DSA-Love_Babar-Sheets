#include <bits/stdc++.h>
#define MAX 5
using namespace std;
void getallpath(int m[MAX][MAX], int n, int row, int col, vector<string> &ans,string cur){
    if(row>=n or col>=n or col<0 or m[row][col]==0)
    return;
    if(row==n-1 and col==n-1)
    {
    ans.push_back(cur);
    return;
    }
    m[row][col]=0;
    getallpath(m,n,row+1,col,ans,cur+'D');
    getallpath(m,n,row,col-1,ans,cur+'L');
    getallpath(m,n,row,col+1,ans,cur+'R');
    getallpath(m,n,row-1,col,ans,cur+'U');
    m[row][col]=1;
}
vector<string> findPath(int m[MAX][MAX],int n){
   vector<string> ans;
   getallpath(m,n,0,0,ans,"");
   return ans;
}
int main(){
    int m[MAX][MAX] = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 }};
    int n=sizeof(m)/sizeof(m[0]);
    vector<string> ans = findPath(m,n);
    for(auto i : ans)
    cout<<i<<' ';
    }