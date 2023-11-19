#include <iostream>
#include <fstream>




int main()
{
    int a;

    int b;

    int h;

    int n;

    bool stream;

    std::cout << "enter a:"; std::cin >> a;       //ліва границя
    std::cout << "enter b:"; std::cin >> b;       //права границя
    std::cout << "enter n[3,int):"; std::cin >> n;//права границя внутрішнього циклу
    std::cout << "enter h[1,int):"; std::cin >> h;//крок зовнішнього циклу
    std::cout << "do you wanna to write to file(1,0):"; std::cin >> stream;
    std::ofstream fout("file.txt");
    if (a > b || h <= 0 || n < 2 || stream != true && stream != false) {
        return 0;
    }
    

   
    
    double x = a;
    while (x < b)
    {
        
        double y;
        if (x <= 0) {
            y = 1;
            for (int i = 0; i < n - 1; ++i) {
                y *= (i * i + i);
            }
        }
        else {
            y = 0;
            for (int i = 0; i < n - 1; ++i) {
                double s = 0;
                for (int j = 0; j < n - 1; ++j) {
                    s += x / (i + j);
                }
                y += s;
            }
        }
        if (stream) {
            fout << "x:" << x << std::endl;
            fout << "y:" << y << std::endl;
            fout << "n:" << n << std::endl;
        }

        
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl << std::endl;

        x += h;
    }


    fout.close();
}

