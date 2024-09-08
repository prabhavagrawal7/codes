from fractions import Fraction
import sys
input = sys.stdin.read

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def find_distance_from_circle_center(a, b, rx, ry):
    numerator = (a * rx + b * ry) ** 2
    denominator = a ** 2 + b ** 2
    return Fraction(numerator, denominator)

def find_line_eq(rx, ry):
    a = ry
    b = -rx
    g = gcd(abs(a), abs(b))
    a //= g
    b //= g
    return a, b, 0

def solve_case(n, circles, rs, re):
    rx, ry = re[0] - rs[0], re[1] - rs[1]
    
    # Adjust circles' coordinates relative to rs
    circles = [(x - rs[0], y - rs[1]) for x, y in circles]
    
    a, b, c = find_line_eq(rx, ry)
    
    for cx, cy in circles:
        dist = find_distance_from_circle_center(a, b, cx, cy)
        hypo = Fraction(cx * cx + cy * cy, 1)
        
        # Check if hypo / dist < 2
        hypo /= dist
        if hypo > 2:
            return "NO"
    
    return "YES"

def main():
    data = input().strip().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    
    results = []
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        circles = []
        for _ in range(n):
            x = int(data[idx])
            y = int(data[idx + 1])
            circles.append((x, y))
            idx += 2
        rs = (int(data[idx]), int(data[idx + 1]))
        re = (int(data[idx + 2]), int(data[idx + 3]))
        idx += 4
        
        result = solve_case(n, circles, rs, re)
        results.append(result)
    
    print("\n".join(results))

if __name__ == "__main__":
    main()
