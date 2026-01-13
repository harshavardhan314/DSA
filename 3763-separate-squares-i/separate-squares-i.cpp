class Solution {
public:
    bool check(double mid, vector<vector<int>>& s, double area) {
        double low = 0, high = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            double y = s[i][1];
            double side = s[i][2];

            if (y + side <= mid) {
                low += side * side;
            }
            else if (y >= mid) {
                high += side * side;
            }
            else {
                double lower_part = (mid - y) * side;
                low += lower_part;
                high += side * side - lower_part;
            }
        }

        return low >= area / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 2e9;
        double area = 0;

        for (auto &sq : squares) {
            double y = sq[1];
            double side = sq[2];
            area += side * side;
        }

        double eps = 1e-6;

        while (high - low > eps) {
            double mid = (low + high) / 2.0;
            if (check(mid, squares, area))
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};
