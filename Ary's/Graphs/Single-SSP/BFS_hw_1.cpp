// https://cses.fi/problemset/task/1667
/*
Syrjälä's network has n computers and m connections. 
Your task is to find out if Uolevi can send a message to Maija, and if it is possible, 
what is the minimum number of computers on such a route.

Input

The first input line has two integers n and m: the number of computers and connections.
The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.

Output

If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".

*/

#include<bits/stdc++.h>
using namespace std;

void printer(){
    
}

int n,m,comp;
vector<int> visited, comp_no;
vector<vector<int>> nbors;

void dfs(int node, int cc){
    visited[node]=1;
    comp_no[node]=cc;
    for(auto v:nbors[node]){
        if(!visited[v]){
            dfs(v,cc);
        }
    }
}

void solve(){
    cin >> n >> m;
    nbors.resize(n+1); visited.resize(n+1); comp_no.resize(n+1);
    while(m--){
        int x,y;
        cin >> x >> y;
        nbors[x].push_back(y);
        nbors[y].push_back(x);
    }
    comp=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            comp++;
            dfs(i,comp);
        }
    }
    if(comp_no[1]==comp_no[n]){
        printer();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}