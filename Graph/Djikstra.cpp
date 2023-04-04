int bfs(int source){
   vector<int>vis(N,0);
   vector<int>dist(N,INF);

   set<pair<int,int>>st;
   st.insert({0,source});
   dist[source]=0;

   while(!st.empty()){
      pair<int,int>p = *st.begin();
      st.erase(st.begin());
      
      int dis = p.first;
      int curr_vec = p.second;
      if(vis[curr_vec]==0){
        for(auto child:graph[curr_vec]){
            int tempdist = dis+child.second;
            if(tempdist<dist[child.first]){
                st.insert({tempdist,child.first});
                dist[child.first] = tempdist;
            } 
        }
      }

      vis[curr_vec]=1;
   }

   
  

}