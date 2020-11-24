using namespace std;

const int iterMax = 100;

double sqrt(double a)
{
    double x = a / 2;
    for (int i = 0; i < iterMax; ++i)
        x = (x + a / x) / 2;
    return x;
}
