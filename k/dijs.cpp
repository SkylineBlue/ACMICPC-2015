#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#define INT_MAX (1<<30)
using namespace std;
typedef pair<int,int> P;


struct Edge{
  int from , to,cost ;
  Edge(int from , int to , int cost) :from(from), to(to), cost(cost){}
};



struct Dijs{

  int dijs(int s,  int t, const vector<vector<Edge> >& g){
    priority_queue<P,vector<P>, greater<P> > heap;
    int n = g.size();
    int *d = new int[n];
    fill(d,d+n,INT_MAX);
    d[s] = 0 ;
    heap.push(P(0,s));
    while(!heap.empty()){
      P p = heap.top(); heap.pop();
      int v = p.second;
      if(d[v] < p.first)continue;
      for(int i = 0 ; i < g[v].size() ; i++){
	Edge e = g[v][i];
	if(d[e.to] > d[v]+e.cost){
	  d[e.to] = d[v]+e.cost;
	  heap.push(P(d[e.to],e.to));
	}
      }
    }
    int ans = d[t];
    delete d;
    return ans;
  }

  
  int dijsNaive(int s , int t , const vector<vector<Edge> > & g){
    int n = g.size();
    int* d = new int[n];
    bool *flag = new bool[n];
    fill(d,d+n,INT_MAX);
    for(int i = 0 ; i < n ; i++) flag[i] = false;
    d[s] = 0;
    while(1){
      int node = -1, minn = INT_MAX;
      for(int i = 0 ; i < n ; i++){
	if(d[i] < minn && (!flag[i])){
	  node = i;
	  minn = d[i];
	}
      }
      if(node==-1)break;
      flag[node] = true;;
      for(int i = 0 ; i < g[node].size() ; i++){
        Edge e = g[node][i];
	d[e.to] = min(d[e.to],d[e.from]+e.cost);
      }
    }
    delete flag;
    int ans = d[t];
    delete d;
    return ans;
  }





  
};


vector<vector<Edge> > g;
void generate_graph(){
  g.clear();
  int graph_size = rand()%200;
  for(int i = 0 ; i < graph_size ; i++)
    g.push_back(vector<Edge>());
  int E = rand() % (graph_size*graph_size);
  for(int i = 0 ; i < E ; i++){
    int from = rand()%graph_size;
    int to = rand()%graph_size;
    int cost = rand()% 10000;
    g[from].push_back(Edge(from,to,cost));
    g[to].push_back(Edge(to,from,cost));
  }
}

void test(){
  Dijs solver;
  generate_graph();
  int n = 20;
  while(n--){
    int s = rand()%g.size();
    int t = rand()%g.size();
    int r1 = solver.dijsNaive(s,t,g);
    int r2 = solver.dijs(s,t,g);
    cout<<"r1="<<r1<<" r2="<<r2<<' '<<(r1==r2?"TRUE":"FALSE")<<endl;
  }
	      
}




int main(){
  int n = 10;
  while(n--)test();
  
}
