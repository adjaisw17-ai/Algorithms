#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char,vector<char>> nbors;
    map<char,int> visited,comp_no;

    void dfs(char node, int cc){
        visited[node]=1;
        comp_no[node]=cc;
        for(auto v : nbors[node]){
            if(!visited[v]){
                dfs(v,cc);
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {

        for(int i=0; i<equations.size(); i++){
            string cur = equations[i];
            visited[cur[0]]=0;
            visited[cur[3]]=0;
            if(cur[1]=='='){
                nbors[cur[0]].push_back(cur[3]);
                nbors[cur[3]].push_back(cur[0]);
            }
        }
        int cur_comp_no = 0;
        for(auto p: visited){
            if(!visited[p.first]){
                cur_comp_no++;
                dfs(p.first, cur_comp_no);
            }
        }
        for(int i=0; i<equations.size(); i++){
            string cur = equations[i];
            if(cur[1]=='!' && comp_no[cur[0]]==comp_no[cur[3]]){
                return false;
            }
        }
        return true;
    }
};