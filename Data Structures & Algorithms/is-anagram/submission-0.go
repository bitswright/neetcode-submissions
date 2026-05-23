func isAnagram(s string, t string) bool {
    freq := make([]int, 26)
    for _, c := range(s) {
        freq[c - 'a'] += 1
    }
    for _, c := range(t) {
        freq[c - 'a'] -= 1
    }
    for _, f := range(freq) {
        if(f != 0) {
            return false;
        }
    }
    return true;
}
