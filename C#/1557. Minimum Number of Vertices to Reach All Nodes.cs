public class Solution {
    public IList<int> FindSmallestSetOfVertices(int n, IList<IList<int>> edges) {
        List<int> res = new();
        HashSet<int> endNodes = new();
        
        foreach (var edge in edges)
        {
            endNodes.Add(edge[1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (endNodes.Contains(i) is false)
                res.Add(i);
        }
        return res;
    }
}