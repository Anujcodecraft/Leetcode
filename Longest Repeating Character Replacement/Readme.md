# Longest Repeating Character Replacement

You are given a string `s` and an integer `k`. You may choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Your task is to return the length of the longest possible substring that contains only the same letter after at most `k` operations.

---

## ✨ Problem Example

### Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace two 'A's with 'B's or vice versa to get "BBBB" or "AAAA".


### Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace one 'A' in the middle to get "AABBBBA". The longest substring with the same letter is "BBBB".


---

## 🧠 Constraints

- 1 ≤ s.length ≤ 10⁵  
- s consists of only uppercase English letters (A–Z)  
- 0 ≤ k ≤ s.length

---

## ✅ Objective

Find the length of the longest substring containing the same letter you can get after performing at most `k` character replacements.

---

## 🚀 Optimized Python Solution (Sliding Window)

```python
from collections import defaultdict

def characterReplacement(s: str, k: int) -> int:
    freq = defaultdict(int)
    max_count = 0
    left = 0
    res = 0

    for right in range(len(s)):
        freq[s[right]] += 1
        max_count = max(max_count, freq[s[right]])

        # window size - max repeating char count > k ⇒ shrink window
        while (right - left + 1) - max_count > k:
            freq[s[left]] -= 1
            left += 1

        res = max(res, right - left + 1)

    return res
