#include <bits/stdc++.h>
using namespace std;

class mystring {
private:
    char *ch = nullptr;
    int len = 0;

public:
    mystring() : ch(nullptr), len(0) {}

    mystring(int _len, int c) : ch(nullptr), len(0) {
        if (_len > 0) {
            len = _len;
            ch = new char[len];
            char cc = static_cast<char>(c);
            for (int i = 0; i < len; ++i) ch[i] = cc;
        }
    }

    mystring(const string &s) : ch(nullptr), len(0) {
        len = static_cast<int>(s.size());
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, s.data(), len);
        }
    }

    mystring(const mystring &other) : ch(nullptr), len(0) {
        len = other.len;
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        }
    }

    mystring &operator=(const mystring &other) {
        if (this == &other) return *this;
        delete[] ch;
        ch = nullptr;
        len = other.len;
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        }
        return *this;
    }

    ~mystring() { delete[] ch; ch = nullptr; len = 0; }

    int get_len() const { return len; }

    char operator[](int idx) const {
        if (idx < 0 || idx >= len) return '\0';
        return ch[idx];
    }

    bool operator<(const mystring &rhs) const {
        int m = min(len, rhs.len);
        for (int i = 0; i < m; ++i) {
            if (ch[i] != rhs.ch[i]) return ch[i] < rhs.ch[i];
        }
        return len < rhs.len;
    }

    bool operator==(const mystring &rhs) const {
        if (len != rhs.len) return false;
        if (len == 0) return true;
        return memcmp(ch, rhs.ch, len) == 0;
    }

    void ADD(const mystring &rhs) {
        if (rhs.len == 0) return;
        if (len == 0) { *this = rhs; return; }
        int nlen = len + rhs.len;
        char *nch = new char[nlen];
        memcpy(nch, ch, len);
        memcpy(nch + len, rhs.ch, rhs.len);
        delete[] ch;
        ch = nch;
        len = nlen;
    }

    void out() const {
        if (len > 0 && ch) cout.write(ch, len);
    }

    friend ostream &operator<<(ostream &os, const mystring &s) {
        if (s.len > 0 && s.ch) os.write(s.ch, s.len);
        return os;
    }

    // Optional conveniences
    mystring &operator+=(const mystring &rhs) { ADD(rhs); return *this; }
    mystring operator+(const mystring &rhs) const { mystring t(*this); t.ADD(rhs); return t; }
};

string str_in1, str_in2;
int n, id;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out(); cout << '\n';
        // cout << str1 << "\n";
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << '\n';
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << '\n';
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); cout << '\n';
        // cout << str2 << "\n";
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << '\n';
        }
        cout << str2.get_len() << ' ' << str3.get_len() << '\n';
        cout << (int)(str2 < str3) << '\n';
        str2.ADD(str3);
        str2.out(); cout << '\n';
        // cout << str2 << "\n";
        cout << str2.get_len() << '\n';
    }
    return 0;
}
