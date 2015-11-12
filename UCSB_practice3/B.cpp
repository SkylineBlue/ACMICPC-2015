#include<iostream>
#include<algorithm>
#include<vector>
#define P pair<int,int>
#define MAX_N (101)
#define INT_MAX (1<<29)
#define F first
#define S second
#define pb(x) push_back(x)
#include<set>
using namespace std;

int d[MAX_N][MAX_N];
int t , n , k , m;
bool flag[MAX_N];
int father[MAX_N];

void init(){
  for(int i = 0 ; i < MAX_N ; i++){
    father[i] = i;
    for(int j = 0 ; j < MAX_N ; j++){
      d[i][j] = INT_MAX;
    }
  }
}

void read_data(){
  cin>>n>>k>>m;
  int v1 , v2 , c;
  for(int i = 0 ; i < m ; i++){
    cin>>v1>>v2>>c;
    d[v1][v2] = c;
  }
}

void floyd(){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      for(int k = 0 ; k < n ; k++)
	d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    }
  }
}
////////////////////
int getfather(int x){
  //cout<<"getfather "<<x<<endl;
  if(x==father[x])return x;
  else{
    father[x] = getfather(father[x]);
    return father[x];
  }
}

void unite(int x , int y){
  //cout<<"unite"<<endl;
  int fx = getfather(x);
  int fy = getfather(y);
  father[fx] = fy;
  return;
}

bool same(int x , int y){
  //cout<<"same"<<endl;
  return getfather(x)==getfather(y);
}


////////////////

struct E{
  int c , v1 ,v2 ;
  E(int c, int v1 , int v2):c(c),v1(v1),v2(v2){}
  void print(){
    cout<<"cost="<<c<<" v1="<<v1<<" v2="<<v2<<endl;
  }
};
bool cmp(const E e1 , const E e2){
  return e1.c < e2.c;
}
template<class T>
bool inset( T ele , set<T>& s){
  return s.find(ele)!=s.end();
}
void print_ps(vector<E>& ps){
  cout<<"ps infos:"<<endl;
  for(int i = 0 ; i < ps.size() ; i++){
    cout<<"No."<<i<<' ';
    ps[i].print();
  }
  cout<<endl;
}
int solve(){
  floyd();
  set<P > s;
  vector<E> ps;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++){
      E e(d[i][j],i,j);
      P p1(i,j);
      P p2(j,i);
      if( inset(p1,s))continue;
      s.insert(p1);
      s.insert(p2);
      ps.pb(e);
    }
  sort(ps.begin() , ps.end() , cmp);
  //for debug
  print_ps(ps);
  //
  int com_num = n-k;
  int res = 0;
  for(int i = 0 ; i < ps.size() ; i++){
    cout<<i<<"th iteration"<<endl;
    E e = ps[i];
    int v1 = e.v1 , v2 = e.v2 , c = e.c;
    if(same(v1,v2))continue;
    unite(v1,v2);
    com_num--;
    res += c;
    e.print();
    cout<<"res="<<res<<endl;
    if(!com_num)break;
  }
  return res;
  
}




void run(){
  cin>>t;
  while(t--){
    init();
    read_data();
    cout<<solve()<<endl;
  }

}





int main(){
  run();
}
