#include<bits/stdc++.h>
using namespace std;
int f(vector<char> paranthesis){
    stack<int> s;
    for(auto a:paranthesis){
        if(a=='(' || a=='{'){
            s.push(a);
        }
        else{
            if(s.top()=='(' && a==')') s.pop();
            if(s.top()=='{'&& a=='}') s.pop();
            else return -1;
        }
    }
    return 1;

}
