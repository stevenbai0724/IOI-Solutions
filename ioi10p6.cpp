//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>weight(n+1);
    vector<bool>vis(n+1);
    vector<vector<int>>adj(n+1);
    vector<int>dis(n+1);
    int start = 0;
    int end = 0;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a++; b++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1 && !start) start = i;
        else end = i;
    }

    queue<int>q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                dis[nxt] = dis[cur]+weight[nxt];
                q.push(nxt);
            }
        }
    }
    
    int ans = 1e18;
    int node = 0;
    for(int i=1;i<=n;i++){
        int d1 = dis[i] - weight[i] + weight[start];
        int d2 = dis[end]-dis[i];
        int dd = max(d1, d2);
        if(dd<ans){
            ans = dd;
            node = i-1;
        }
    }
    cout<<node<<"\n";


    return 0;
}