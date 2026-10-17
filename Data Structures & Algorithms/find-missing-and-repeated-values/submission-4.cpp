class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = n*n;
        int XYxor = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                XYxor ^= grid[i][j];
                XYxor ^= (i*n + j + 1);
            }
        }

        int diffBit = 1;
        for(int i = 0; i < 32; ++i) {
            if(XYxor & diffBit) {
                break;
            }
            diffBit <<= 1;
        }

        int oneSetBitNumber = 0;
        int zeroSetBitNumber = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] & diffBit) {
                    oneSetBitNumber ^= grid[i][j];
                } else {
                    zeroSetBitNumber ^= grid[i][j];
                }
                if((i*n + j + 1) & diffBit) {
                    oneSetBitNumber ^= (i*n + j + 1);
                } else {
                    zeroSetBitNumber ^= (i*n + j + 1);
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == oneSetBitNumber) {
                    return {oneSetBitNumber, zeroSetBitNumber};
                }
                if(grid[i][j] == zeroSetBitNumber) {
                    return {zeroSetBitNumber, oneSetBitNumber};
                }
            }
        }
    }
};