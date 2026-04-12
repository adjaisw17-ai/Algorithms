
#include<bits/stdc++.h>
using namespace std;

//Two Pointers Class Question.

int freq[1000100];
int n,k;
vector<int> arr(n);
int distinct=0;

int can_eat(int x){
    int temp=distinct;
    if(freq[x]==0)temp++;
    if(temp<=k)return 1;
    return 0;   
}

void insert_in_window(int x){
    if(freq[x]==0)distinct++;
    freq[x]++;
}

void remove_from_window(int x){
    freq[x]--;
    if(freq[x]==0){
        distinct--;
    }
}
void solve(){
    //we need to keep track of distinct elements using freq arr;
    //given that maximum value of an element in that arr is, let's say
    //MAX_VAL, then, we make an array of that size .
    //In this que, we'll suppose that max value of an input is 1e6
    //note, since we are talking about number of distinct elements in
    //a paritcular window, we'll use freq arr for that window.
    
    //The idea is to apply two pointers/
    //1.We'll keep track of number of distinct elements from arr[tail]
    //to arr[head].
    //2.We'll design a data structure which will check if the next element
    //can be eaten or not, and if yes then eat, else move the tail forward.
    cin >> n >> k;
    arr.resize(n);
    for(int i=0; i<n; i++)cin >> arr[i];
    int head=-1, tail=0;
    int len=0;
    while(tail<n){
        while(head+1<n && can_eat(arr[head+1])){
            head++;
            insert_in_window(arr[head]);
        }
        len+=head-tail+1;
        if(tail<=head){
            remove_from_window(arr[tail]);
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    cout << len << endl;

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}