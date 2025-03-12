/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumCount = function (nums) {
  return Math.max(
    [...nums.filter((item) => item > 0)].length,
    [...nums.filter((item) => item < 0)].length
  );
};
