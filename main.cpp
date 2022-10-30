//
//  main.cpp
//  AoPS
//
//  Created by chl178 on 2022/10/27.
//

#include <iostream>
using namespace std;
#include <limits>
#include <string>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<algorithm>
#include <fstream>
#include <sstream>

// recursive method
void helper(vector<vector<int>>& a, int i, int j, int remain,int n, vector<string>& res, string& path){
    
    // If the remainder is not divisible by a[i][j]
    if(remain % a[i][j])
        return;
    
    //Because it is just on the last line and the remainder is equal to this number,
    //so this path is valid, we push it back to the res.
    if(i==n && remain==a[i][j]){
        res.push_back(path);
        return;
    }
    
    //Go left
    if(i+1<=n){
        path.push_back('L');
        helper(a, i+1, j,remain/a[i][j],n,res,path);
        path.pop_back();
    }
    
    //Go right
    if(i+1<=n&&j+1<=n){
        path.push_back('R');
        helper(a, i+1, j+1,remain/a[i][j],n,res,path);
        path.pop_back();
    }
        
    
}

int main()
{
    int n; //the heigth of the pyramid
    cin>>n;
    
    vector<vector<int>> a(n+1,vector<int>(n+1));
    // Initialize the pyramid
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    
    int target;
    cout<<"target:";
    cin>>target;
    
    //res is used to store all the possible path
    vector<string> res;
    string path;
    
    helper(a,1,1,target,n,res,path);
    
    // if none of the path is valid
    if(res.empty()){
        cout<<"-1"<<'\n';
        return 0;
    }
    
    //the output
    for(auto t:res){
        cout<<t<<'\n';
    }
}





