#include<iostream>
#include<queue>
#include<set>
#include<fstream>
#include<map>
#include<cstring>
#define X first
#define Y second
#define MAX_N (1001)
using namespace std;
typedef long long ll;
#define P pair<ll,int>

priority_queue<P,vector<P > , greater<P > >heap;
int t,k,w,h,sr,sc;
map<char,int> m;
char g[MAX_N][MAX_N];
bool flag[MAX_N*MAX_N];

void init(){
  m.clear(); 
  for(int i = 0 ; i < MAX_N*MAX_N ; i++)
    flag[i] = 0;
  while(!heap.empty())heap.pop();
}
void read_data(){
  cin>>k>>w>>h;
  //cout<<"k="<<k<<" w="<<w<<" h="<<h<<endl;
  for(int i = 0 ; i < k ; i++){
    int v ;
    char c;
    cin>>c>>v;
    m[c] = v;
    //cout<<"map "<<c<<" to "<<v<<endl;
  }
  for(int i = 0 ; i < h ; i++){
    for(int j = 0 ; j < w ; j++){
      cin>>g[i][j];
      if(g[i][j]=='E'){
	sr = i;
	sc = j;
	//cout<<"sr="<<sr<<" sc="<<sc<<endl;
      }
    }
  }
}

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
bool check(int r , int c){
  //cout<<r<<' '<<w<<' '<<c<<' '<<h<<endl;
  return 0<=r && r<h && 0<=c && c<w;
  //return true;
}

int hash(int r , int c){
  return r*w+c;
}
void solve(){
  P p(0,hash(sr,sc));
  heap.push(p);
  
  while(!heap.empty()){
    P p = heap.top();
    int key = p.Y;
    ll  val = p.X;
    int r = key/w;
    int c = key%w;
    //cout<<"row="<<r<<" col="<<c<<" key="<<key<<" val="<<val<<endl;
    if(r==0||c==0||r==h-1||c==w-1){
      cout<<val<<endl;
      return;
    }
    heap.pop();
    for(int i = 0 ; i < 4 ; i++){
      int nr = r+dx[i];
      int nc = c+dy[i];
      if(!check(nr,nc))continue;
      int key = hash(nr,nc);
      if(flag[key])continue;
      flag[key] = true;
      ll nv = val + m[g[nr][nc]];
      P p(nv, key);
      heap.push(p);
    }
  }
}


int run(){
  cin>>t;
  while(t--){
    //cout<<"t="<<t<<endl;
    init();
    read_data();
    solve();
  }
}






int main(){
  // test();
  run();
}
