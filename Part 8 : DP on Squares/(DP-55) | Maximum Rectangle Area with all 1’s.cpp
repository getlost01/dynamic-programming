#include <stack>
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	int out = 0,c =0 ;
        for (int j = 0; j < m; ++j) {
		  if(mat[0][j]) ++c;
		  else c = 0;
          out = max(out, c);
        }

        for(int i = 1; i<n;++i){
			stack<int> st;
			vector<int> pre(m);
			int post;
			for(int j = 0; j<m;++j){
				if(mat[i][j])
					mat[i][j] += mat[i-1][j];

				while(!st.empty()){
					if(mat[i][j] > mat[i][st.top()]){
						pre[j] = st.top()+1;
						break;
					}
					st.pop();
				}
				if(st.empty())
					pre[j] = 0;
				
				st.push(j);
			}
			while(!st.empty()) st.pop();
			
			for(int j = m-1; j>=0;--j){
				while(!st.empty()){
					if(mat[i][j] > mat[i][st.top()]){
						post = st.top()-1;
						break;
					}
					st.pop();
				}
				if(st.empty())
					post = m-1;
				
				st.push(j);

				out = max(out, mat[i][j]*( post - pre[j]+1));
			}
	}
    
	
	return out;



}