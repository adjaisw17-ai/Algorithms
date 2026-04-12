//Print all the combinations of size k of an n sized array
//containing distinct elements only.

//BRUTE FORCE to Backtracking

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++)cin >> arr[i];
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" <<" | ";
//             }
//         }
//     }
// }

// signed main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     solve();
// }

#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr, combination;

void rec(int idx){
    if(combination.size()==k){
        for(int i=0; i<k; i++){
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=idx; i<n; i++){
        combination.push_back(arr[i]);
        rec(i+1);
        combination.pop_back();
    }
}

void solve(){
    cin >> n >> k;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}