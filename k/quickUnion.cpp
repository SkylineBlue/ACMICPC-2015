#include<iostream>

using namespace std;

const int MAX_N = 100000;
int par[MAX_N];
int rank[MAX_N];

void init(int n){
  for(int i = 0 ; i < n ; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] ==x)return x;
  else{
    par[x] = find(x);
    return par[x];
  }
}

void unite(int x , int y){
  x = find(x);
  y = find(y);
  if(rank[x]<rank[y]){
    par[x] = y;
  }
  else{
    par[y] = x;
    if(rank[x] == rank[y])rank[x]++;
  }
  
}

bool same(int x , int y){
  return find(x)==find(y);
}
