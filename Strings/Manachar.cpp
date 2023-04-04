struct manacher{
    vector<int>p;
    void run_manacher(string s){
        int n = s.length();
        p.assign(n,1);
        int l=1,r=1;
        for(int i=1;i<n;i++){
            p[i] = max(0ll,min(r-i,p[l+r-i]));
            while(i+p[i]<n and i-p[i]>=0 and s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }

            if((i+p[i])>r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }
    void build(string s){
        string t;
        for(auto i:s){
            t.push_back('#');
            t.push_back(i);
        }
        t.push_back('#');
        run_manacher(t);
    } 

    int get_longest(int index,bool odd){
        if(odd){
            return (p[(2*index)+1])-1;
        }else{
            return (p[2*(index+1)])-1;
        }
    }

    bool check_palindrome(int l,int r){
        int l1 = l,r1=r;
        l = (2*l+1);
        r = (2*r+1);
        int index = (l+r)>>1;
        if(p[index]-1>=(r1-l1+1)){
            return true;
        }else{
            return false;
        }

    }

}m;