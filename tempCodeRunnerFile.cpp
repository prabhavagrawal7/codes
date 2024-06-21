ll func()
{
    newint(n);
    n = abs(n);
    int val = 0;
    int steps = 0;
    while (val < n)
    {
        steps++;
        val += steps;
    }
    if (val == n || (val - n) % 2 == 0)
        return (steps) * (steps + 1) / 2;
    return (steps + 1) * (steps + 2) / 2;
}