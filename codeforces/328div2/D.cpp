#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<assert.h>
#include<stdlib.h>
#define pb(x) push_back(x)
#define MAX_N (1000000)
#define P pair<int,int>
#define X first
#define Y second
//#define _DEBUG
using namespace std;

int n , m, E, st , diameter ;
vector<int> road[MAX_N], g[MAX_N];
set<int> s;
set<pair<int ,int > > es;
bool flag[MAX_N];
void init(){
  //  cout<<"in init"<<endl;
  for(int i = 0 ; i < MAX_N ; i++){
    road[i].clear();
    g[i].clear();
  }
  diameter = 0;
  E = 0 ;
  st = MAX_N;
}

void initFlag(){
  for(int i = 0 ; i < MAX_N ; i++)
    flag[i] = false;
} 
void read_data(){
  //  cout<<"in read data"<<endl;
  cin>>n>>m;
  int c1 , c2;
  for(int i = 0 ; i < n-1 ; i ++){
    cin>>c1>>c2;
    c1--;
    c2--;		     
    /*
      P p1(c1,c2);
      P p2(c1,c2);
    
      if(es.find(p1)!=es.end()){
      continue;
      }
    */
    road[c1].pb(c2);
    road[c2].pb(c1);
    /*
      es.insert(p1);
      es.insert(p2);
    */
  }
  for(int i = 0 ; i < m ; i++){
    cin>>c1;
    c1--;
    s.insert(c1);    
  }
}
bool inset(int c){
  return s.find(c)!=s.end();
}


bool build_tree(int r){
  //  cout<<"in build tree"<<endl;
  if(flag[r]) return false;
  flag[r] = true;
  bool flag1 = inset(r);
  for(int i = 0 ; i < road[r].size() ; i++){
    bool res = build_tree(road[r][i]);
    flag1 = flag1 | res;
    if(res){
      g[r].pb(road[r][i]);
      g[road[r][i]].pb(r);
      E++;
    }   
  }
  return flag1;
}

int get_center(){
  for(int c = 0 ; c < n ; c++)
    if(g[c].size()>=2)
      return c;    
}

struct S{
  int c , dep;
};

bool check(int dep1, int c1,int dep2,int c2){
  return (dep1>dep2)||(dep1==dep2 && c1 < c2);
}

S dfs(int r){

  //cout<<"in dfs"<<endl;
  if(flag[r]){
    S state;
    state.c = MAX_N;
    state.dep = 0;
    return state;
  }
  flag[r] = true;
  int m1 = 1 , m2 = 1 , n1 = MAX_N , n2 = MAX_N ;
  for(int i = 0 ; i < g[r].size() ; i++){
    S state = dfs(g[r][i]);
    int c = state.c;
    int dep = state.dep;
    if(check(dep , c , m1 , n1)){
      m1 = dep;
      n1 = c;
    }
    else
      if(check(dep, c, m2, n2)){
	m2 = dep;
	n2 = c;
      }
  }
  if(n1 == MAX_N){
    S state;
    state.c = r;
    state.dep = 1;
    return state;    
  }
  else
    if(n2==MAX_N){
      if(check(m1 , n1 , diameter, st)){
	diameter = m1;
	st = n1;
      }
    }
    else{
      if(check(m1 + m2 , min( n1, n2 ) , diameter , st)){
	diameter = m1 + m2;
	st = min(n1,n2);
      }
    }
  S state ;
  state.c = n1 ;
  state.dep = m1 + 1;
#ifdef _DEBUG
  cout<<"m1="<<m1<<" c1="
      << (n1+1)
      <<" m2="<<m2<<" c2="
      << (n2+1)<<endl;
  cout<<"returned stateInfo:"<< "city="<<state.c+1<<" cost="<<state.dep<<endl;
#endif
  return state;
}




P solve(){
  //  cout<<"in solve"<<endl;
  if(s.size()==1){
    cout<< (*s.begin()) + 1<<endl;
    cout<<0<<endl;
    return P(*(s.begin()),0);
  }
  initFlag();
  build_tree(*(s.begin()));
  int center = get_center();
  initFlag();
  dfs(center);
#ifdef _DEBUG
  cout<<"E="<<E<<' '
      <<"diameter="<<diameter
      <<endl;
#endif

  cout<<st+1<<endl;
  cout<<E*2-diameter<<endl;
  return P(st+1,E*2-diameter);
}

P run(){
  init();
  read_data();
  P p = solve();
  return p;
}
  
void dfs2(){

}

P solve2(){

  for(int i = 0 ; i < n ; i++)
    dfs2();
}



void generate_data(){
  ofstream os("./D.in");
  int n = rand()%10001;
  int m = rand()%1000;
  os<<n<<' '<<m<<endl;
  vector<int> v1,v2;
  vector<P > es;
  for(int i = 0 ; i < n ; i++){
    v1.pb(i+1);
  }
  while(v1.size()){
    int idx = rand()%v1.size();
    v2.push_back(v1[idx]);
    v1.erase(v1.begin() + idx);
    if(v2.size()<=1)continue;
    int idx2 = rand()%(v2.size()-1);
    es.push_back(P(v2[idx2],v2[v2.size()-1]));
  }
  // for check total
  assert(es.size() == n - 1 );
  for(int i = 0 ; i < es.size() ; i++){
    os<<es[i].X<<' '<<es[i].Y<<endl;
  }
  
  for(int i = 0 ; i < m ; i++){
    int idx = rand()%v2.size();
    os<< v2[idx] << ' ';
    v2.erase(v2.begin()+idx);
  }
  os<<endl;
  os.close();
}





int test(){
  init();
  P ans1 = solve(); 
  init();
  P ans2 = solve2();
}

int main(){
  generate_data();
}
