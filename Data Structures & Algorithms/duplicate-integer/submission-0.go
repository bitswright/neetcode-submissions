func hasDuplicate(nums []int) bool {
    present := make(map[int]bool)
    for _, num := range nums {
        if(present[num]) {
            return true;
        }
        present[num] = true;
    }
    return false;
}
