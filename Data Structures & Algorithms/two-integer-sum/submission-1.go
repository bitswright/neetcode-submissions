func twoSum(nums []int, target int) []int {
    index := make(map[int]int)
    for i, n := range(nums) {
        if(index[target - n] != 0) {
            return []int{index[target - n] - 1, i}
        }
        index[n] = i + 1
    }
    return []int{0, 0} // will not be executed
}
