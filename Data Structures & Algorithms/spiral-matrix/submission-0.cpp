class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> result;
        while (right >= left && bottom >= top) {
            for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
            top++;
            if (top > bottom) break;
            for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
            right--;
            if (left > right) break;
            for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
            bottom--;
            if (top > bottom) break;
            for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            left++;
        }
        return result;
    }
};
