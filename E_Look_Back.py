def solve():
    n = int(input())
    vec = list(map(int, input().split()))
    count = 0
    for i in range(1, len(vec)): 
        while vec[i] < vec[i-1]: 
            vec[i] *= 2
            count += 1
    print(count)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()