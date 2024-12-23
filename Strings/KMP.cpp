vll kmp ( string &s){
    ll n = s.size();
    vll pi(n , 0);
    for(int i = 1 ; i < n ; i ++){
        ll j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
vector<vll>aut;
void compute_automaton(string s){
    s += '#';
    vll pi = kmp(s);
    ll n = s.size();
    for(int i = 0 ; i < n ;i++ ){
        for(int j = 0 ; j < 26 ; j ++ ){
            if(i > 0 && s[i]!='a'+j){
                aut[i][j] = aut[pi[i-1]][j];
            }else{
                aut[i][j] = i + ('a'+j == s[i]);
            }
        }
    }
}
vector<int> zFunction(string &str){
    int n = str.length();
    vector<int>ans(n);int l = 0,r = 0;
    for(int i=1;i<n;i++){
        if(i <= r){
            ans[i] = min(ans[i-l],r-i+1);
        }
        while((i+ans[i])<n and (str[ans[i]] == str[i+ans[i]])){
            ans[i]++;
        }
        if((i+ans[i]-1)>r){
            l = i;
            r = i+ans[i]-1;
        }
    }
    return ans;
}
