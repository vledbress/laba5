#include <iostream>
#include <fstream>

void checkValidInput() {
    if (std::cin.fail()) { throw "Incorrect input"; }
}

void check_valid_params(double& a, double& b, double& h, int& n) {
    if (a > b || h <= 0 || n < 2 ) {
        throw "Incorrect input data";
    }
}

double calculate(double& x, int& n) {
    double y;
    if (x <= 0) {
        y = 1;
        for (int i = 1; i < n - 1; ++i) {
            y *= (i * i + i);
        }
    }
    else {
        y = 0;
        for (int i = 1; i < n - 1; ++i) {
            double s = 0;
            for (int j = 1; j < n - 1; ++j) {
                s += x / (i + j);
            }
            y += s;
        }
    }
    return y;
}

void calculate_in_a_loop(double& x, double& b, double& h, int& n, bool& stream) {
    std::ofstream fout("file.txt");
    while (x < b) {
        if (stream) {
            fout << "Y = " << calculate(x, n) << std::endl;
            fout << "X = " << x << std::endl;
        }
        std::cout << "Y = " << calculate(x, n) << std::endl;
        std::cout << "X = " << x << std::endl;
        x += h;
    }
    fout.close();
}


int main()
{
    double a;
    double b;
    double h;
    int n;
    bool stream;
   
    std::cout << "enter a:"; std::cin >> a;       //ліва границя
    std::cout << "enter b:"; std::cin >> b;       //права границя
    std::cout << "enter n[3,int):"; std::cin >> n;//права границя внутрішнього циклу
    std::cout << "enter h[1,int):"; std::cin >> h;//крок зовнішнього циклу
    std::cout << "do you wanna to write to file(1,0):"; std::cin >> stream;
    checkValidInput();
    calculate_in_a_loop(a, b, h, n, stream);
   
}

