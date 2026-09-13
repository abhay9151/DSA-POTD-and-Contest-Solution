class Solution {
    int countOverlaps(vector<vector<int>>& A,vector<vector<int>>& B,
int rowOff,int colOff) {
        int n = A.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // A[i][j] ka corresponding index B me find karo
                int newRow = i + rowOff;
                int newCol = j + colOff;
                 // Agar B ka index matrix ke andar hai
                if(newRow >= 0 && newRow < n &&newCol >= 0 && newCol < n) {
                    if(A[i][j] == 1 && B[newRow][newCol] == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

public:
    int largestOverlap(vector<vector<int>>& A,vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = 0;
        // Try every possible row shift
        for(int rowOff = -n + 1; rowOff < n; rowOff++) {
            // Try every possible column shift
            for(int colOff = -n + 1; colOff < n; colOff++) {
                int count = countOverlaps(A, B, rowOff, colOff);
                maxOverlap = max(maxOverlap, count);
            }
        }
        return maxOverlap;
    }
};