// dec to bin
string dectoBin(ll n){
    bitset<64> b(n);
    string s=b.to_string();
    reverse(all(s));
    while(s.size()>0 && s[s.size()-1]=='0')
    s.pop_back();
    reverse(all(s));
    return s;
}

//dec to hex
string dectoHex(ll n){
    string hex="";
    while(n>15){
        ll rem=n%16;
        if(rem<10)
        hex+=to_string(n%16);
        else{
            hex+=((rem==10)?"A":(rem==11)?"B":(rem==12)?"C":(rem==13)?"D":(rem==14)?"E":"F");
        }
        if(n<=15)break;
        n/=16;
    }
    if(n<10)hex+=to_string(n);
    else{
        hex+=((n==10)?"A":(n==11)?"B":(n==12)?"C":(n==13)?"D":(n==14)?"E":"F");
    }
    reverse(all(hex));
    return hex;
}

// lcs in nlogn
int LCS(vector<int>& firstArr,vector<int>& secondArr){
    unordered_map<int, int> mp;
    for (int i = 0; i < firstArr.size(); i++) {
        mp[firstArr[i]] = i + 1;
    }
    vector<int> tempArr;
    for (int i = 0; i < secondArr.size(); i++) {
    // If current element exists in the Map
        if (mp.find(secondArr[i]) != mp.end()) {
            tempArr.push_back(mp[secondArr[i]]);
        }
    }
    vector<int> tail;
    tail.push_back(tempArr[0]);
    for (int i = 1; i < tempArr.size(); i++) {
        if (tempArr[i] > tail.back())
            tail.push_back(tempArr[i]);
        else if (tempArr[i] < tail[0])
            tail[0] = tempArr[i];
        else {
            auto it = lower_bound(tail.begin(),
                                  tail.end(),
                                  tempArr[i]);
            *it = tempArr[i];
        }
    }
    return (int)tail.size();
}


//Mex
ll MEX(vector<ll>&v){
   ll n  = v.size();
   map<ll, ll>m;
   for(int i = 0; i <= n; ++i){
      m[i]++;
   }
   for(int i = 0; i < n; ++i){
      m.erase(v[i]);
   }
   return m.begin()->first;
}

//maximum subarray sum
ll maximum_subarray_sum(vector<ll> &v){
    ll ans=0;
    ll var=INT_MIN;
    fr(i,v.size()){
        var=max(v[i],var+v[i]);
        ans=max(ans,var);
    }
    return ans;
}
