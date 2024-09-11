int gcd(int a, int b) {
    // Ensure that a is always greater than b
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
