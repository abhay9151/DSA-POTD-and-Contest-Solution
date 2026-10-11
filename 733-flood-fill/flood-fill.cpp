class Solution {
    void dfs(vector<vector<int>>& image,int node,vector<vector<int>>&res,int sr,int sc,int color,vector<vector<int>>&vis){
       int row=image.size();
        int col=image[0].size();

        if(sr<0|| sc<0 || sr>=row || sc>=col){
            return ;
        }
        if(vis[sr][sc] ||image[sr][sc] != node){
            return;
        }
        vis[sr][sc]=1;
        res[sr][sc]=color;
        dfs(image,node,res,sr+1,sc,color,vis);
        dfs(image,node,res,sr-1,sc,color,vis);
        dfs(image,node,res,sr,sc+1,color,vis);
        dfs(image,node,res,sr,sc-1,color,vis);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>res(image.begin(),image.end());
        int row=image.size();
        int col=image[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        int node=image[sr][sc];
        if (node == color) return res;

        dfs(image,node,res,sr,sc,color,vis);
        return res;
    }
};