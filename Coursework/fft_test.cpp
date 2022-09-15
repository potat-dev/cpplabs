// Реализовать умножение длинных чисел с помощью быстрого преобразования Фурье (нерекурсивный вариант)

#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

typedef complex<double> cd;

void fft(vector<cd> &a, bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (cd &x : a)
            x /= n;
}

vector<int> multiply(vector<int> const &a, vector<int> const &b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = int(fa[i].real() + 0.5);
    // нормализация
    for (int i = 0; i < n - 1; i++)
    {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    return result;
}

int main()
{
    vector<int> a = {6, 1, 8};
    vector<int> b = {4, 2, 0, 6, 9};
    vector<int> c = multiply(a, b);
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    return 0;
}