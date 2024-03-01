from fractions import Fraction

def MathChallenge(stArs):
    x1, y1 = stArs[0]
    x2, y2 = stArs[1]
    x3, y3 = stArs[2]
    x4, y4 = stArs[3]

    # Check if the two lines are parallel
    if (x1 - x2) * (y3 - y4) == (x3 - x4) * (y1 - y2):
        return 'no intersection'
    
    # Calculate the intersection point
    px = Fraction((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4), (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4))
    py = Fraction((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4), (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4))

    return f'({px.numerator if px.denominator == 1 else px}/{py.numerator if py.denominator == 1 else py})'

# Example usage:
stArs = ["(3, 0)", "(1, 4)", "(0, -3)", "(2, 3)"]
# parse the input into a list of tuples
stArs = [tuple(map(int, stAr[1:-1].split(', '))) for stAr in stArs]
result = MathChallenge(stArs)
stArs = []
print(result)
