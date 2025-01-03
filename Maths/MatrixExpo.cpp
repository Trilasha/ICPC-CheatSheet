struct Matrix{
    vector<vector<ll>> a;
    Matrix(ll n,ll m){
        a.resize(n,vector<ll>(m,0));
    }
    Matrix operator *(const Matrix& other){
        ll x=a.size();
        ll y=a[0].size();
        ll z=other.a[0].size();
        Matrix product=Matrix(x,z);

        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    product.a[i][k]+=a[i][j]*other.a[j][k];
                    product.a[i][k]%=modval;
                }
            }
        }
        return product;
    }
};
 
Matrix expo_power(Matrix a, ll k){
    Matrix product=Matrix(n,n);
    for(ll i=0;i<n;++i){
        product.a[i][i]=1;
    }
    while(k){
        if(k&1){
            product=product*a;
        }
        a=a*a;
        k>>=1;
    }
    return product;
}
//Matrix mat=Matrix(n,n);
//Matrix res=expo_power(mat,k);
//mat.a[i][j]=1;
//O(k^3logN)


