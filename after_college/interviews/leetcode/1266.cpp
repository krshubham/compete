class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
      int total_time = 0;
        for(int i = 1; i < points.size(); i++) {
            int x_dist = abs(points[i][0] - points[i-1][0]);
            int y_dist = abs(points[i][1] - points[i-1][1]);

            total_time += x_dist > y_dist ? x_dist : y_dist;
        }
        return total_time;
    }
};
