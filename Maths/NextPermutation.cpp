vector<vector<ll>> generate_all(vector<ll>v){
     vector<vector<ll>>ans;
     do{
          ans.pb(v);
     }while(next_permutation(all(v)));
     return ans;
}
 
 