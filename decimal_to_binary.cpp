int decimalToBinary(int num) {
    int binaryNumber = 0;
    int placeValue = 1; // Represents the position in binary (1, 10, 100, ...)

    while (num > 0) {
        int remainder = num % 2; // Get the least significant bit
        binaryNumber += remainder * placeValue; // Append it at the correct position
        num = num / 2; // Move to the next bit
        placeValue *= 10; // Update place value for the next bit
    }

    return binaryNumber;
}
