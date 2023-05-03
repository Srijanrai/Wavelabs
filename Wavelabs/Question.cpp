#include <bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>>>times;
vector<int> dijkestra(int n,int k){
    vector<int>dist(n+1,1e7);
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> >pq;
    pq.push({k,0});
    dist[k]=0;
    while(pq.size()>0){
       int node = pq.top().first; pq.pop();
        for(pair<int,int>p : times[node]){
            int child = p.first; 
            int cost = p.second;
            if(dist[child] > dist[node] + cost){
                dist[child] = dist[node] + cost; 
                pq.push({child,dist[child]});
            }
        }
    }
    return dist;
}
int main() {
   int length ;
   cin>>length;
   for(int i = 0 ; i < length;i++){
       int u,v,w;
       cin>>u>>v>>w;
       times[u].push_back({v,w});
   }
   int n,k;  
   cin>>n>>k;
   vector<int>dis = dijkestra(n,k);
   int ans = 0 ; 
   for(int i = 1 ; i <= n ; i++){
       ans=max(ans,dis[i]);
   }
   if(ans == 1e7)ans=-1;
   cout<<ans;
	return 0;
}