func rob(nums []int) int {
    prev1 := 0
    prev2 := 0

    for _, money := range nums {
        temp := max(money + prev1, prev2)
        prev1 = prev2
        prev2 = temp
    }

    return prev2
}