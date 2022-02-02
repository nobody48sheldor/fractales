#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <complex>
#include <sstream>

using namespace std;

int write_data(vector<vector<double>> data, int n)
{
    ofstream output_file;
    output_file.open("data_julia.txt");
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
    int T = 200;
    int n = 200;
    int M;
    double re_c;
    double im_c;
    complex<double> z (0, 0);
    string line;
    string re;
    string im;

    fstream input_file;

    input_file.open("input.txt",ios::in);
    getline(input_file, re);
    getline(input_file, im);
    input_file.close();


    re_c = stod(re);
    cout << re_c <<endl;
    re_c = 4*(re_c-(1000/2))/1000;
    im_c = stod(im);
    cout << im_c <<endl;
    im_c = 4*(im_c-(1000/2))/1000;

    cout <<re_c << " / " << im_c << endl;

    vector<double> X;
    X.resize(n);
    X = linspace(-2, 2, n);

    vector<double> Y;
    Y.resize(n);
    Y = linspace(-2, 2, n);

    vector<double> empty;
    empty.resize(n);
    empty = linspace(0, 0, n);
    vector<double> Mandelbrot_x;
    Mandelbrot_x.resize(n);
    vector<vector<double>> Mandelbrot_y;
    Mandelbrot_y.resize(n);

    complex<double> c (re_c, im_c);

    for (int y = 0; y < n; y++)
    {
        // cout << "y = " << y << " / " << n << endl;
        Mandelbrot_x = empty;
        for (int x = 0; x < n; x++)
        {
            complex<double> z (X[x],Y[y]);
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
    }
    write_data(Mandelbrot_y, n);
    system("python3 plot-a-frame_julia.py");

    return 0;
}
