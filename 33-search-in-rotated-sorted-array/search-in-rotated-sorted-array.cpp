class Solution {
public:
    int search(vector<int>& arr, int target) {

        int n=arr.size();
        
        int l=0;
        int h=n-1;

        while(l<=h){

            int mid=(l+h)/2;

            if(arr[mid]==target){
                return mid;
            }

            // if my array is increasing from l.. to ..mid
            // then i will check in that range..
            if(arr[l]<=arr[mid]){
                if(target>=arr[l] && target<=arr[mid]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }

            // if my array is increasing from mid to h
            // then check in that range...
            else if(arr[mid]<=arr[h]){
                if(target>=arr[mid] && target<=arr[h]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }

            }

            


        }
        return -1;
        
    }
};