class Solution {
public:
    int countOverlaps(vector<vector<int>>& img1,vector<vector<int>>& img2,int row_offset,int col_offset){
        int n = img1.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int colx = j+col_offset;
                int rowx = i+row_offset;
                if(rowx<0 || colx<0 || rowx >= n || colx >= n)
                    continue;
                if(img1[i][j]==1 && img2[rowx][colx]==1)
                    count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int count = 0;
        for(int row_offset = (-1*n+1);row_offset<n;row_offset++){
            for(int col_offset = (-1*n+1);col_offset<n;col_offset++){
                count= max(countOverlaps(img1,img2,row_offset,col_offset),count);
            }
        }
        return count;
    }
};