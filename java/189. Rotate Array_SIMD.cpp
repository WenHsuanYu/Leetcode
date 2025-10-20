// 189. Rotate Array
// TC: O(n)
// SC: O(1)
#include <algorithm>
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) noexcept {
        const int n = static_cast<int>(nums.size());
        if (n <= 1) [[unlikely]] return;
        k %= n;
        if (k == 0) [[unlikely]] return;

        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};

// TC: O(n)
// SC: O(1)

#include <vector>
#include <immintrin.h>  // AVX intrinsics
#include <algorithm>    // std::reverse

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) noexcept {
        const int n = static_cast<int>(nums.size());
        if (n <= 1) [[unlikely]] return;

        k %= n;
        if (k == 0) [[unlikely]] return;

        // SIMD 反轉法：先整體反轉，再分段反轉
        reverse_simd(nums, 0, n);        // 全部反轉
        reverse_simd(nums, 0, k);        // 前 k
        reverse_simd(nums, k, n);        // 後 n-k
    }

private:
      __attribute__((target("avx2"))) void reverse_simd(std::vector<int>& nums, int start, int end) noexcept {
        int left = start;
        int right = end - 1;

        // 使用 AVX2，每次交換 8 個 int (32 bytes)
        while (right - left + 1 >= 8) {
            __m256i v_left  = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&nums[left]));
            __m256i v_right = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&nums[right - 7]));
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(&nums[left]), _mm256_permutevar8x32_epi32(v_right, _mm256_setr_epi32(7,6,5,4,3,2,1,0)));
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(&nums[right - 7]), _mm256_permutevar8x32_epi32(v_left, _mm256_setr_epi32(7,6,5,4,3,2,1,0)));
            left += 8;
            right -= 8;
        }

        // 處理剩餘不足 8 個的尾巴
        while (left < right) {
            std::swap(nums[left++], nums[right--]);
        }
    }
};