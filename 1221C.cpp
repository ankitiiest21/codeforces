//Problem Link- https://codeforces.com/contest/1221/problem/C
//Solution Link- https://codeforces.com/contest/1221/submission/61344947

#include<iostream>
#include<bits/stdc++.h> 
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ll long long int
#define ld long double
#define vl vector<ll>
#define vp vector<pair<ll, ll> >
#define sl set<ll>
#define N 1000005
#define mod 1000000007
using namespace std;
//vector<ll> ans[N];
// vector<ll> graph[N];
// bool visited[N];
//ll odd[N+1],even[N+1];
ll myfunc(ll*a,ll*b,ll n,ll m){
	if(n==1)
	 return ((a[n]>b[m])?-1:1);
	vector<ll> temp;
 	for(ll j=1;j<=sqrt(n)&&j<=m;j++){
 		if(n%j==0){
 			 if(n/j==j){
 			 	if(b[j]>=a[n])
 			 	 return j;
 			 }
 			else{
 				if(b[j]>=a[n])
 				 return j;
 				if(n/j<=m)
 				temp.PB(n/j);
 			}
 		}
   }
for(ll k=temp.size()-1;k>=0&&temp[k]<=m;k--){
 		 if(b[temp[k]]>=a[n])
 		 	return temp[k];
 		}
 return -1;
}
// void dfs(ll node,ll a[],ll &mini){
// 	mini=min(mini,a[node]);
// 	visited[node]=true;
// 	for(ll i:graph[node]){
// 		if(!visited[i])
// 		 dfs(i,a,mini);
// 	}
// }
// void addedge(ll u,ll v){
// 	graph[u-1].PB(v-1);
// 	graph[v-1].PB(u-1);
// }
// ll MSCC(ll a[],ll n){
// 	ll sum=0;
// 	for(ll i=0;i<n;i++){
// 		if(!visited[i]){
// 			ll mini=a[i];
// 			dfs(i,a,mini);
// 			sum+=mini;
// 		}
// 	}
// 	return sum;
// }
bool sortbyfirst(const pair<ll,ld> &a,const pair<ll,ld> &b)
{ 
if(a.first>b.first)
return true;
else
 return false;
}
bool sortbysecond(const pair<ll,ld> &a,const pair<ll,ld> &b)
{ 
if(a.second<b.second)
return true;
else
 return false;
}
ll sumofdigits(ll n)
{
 ll ans=0;
 while(n)
 {
  ans+=n%10;
  n/=10;
 } 
 return ans;
}
void swap(int &a,int &b){
	a^=b^=a^=b;
}
ll solve(ll n,ll r){
	ll c[r+1]={0};
	c[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=min(i,r);j>0;j--)
			c[j]=c[j]+c[j-1];
	}
	return c[r];
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
ios::sync_with_stdio(0);
cin.tie(0);
ll t;
cin>>t;
while(t--){
 ll c,m,x;
 cin>>c>>m>>x;
 ll ans=min(c,m);
 if(x+max(c,m)-min(c,m)>=ans)
  cout<<ans<<endl;
 else
  cout<<(c+m+x)/3<<endl;
}
return 0;
}