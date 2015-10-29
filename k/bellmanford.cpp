
struct BellmanFord{

  
  int bellmanford(int s , int t , vector<vector<Edge> > g){
    //cout<<"In bellmanford"<<endl;
    int E = 0 ;
    int V = g.size();
    int * d = new int[V];
    fill(d,d+V,INT_MAX);
    d[s] = 0;
    vector<Edge> es;
    for(int i = 0 ; i < g.size() ; i++)
      for(int j = 0 ; j < g[i].size() ; j++){
	E++;
	es.push_back(g[i][j]);
      }
    int c = 0 ;
    while(1){
      c++;
      if(c==V){
	cout<<"Neg Circle in Graph!"<<endl;
	return -1;
      }
      bool update = false;
      for(int i = 0 ; i < E ; i++){
	const Edge &e = es[i];
	if(d[e.from] != INT_MAX && d[e.from]+e.cost<d[e.to]){
	  d[e.to] = d[e.from]+e.cost;
	  update = true;
	}
      }
      if(!update)break;
    }
    int res = d[t];
    delete d;
    return res;
    
  }

  
};


