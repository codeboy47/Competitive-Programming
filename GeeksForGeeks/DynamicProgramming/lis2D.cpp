int original[m][n] = {...};
int longest[m][n] = {0};
/*
Algorithm : find the longest length for every point, and record the result in a 2D array so that we do not need to calculate the longest length for some points again.
Algo :
1) start with a point (and this step has to be taken for all necessary points)
2) if no surrounding point is greater, then this path ends; else pick a greater surrounding point to continue the path, and go to 2).
*/
3) if the (ended) path is longer than recorded longest path, substitute itself as the longest.

int find() {
    int max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int current = findfor(i, j);
            if (current > max) { max = current; }
        }
    }
    return max;
}

int findfor(int i, int j) {
    if (longest[i][j] == 0) {
        int max = 0;
        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                if (!(k == 0 && l == 0) &&
                    i + k >= 0 && i + k < m &&
                    j + l >= 0 && j + l < n &&
                    original[i + k][j + l] > original[i][j]
                   )
                    int current = findfor(i + k, j + l);
                    if (current > max) { max = current; }
                }
            }
        }
        longest[i][j] = max + 1;
    }
    return longest[i][j];
}
