class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;
        int i=0,j=0,k=0;
        int[] arr =new int[m+n];
        double ans;
        
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                arr[k]=nums1[i];
                i++;
            }
            else
            {
                arr[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<n)
        {
            arr[k]=nums1[i];
            i++;
            k++;    
        } 
        while(j<m)
        {
            arr[k]=nums2[j];
            j++;
            k++;
            
        } 
        n=n+m;
        if(n%2==1){
            ans=arr[n/2];
        }
        else{
            ans=(arr[n/2]+arr[(n/2)-1])/2.0;
        }
        return ans;
    }
}

