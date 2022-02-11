#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <complex>

using namespace std;

int write_data(vector<vector<double>> data, int n)
{
    ofstream output_file;
    output_file.open("data.txt");
    for (int ypos=0; ypos < n; ypos++)
    {
        //cout << ypos << endl;
        for (int xpos=0; xpos < n; xpos++)
        {
            output_file << data[ypos][xpos] << '/';
        }
    }
    output_file.close();
    return 0;
}
auto linspace(double l_0, double l_1, int n)
{
    vector<double> array;
    array.resize(n);

    for (int i = 0; i < n; i++)
    {
        array[i] = l_0 + (i*(l_1 - l_0)/n);
    }
    return array;
}

auto Func(complex<double> z, complex<double> c)
{
    complex<double> Z;
    Z = z*z + c;
    return Z;
}

int main()
{
    int T = 400;
    int n = 1000;
    int M;
    double re_c;
    double im_c;
    complex<double> z (0, 0);

    double Xr;
    double Yr;

    string line;
    string re;
    string im;

    fstream input_file;

    input_file.open("input_zoom.txt",ios::in);
    getline(input_file, re);
    getline(input_file, im);
    input_file.close();


    Xr = stod(re);
    cout << Xr <<endl;
    Xr = 4*(Xr-(1000/2))/1000;
    Yr = stod(im);
    cout << Yr <<endl;
    Yr = 4*(Yr-(1000/2))/1000;

    cout << Xr << " / " << Yr << endl;
    vector<double> X;
    X.resize(n);
    X = linspace(Xr-0.04, Xr+0.04, n);

    vector<double> Y;
    Y.resize(n);
    Y = linspace(Yr-0.04, Yr+0.04, n);

    vector<double> empty;
    empty.resize(n);
    empty = linspace(0, 0, n);
    vector<double> Mandelbrot_x;
    Mandelbrot_x.resize(n);
    vector<vector<double>> Mandelbrot_y;
    Mandelbrot_y.resize(n);

    for (int y = 0; y < n; y++)
    {
        // cout << "y = " << y << " / " << n << endl;
        Mandelbrot_x = empty;
        for (int x = 0; x < n; x++)
        {
            complex<double> z (0,0);
            complex<double> c (X[x],Y[y]);
            for (int i = 0; i < T; i++)
            {
                z = Func(z, c);
                // cout << z << x << y << endl;
            }
            if (norm(z) != norm(z))
            {
                M = 0;
            }
            else
            {
                M = 1;
            }
            Mandelbrot_x[x] = M;
        }
        Mandelbrot_y[y] = Mandelbrot_x;
        // if ((100*y)%n == 0)
        // {
            // cout << 100*y/n << " / " << "100" << endl;
        // }
    }
    write_data(Mandelbrot_y, n);
    system("python3 plot-a-frame.py");

    return 0;
}
