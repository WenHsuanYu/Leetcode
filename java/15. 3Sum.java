class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length == 3) {
            return 0 == nums[0] + nums[1] + nums[2] ?
                Arrays.asList((Arrays.asList(nums[0], nums[1], nums[2]))) :
                new ArrayList<>();
        }
        List<List<Integer>> lt = new ArrayList<List<Integer>>();

        Arrays.parallelSort(nums);
        int l = 0; 
                
        while (l < nums.length - 2 && nums[l] <= 0) {     // l = 1 nums[l] = -1
            if (l > 0 && nums[l-1] == nums[l]) {
                l++;
                continue;
            }
            int left = l + 1;     // left = 2
            int right = nums.length - 1; //right = 4
            while (left < right) { 
                int sum = nums[l] + nums[left] + nums[right]; //-1+-1+2 = 0
                if (sum == 0) {
                    lt.add(Arrays.asList(nums[l], nums[left], nums[right]));
                    while (left < right && nums[left] == nums[++left]);
                    while (left < right && nums[right] == nums[--right]);
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
            l++;
        }
        return lt;
    }
}