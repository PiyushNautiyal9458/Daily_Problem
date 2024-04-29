class Solution {
public:
pair<int,int> solve(vector<vector<int>>& land,int i,int j,int n,int m,int prev_i,int prev_j){
    
    if(i>=n && j>=m){
        return {i-1,j-1};
    }

    if(i>=n)
    {
        return {i-1,j};
    }

    if(j>=m)
    {
        return {i,j-1};
    }

    if(land[i][j]!=1){
        return {prev_i,prev_j};
    }
    land[i][j]=-1;
    prev_i=max(prev_i,i);
    prev_j=max(prev_j,j);
    pair<int,int> p1=solve(land,i,j+1,n,m,prev_i,prev_j);
    pair<int,int> p2=solve(land,i+1,j,n,m,prev_i,prev_j);
    int val1=max(p1.first,p2.first);
    int val2=max(p2.second,p1.second);
    return {val1,val2};
    
}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> answer;
        int n=land.size();
        int m=land[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<int> ans;
                if(land[i][j]==1){
                    pair<int,int> p=solve(land,i,j,n,m,i,j);
                    ans.push_back(i);
                    ans.push_back(j);
                    ans.push_back(p.first);
                    ans.push_back(p.second);
                    answer.push_back(ans);
                }
            }
        }
        return answer;

    }
};