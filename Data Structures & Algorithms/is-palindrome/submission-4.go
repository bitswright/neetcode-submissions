func isPalindrome(s string) bool {
    left := 0
    right := len(s) - 1

    for left < right {
        // skip non-alphanumeric from left
        for left < right && !isAlphaNumeric(rune(s[left])) {
            left++
        }

        // skip non-alphanumeric from right
        for left < right && !isAlphaNumeric(rune(s[right])) {
            right--
        }

        // compare lowercase chars
        if unicode.ToLower(rune(s[left])) != unicode.ToLower(rune(s[right])) {
            return false
        }

        left++
        right--
    }

    return true
}

func isAlphaNumeric(c rune) bool {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9')
}