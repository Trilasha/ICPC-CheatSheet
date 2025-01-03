void kmp(string s,string t,set<int> &stt){
    int n=s.size();
    int m=t.size();
    vector<int> lps(m);
    int i=1,j=0;
    while(i<m){
        if(t[i]==t[j]){
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    i=0,j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        if(j==m){
            stt.insert(i-t.size());
            j=lps[j-1];
        }
        else if(i<n && s[i]!=t[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}