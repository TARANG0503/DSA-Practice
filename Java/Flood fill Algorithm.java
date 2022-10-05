class Solution
{
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor)
    {
        // Code here 
        boolean[][] visited=new boolean[image.length][image[0].length];
        getans(image,sr,sc,newColor,visited,image[sr][sc]);
        return image;
    }
    static void getans(int[][] image, int i, int j, int change,boolean[][] visited,int prev){
        if(i<0||j<0||i>=image.length||j>=image[0].length||visited[i][j]==true||image[i][j]!=prev)return;
        visited[i][j]=true;
        image[i][j]=change;
        getans(image,i-1,j,change,visited,prev);
        getans(image,i,j-1,change,visited,prev);
        getans(image,i+1,j,change,visited,prev);
        getans(image,i,j+1,change,visited,prev);
        
    }
}