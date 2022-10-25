#include <iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

#define M_PI 3.14159
typedef complex<double> cd;

vector<cd> fft(vector<cd>& a)
{
    int n = a.size();
    if (n == 1)
        return vector<cd>(1, a[0]);
    vector<cd> w(n);            ///complex roots
    for (int i = 0; i < n; i++)
    {
        double alpha = 2 * M_PI * i / n;
        w[i] = cd(cos(alpha), sin(alpha));
    }
    vector<cd> A0(n / 2), A1(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        A0[i] = a[i * 2];       ///Even coefficients
        A1[i] = a[i * 2 + 1];   ///Odd coefficients
    }
    vector<cd> y0 = fft(A0);
    vector<cd> y1 = fft(A1);
    vector<cd> y(n);
    for (int k = 0; k < n / 2; k++)
    {
        y[k] = y0[k] + w[k] * y1[k];
        y[k + n / 2] = y0[k] - w[k] * y1[k];
    }
    return y;
}
vector<cd> ifft(vector<cd>& a)      ///Inverse FFT
{
    int n = a.size();
    if (n == 1)
        return vector<cd>(1, a[0]);
    vector<cd> w(n);
    for (int i = 0; i < n; i++)
    {
        double alpha = 2 * M_PI * i / n;
        w[i] =cd(cos(alpha), sin(alpha));
    }
    vector<cd> A0(n / 2), A1(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        A0[i] = a[i * 2];
        A1[i] = a[i * 2 + 1];
    }
    vector<cd> y0 = ifft(A0);
    vector<cd> y1 = ifft(A1);
    vector<cd> y(n);
    for (int k = 0; k < n / 2; k++)
    {
        y[k] = y0[k] + y1[k]/w[k];              ///w[k]^-1
        y[k + n / 2] = y0[k] - y1[k]/w[k];
    }
    return y;
}

vector<cd> invfft(vector<cd>&a)         ///last step of inverse fft
{                                       ///divide each element by n
    a=ifft(a);
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        a[i]=a[i]/cd(n);
    }
    return a;
}
vector<cd> mulfft(vector<cd>&a)         ///doubles the quantity of terms by adding n high-order
{                                       ///coefficients of 0
    int n=a.size();                     ///So we can obtain the right quantity of terms as a result
    for(int i=0;i<n;i++)
    {
        a.push_back(0);
    }
    return fft(a);
}

vector<cd> mult(vector<cd>&a,vector<cd>&b)
{
    int n=max(a.size(),b.size());
    vector<cd> c(n);
    for (int i=0;i<n;i++)
    {
        c[i]=a[i]*b[i];
    }
    return c;
}

int main()
{
    vector<cd> a{1, 2, 4, 3, 9, 8, 6, 7, 5};
    vector<cd> b{1, 2, 4, 3, 9, 8, 6, 7, 5};
    // reverse b
    reverse(b.begin(), b.end());
    vector<cd> c;
    a=mulfft(a);
    cout<<endl<<"Vector a: "<<endl;
    for (int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    b=mulfft(b);
    cout<<endl<<"Vector b: "<<endl;
    for (int i=0;i<b.size();i++)
    {
        cout<<b[i]<<endl;
    }
    c = mult(a,b);
    c=invfft(c);
    cout<<endl<<"Vector c: "<<endl;
    for (int i=0;i<c.size();i++)
    {
        cout<<c[i]<<endl;
    }
	return 0;
}