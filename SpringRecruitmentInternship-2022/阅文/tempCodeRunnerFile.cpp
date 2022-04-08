int main() {
    string s;
    int n;
    vector<int> v;
    while (cin >> s) {
        if (s == "push") {
            cin >> n;
            v.push_back(n);
            cout << v.size() << endl;
        } else if (s == "pop") {
            cout << !v.empty() ? v.back() : -1 << endl;
            if (!v.empty()) {
                v.pop_back();
            }
        } else if (s == "get") {
            cin >> n;
            if (n < 0 || n >= v.size()) {
                cout << -1 << endl;
            } else {
                cout << v[n] << endl;
            }
        }
    }
    return 0;
}