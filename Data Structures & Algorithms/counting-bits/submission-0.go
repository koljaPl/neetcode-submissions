func countBits(n int) []int {
    ans := make([]int, n + 1)
    sub := 1

    for i := 1; i < n + 1; i++ {
        if sub * 2 == i{
            sub = i
        }
            
        ans[i] = ans[i - sub] + 1
    }

    return ans
}