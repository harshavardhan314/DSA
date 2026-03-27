bool check(int r1,int r2,int c1,int c2,vector<int>vals,int diff,vector<vector<int>>&grid){

    int rows=r2-r1+1;
    int cols=c2-c1+1;

    if(rows*cols==1)return false;

    if(rows>1 && cols>1)return true;

    if(rows==1){
        return grid[r1][c1]==diff || grid[r2][c2]==diff;
    }
    else{
        return grid[r1][c1]==diff || grid[r2][c2]==diff;
    }

}
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int max_val=100001;
        

        long long int total=0;
        vector<int>all_vals(max_val,0);
        for(auto it:grid){
            for(auto r:it){
                total+=r;
                all_vals[r]++;
            }
        }

      
        vector<int>temp=all_vals;
       vector<int>row_vals(max_val,0);

        long long row_sum=0;
        int ele_cnt=n*m;
        int curr_cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                row_sum+=grid[i][j];
                row_vals[grid[i][j]]++;
                all_vals[grid[i][j]]--;
                curr_cnt++;
                ele_cnt--;
            }
            if(row_sum*2==total) return true;
            long long rem_sum=total-row_sum;
            long long diff=abs(row_sum-rem_sum);

            if(diff<max_val){
            if(row_sum>rem_sum){
                if(row_vals[diff]>0){

                    if(check(0,i,0,m-1,row_vals,diff,grid))
                    return true;
                }
            }
            else{
                if(all_vals[diff]>0){

                    if(check(i+1,n-1,0,m-1,all_vals,diff,grid))
                    return true;
                }
            }
            }
        }


        long long col_sum=0;
        vector<int>col_vals(max_val,0);

        ele_cnt=n*m;
        curr_cnt=0;

        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                col_sum+=grid[j][i];
                col_vals[grid[j][i]]++;
                temp[grid[j][i]]--;
                curr_cnt++;
                ele_cnt--;
            }

            if(col_sum*2==total)return true;

            long long rem_sum=total-col_sum;
            long long diff=abs(col_sum-rem_sum);

            if(diff<max_val){
            

            if(col_sum>rem_sum){
                if(col_vals[diff]>0){

                    if(check(0,n-1,0,i,col_vals,diff,grid))
                    return true;
                }

            }
            else{
                if(temp[diff]>0){

                    if(check(0,n-1,i+1,m-1,temp,diff,grid))
                    return true;
                }


            }
            }
        }
        return false;


        
    }
};