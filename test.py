# # automate for bing search
# import pyautogui as py
# import time
# import random

# def randomchar():
#     return chr(random.randint(65, 90))

# py.sleep(5)
# while(True):
#     py.hotkey('command', 'enter')
#     py.press(randomchar())
    
    
import sys

def input():
    return sys.stdin.readline().rstrip()

def print(*args):
    sys.stdout.write(' '.join(map(str,args)) + '\n')

def func():
    q = int(input())
    low, high = -1, float('inf')
    ans = []
    for _ in range(q):
        opr, *args = map(int, input().split())
        if opr == 1:
            a, b, days = args
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
            a, b = args
            day1 = (high - b - 1) // (a - b) + 1
            day2 = (low - b) // (a - b) + 1
            day1 = max(day1, 1)
            day2 = max(day2, 1)
            if day1 == day2:
                ans.append(day1)
            else:
                ans.append(-1)
    return ans

t = int(input())
for _ in range(t):
    ans = func()
    print(*ans)
