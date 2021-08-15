public static long fast_pow(int base, int exp) {
    long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res*base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res % mod;
}