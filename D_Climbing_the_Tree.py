def func():
    q = int(input())
    low, high = -1, (int)(1e19)
    ans = []
    for _ in range(q):
        opr = [int(x) for x in input().split()]
        if opr[0] == 1:
            a, b, days = opr[1:]
            daybef = (a - b) * (days - 1) + b
            dayaft = (a - b) * days + b
            if days == 1:
                daybef = 0
            if high <= daybef:
                ans.append(0)
            elif dayaft <= low:
                ans.append(0)
            else:
                low = max(low, daybef)
                high = min(high, dayaft)
                ans.append(1)
        else:
            a, b = opr[1:]
            l, r = 1, int(1e19)
            while r - l > 1:
                mid = (l + r) // 2
                if (a - b) * (mid - 1) + b >= high:
                    r = mid
                elif (a - b) * mid + b <= low:
                    l = mid + 1
                else:
                    l = mid
            days = l
            daybef = (a - b) * (days - 1) + b
            dayaft = (a - b) * days + b
            if days == 1:
                daybef = 0
            if high <= daybef:
                ans.append(-1)
            elif dayaft <= low:
                ans.append(-1)
            elif days == 1:
                ans.append(days)
            else:
                daybef = (a - b) * (days - 2) + b
                dayaft = (a - b) * (days - 1) + b
                if high <= daybef or dayaft <= low:
                    ans.append(days)
                else:
                    ans.append(-1)
    for i in ans: 
        print(i, end=" ")
    print()

t = int(input())
for _ in range(t):
    func()