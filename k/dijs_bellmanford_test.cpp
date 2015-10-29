#include "dijs.cpp"
#include "bellmanford.cpp"
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
    int cost = -(rand()% 10000);
    g[from].push_back(Edge(from,to,cost));
    //g[to].push_back(Edge(to,from,cost));
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

    cout<<"NaiveDijs="<<r1<<" HeapDijs="<<r2<<' '<<(r1==r2?"TRUE":"FALSE")<<endl;
  }
	      
}


void test_bellmanford(){
  Dijs solver;
  BellmanFord bell;
  generate_graph();
  int n = 20;
  while(n--){
    int s = rand()%g.size();
    int t = rand()%g.size();
    int r1 = bell.bellmanford(s,t,g);
    int r2 = solver.dijs(s,t,g);

    cout<<"Bellmanford="<<r1<<" HeapDijs="<<r2<<' '<<(r1==r2?"TRUE":"FALSE")<<endl;
  }
	      
}




int main(){
  int n = 10;
  while(n--)test_bellmanford();
  
}
