class Solution {
public:

    struct Node {
        char lc, rc;
        int pre, suf, mx, len;
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;

        res.lc = a.lc;
        res.rc = b.rc;
        res.len = a.len + b.len;

        res.pre = a.pre;
        if (a.pre == a.len && a.rc == b.lc)
            res.pre = a.len + b.pre;

        res.suf = b.suf;
        if (b.suf == b.len && a.rc == b.lc)
            res.suf = b.len + a.suf;

        res.mx = max(a.mx, b.mx);

        if (a.rc == b.lc)
            res.mx = max(res.mx, a.suf + b.pre);

        return res;
    }

    void build(int idx, int l, int r, string &s) {

        if (l == r) {
            tree[idx] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, s);
        build(idx * 2 + 1, mid + 1, r, s);

        tree[idx] = merge(tree[idx * 2],
                          tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {

        if (l == r) {
            tree[idx] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, ch);
        else
            update(idx * 2 + 1, mid + 1, r, pos, ch);

        tree[idx] = merge(tree[idx * 2],
                          tree[idx * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};