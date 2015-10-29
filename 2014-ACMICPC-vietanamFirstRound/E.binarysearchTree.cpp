#include<iostream>
#include<vector>
#include<cstdio>
#define pb(n) push_back(n)
using namespace std;
const int  MAX_N = 100001;
const int INT_MIN=-(1<<31-1);
const int INT_MAX = 1<<31;
int T,N;


int r[MAX_N],l[MAX_N],par[MAX_N],key[MAX_N];
vector<int> ans;

void read_data(){
  cin>>N;
  for(int i = 0 ; i < N ; i++){
    cin>>l[i]>>r[i]>>key[MAX_N];
    par[l[i]] = i;
    par[r[i]] = i;
  }
}

void init(){
  for(int i = 0 ; i < N ; i++){
    r[i] = l[i] = -1;
    par[i] = i;
    key[i] = -1;
  }
  
}

int  dfs(int root, int lb , int rb){
  int res = 1 ;
  const int val = key[root];
  if(key[l[root]]<key[root])
    res += dfs(l[root],lb,min(rb,val));
  else
    dfs(l[root],INT_MIN,INT_MAX);

  if(key[r[root]]>key[root]){
    res += dfs(r[root],max(val,lb),rb);
  }
  else
    dfs(r[root],INT_MIN,INT_MAX);
  ans.pb(res);
  return res;  
}



int solve(){
  int root = -1;
  for(int i = 0 ; i < N ; i++){
    if(par[i]==i){
      root = i;
      break;
    }
  }
  dfs(root,INT_MIN,INT_MAX);
  int res = INT_MAX;
  for(int i = 0 ; i < ans.size() ; i++){
    res = max(res,ans[i]);
  }
  return res;
}

int main(){
  freopen("Edata.in","r",stdin);
  int T;
  cin>>T;
  while(T--){
    init();
    read_data();
    cout<<solve()<<endl;
  }
  
}
