class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        prefix.resize(m, vector<int>(n, 0));

        // Build Prefix Sum Matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int top = 0;
                int left = 0;
                int diag = 0;

                if (i > 0)
                    top = prefix[i - 1][j];

                if (j > 0)
                    left = prefix[i][j - 1];

                if (i > 0 && j > 0)
                    diag = prefix[i - 1][j - 1];

                prefix[i][j] = matrix[i][j] + top + left - diag;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        int total = prefix[row2][col2];

        int top = 0;
        int left = 0;
        int diag = 0;

        // Remove upper rectangle
        if (row1 > 0)
            top = prefix[row1 - 1][col2];

        // Remove left rectangle
        if (col1 > 0)
            left = prefix[row2][col1 - 1];

        // Add overlap back
        if (row1 > 0 && col1 > 0)
            diag = prefix[row1 - 1][col1 - 1];

        return total - top - left + diag;
    }
};