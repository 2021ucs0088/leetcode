class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        string subset = "";
        vector<string> result;
        sort(tiles.begin(), tiles.end());
        vector<bool> visited(n, false);
        func(result, subset, tiles, visited, 0);
        return result.size() - 1; 
    }

    void func(vector<string>& result, string& subset, string& tiles, vector<bool>& visited, int idx) {
        result.push_back(subset);
        for (int i = 0; i < tiles.size(); i++) { 
            if (visited[i]) continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1]) continue;
            subset += tiles[i];
            visited[i] = true;
            func(result, subset, tiles, visited, idx); 
            subset.pop_back();
            visited[i] = false;
        }
    }
};
