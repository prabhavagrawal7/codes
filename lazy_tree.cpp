struct seg
{
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    V<vi> tree;
    ll n;
    seg(ll n)
    {
        this->n = n;
        tree.assign(1 << (clz(n) + 2), {0, 0});
    }
    void push(ll node, ll start, ll end)
    {
        // critical
    }
    void opr(vi &a, vi &b)
    {
        // critical
    }
    void update(ll l, ll r, ll A, ll D, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            // critical
            return;
        }
        push(node, start, end);
        update(l, r, A, D, lnode, start, mid);
        update(l, r, A + D * (mid - start + 1), D, rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
    }
    ll rfind(ll l, ll r, ll val, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return neutral_element;
        else if (l <= start && end <= r)
        {
            // critical
            return tree[node];
        }
        push(node, start, end);
        return opr(rfind(l, r, val, lnode, start, mid),
                   rfind(l, r, val, rnode, mid + 1, end));
    }
};
void func()
{
    newint(n, k);
    seg s(n);
    range(k)
    {
        newint(opr);
        if (opr == 1)
        {
            newint(l, r, A, D);
            l -= 1, r -= 1;
            s.update(l, r, A - D * l, D, 0, 0, n - 1);
        }
        else
        {
            newint(ind);
            ind -= 1;
            print(s.rfind(ind, 0, 0, n - 1));
        }
    }
}
int main()
{
    func();
}
