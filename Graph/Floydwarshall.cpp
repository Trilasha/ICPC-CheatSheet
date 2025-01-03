void shortest_distance(vector<vector<ll>> &matrix){
	    for(int i=1;i<=n;++i){
	        for(int j=1;j<=n;++j){
	            if(matrix[i][j]==-1)
	            matrix[i][j]=1e18;
	        }
	    }
	    
	    for(int val=1;val<=n;++val){
	       for(int i=1;i<=n;++i){
	           for(int j=1;j<=n;++j){
	               matrix[i][j]=min(matrix[i][j],matrix[i][val]+matrix[val][j]);
	           }
	       }
	    }
	    for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(matrix[i][j]==1e18)
                matrix[i][j]=-1;
            }
	    }
	}
