class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int total = accumulate(distance.begin(), distance.end(), 0);
        int dis1 = 0, dis2 = 0;

        if (start > destination) swap(start, destination);

        for (int i = start; i < destination; i++) {
            dis1 += distance[i];
        }

        dis2 = total - dis1;

        return min(dis1, dis2);
    }
};