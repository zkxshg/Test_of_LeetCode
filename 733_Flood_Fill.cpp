// DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int len = image.size(), wid = image[0].size();
        if (len == 1 && wid == 1) {
            image[0][0] = newColor;
            return image;
        }
        vector<vector<int>> imageDict(len, vector<int>(wid, 1));
        flood(image, sr, sc, newColor, image[sr][sc], imageDict);
        return image;
    }
    
    void flood(vector<vector<int>>& image, int sr, int sc, int newColor, int startColor, vector<vector<int>>& dict) {
        int len = image.size(), wid = image[0].size();
        if (image[sr][sc] == startColor) {
            image[sr][sc] = newColor;
            dict[sr][sc] = 0;
            if (sr > 0 && dict[sr-1][sc]) flood(image, sr - 1, sc, newColor, startColor, dict);
            if (sr < len - 1 && dict[sr + 1][sc]) flood(image, sr + 1, sc, newColor, startColor, dict);
            if (sc > 0 && dict[sr][sc - 1]) flood(image, sr, sc - 1, newColor, startColor, dict);
            if (sc < wid - 1 && dict[sr][sc + 1]) flood(image, sr, sc + 1, newColor, startColor, dict);
        }
    }
};
