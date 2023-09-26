def make_alternating(s):
    min_operations = 0
    different_sequences = 1
    prev_char = s[0]  # Initialize with the first character

    for i in range(1, len(s)):
        if s[i] == prev_char:
            min_operations += 1
        prev_char = s[i]

    # Calculate the number of different sequences modulo 998244353
    for _ in range(min_operations):
        different_sequences = (different_sequences * 2) % 998244353

    return min_operations, different_sequences

# Input
t = int(input())
for _ in range(t):
    s = input()
    min_ops, diff_seq = make_alternating(s)
    print(min_ops, diff_seq)
