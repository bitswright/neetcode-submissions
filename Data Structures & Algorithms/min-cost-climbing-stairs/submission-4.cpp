class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		int prev = 0, curr = cost[0], next;
		for(int i = 1; i < n; ++i) {
			next = min(prev, curr) + cost[i];
			prev = curr;
			curr = next;
		}
		return min(prev, curr);
    }
};