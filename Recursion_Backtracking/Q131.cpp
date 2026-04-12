#include <bits/stdc++.h>
using namespace std;

bool palin(vector<string>& a){
    int n=a.size();
    for(int i=0;i<n;i++){
        int l=a[i].length();
        for(int j=0;j<l/2;j++){
                if(a[i][j]!=a[i][l-j-1]){
                    return false;
                }
            }
        }
    
    return true;
}

void perm(vector<string> a,set<vector<string>>& ans){
    if(palin(a)){
        ans.insert(a);
    }
    for(int i=0;i<a.size();i++){
        
        string x=a[i];
        for(int j=0;j<x.length()-1;j++){
            vector<string> str;
            for(int j=0;j<i;j++) str.push_back(a[j]);
            str.push_back(x.substr(0,j+1));
            str.push_back(x.substr(j+1));
        
            for(int j=i+1;j<a.size();j++) str.push_back(a[j]);
        
        perm(str,ans);
    }
    }
    return;
}

vector<vector<string>> partition(string s) {
    vector<string> a={s};
    set<vector<string>> ans;
    perm(a,ans);
    vector<vector<string>> answer;
    for(auto x:ans) answer.push_back(x);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s="aabb";
    vector<vector<string>> ans=partition(s);
    for(auto x:ans){
        for(auto y:x){
            for(auto z:y){
                cout<<z;
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}