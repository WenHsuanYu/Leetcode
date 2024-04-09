// TC: O(logn)
// SC: O(logn)
typedef long long ll;
double powPositive(double x, ll n);

double myPow(double x, int n) {

    if (n < 0)
        return powPositive(1 / x, -(long long)n);
    else
        return powPositive(x, n);
}

double powPositive(double x, ll n) {
    if (n == 0)
        return 1;
    double res = powPositive(x, n / 2);
    if (n & 1)
        return res * res * x;
    else
        return res * res;
}
