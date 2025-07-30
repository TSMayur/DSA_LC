class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        
        int total_sum = accumulate(distance.begin(), distance.end(), 0);

        if (start > destination) {
            swap(start, destination);
        }
        
        int clockwise_dist = 0;
        for (int i = start; i < destination; ++i) {
            clockwise_dist += distance[i];
        }
        
        int counter_clockwise_dist = total_sum - clockwise_dist;

        return min(clockwise_dist, counter_clockwise_dist);
    }
};