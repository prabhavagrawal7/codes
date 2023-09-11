office = int(input())
construction = int(input())
contractor = int(input())

def btn(a, b, c): 
    return (a <= b and b <= c) or (a >= b and b >= c)

if not btn(office, construction, 0): 
    print(abs(office))

elif btn(0, construction, contractor): 
    print(-1)

else: 
    print(abs(contractor) + abs(contractor - office))

