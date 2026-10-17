class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = 1LL*n*n;
        long long SN = (N*(N+1))/2, S2N = (N*(N+1)*(2*N+1))/6;
        long long S = 0, S2 = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                S += 1LL*grid[i][j];
                S2 += 1LL*grid[i][j] * grid[i][j];
            }
        }
        // X is repeating number
        // Y is mising number
        long long XYdiff = S - SN;
        long long XYsum = (S2 - S2N) / XYdiff;

        long long X = (XYsum + XYdiff) / 2;
        long long Y = XYsum - X;
        return {(int)X, (int)Y};
    }
};