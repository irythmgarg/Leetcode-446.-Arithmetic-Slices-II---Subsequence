# Leetcode-446.-Arithmetic-Slices-II---Subsequence
# 📐✨ Count Arithmetic Subsequences ✨📐

## 🧩 Problem Statement

Given an array of integers, find the **number of arithmetic subsequences** of length **3 or more**. An arithmetic sequence is a sequence of numbers such that the difference between consecutive elements is the same.

### Example

* **Input:** `[2, 4, 6, 8, 10]`
* **Output:** `7`
* **Explanation:**

  * The arithmetic subsequences are: `[2,4,6]`, `[4,6,8]`, `[6,8,10]`, `[2,4,6,8]`, `[4,6,8,10]`, `[2,4,6,8,10]`, `[2,6,10]`

---

## 🛠️ Approaches

### 🧠 Dynamic Programming with Hash Maps

We use an array of hash maps where each index `i` stores a map of differences (`diff`) and how many subsequences ending at `i` have that difference.

#### 🔍 Step-by-Step Explanation:

1. Traverse every pair of elements `(j, i)` where `j < i`.
2. Calculate the difference `diff = nums[i] - nums[j]`.
3. The count of subsequences ending at `j` with this difference is `v[j][diff]`.
4. These can be extended by appending `nums[i]`, so we add `v[j][diff]` to our answer.
5. Update `v[i][diff]` by adding `v[j][diff] + 1`. The `+1` accounts for the new pair `(nums[j], nums[i])`.

#### ⚠️ Important Notes:

* We use `long long (ll)` to handle large number differences safely and avoid integer overflows.
* Only sequences of length **3 or more** are counted in the final answer. The 2-length sequences are building blocks.

---

## ⏱️ Time Complexity

* **O(N^2)**: We iterate through all pairs `(i, j)` in the array.

## 🧠 Space Complexity

* **O(N \* D)**: Where `D` is the number of unique differences per index (bounded by 2^31 for int values).

---

## 🔁 Example Walkthrough

Input: `[2, 4, 6, 8, 10]`

Let's walk through some iterations:

* `i = 2 (6)`, `j = 1 (4)`, diff = 2

  * Extend `[2,4]` to `[2,4,6]`
* `i = 4 (10)`, `j = 0 (2)`, diff = 8

  * Starts new pair
* `i = 4 (10)`, `j = 2 (6)`, diff = 4

  * Extend `[2,6]` to `[2,6,10]`

Total count at the end = 7

---

## ⚔️ Comparison With Other Approaches

| Approach                           | Time Complexity | Handles Large Inputs | Space Usage | Suitable For      |
| ---------------------------------- | --------------- | -------------------- | ----------- | ----------------- |
| Brute-force triple nested loops 😵 | O(N^3)          | ❌                    | Low         | Small arrays only |
| Dynamic Programming + Maps 🧠      | O(N^2)          | ✅                    | Medium      | Large arrays ✔️   |

---

## 👨‍💻 Author

**Ridham Garg**
🎓 B.Tech Computer Engineering, Thapar University, Patiala
🆔 Roll No: 102203014

---

## 🎉 Final Notes

This is a beautiful use-case of dynamic programming with hash maps to count subsequences efficiently. Using maps at each index allows extension of arithmetic chains elegantly without checking all subsequence combinations. 🚀📊

Stay curious, keep optimizing! 🌟🧮💪
