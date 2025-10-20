// 39. Combination Sum
// TC: O(N^(T/M)) where N = candidates length, T = target, M = minimal candidate
// SC: O(T/M) for the recursion stack and the space to store results
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> lt = new ArrayList<List<Integer>>();
        List<Integer> subarray = new ArrayList<Integer>();
        int idx = 0;
        backtracking(idx, candidates, target, subarray, lt);
        return lt;
    }

    private void backtracking(int idx, int[] candidates, int target, List<Integer> sub,
        List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(sub));
            return;
        } else if (target < 0) {
            return;
        }

        for (int i = idx; i < candidates.length && candidates[i] <= target; i++) {
            sub.add(candidates[i]);
            backtracking(i, candidates, target - candidates[i], sub, res);
            sub.remove(sub.size() - 1);
        }
    }
}