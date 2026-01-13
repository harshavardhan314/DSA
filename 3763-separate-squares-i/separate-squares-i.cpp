class Solution {
public:
    bool check(double mid,vector<vector<int>>&s,double area){
        double low=0,high=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            double x=s[i][0];
            double y=s[i][1];
            double l=s[i][2];
            if(y+l<=mid)
            {
                low+=(l*l*1.0);
            }
            else if(y>=mid)
            {
                high+=(l*l*1.0);
            }
            else
            {
                double total=(l*l);
                double lower_part=(mid-y)*l;
                low+=lower_part;
                high+=total-lower_part;
            }

        }
        return low>=(area)/2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double l=0;
        double h=2e9;
        double ans=0;
        double area=0;
        for(int i=0;i<squares.size();i++)
        {
            double side=squares[i][2];
            area+=side*side;

        }
        while((h-l)>1e-5)
        {
            double mid=(l+h)/2;
            if(check(mid,squares,area))
            {
                h=mid;
            }
            else
            l=mid;
        }
        return l;
        
    }
};