#include<iostream>
#include<math.h>
#include<bitset>

using namespace std;

// Function to perform binary addition
bitset<32> addBinary(const bitset<32>& num1, const bitset<32>& num2) {
    bitset<32> sum;
    int carry = 0;
    for (int i = 0; i < 32; ++i) {
        int bitsum = num1[i] + num2[i] + carry;
        sum[i] = bitsum % 2;
        carry = bitsum / 2;
    }
    return sum;
}

bitset<32> multiply_binary(const bitset<32>& num1, const bitset<32>& num2) {
    bitset<32> sum;
    bitset<32> shiftedNum2 = num2;
    bitset<32> shiftedNum1 = num1;

    for (int i = 0; i < 32; ++i) {
        if (num1[i] == 1) {
            sum = addBinary(sum, shiftedNum2);
        }
        shiftedNum2 <<= 1;
        // shiftedNum1 >>= 1;
    }
    return sum;
}



bitset<32> decToBin(int dec) {
    return bitset<32>(dec);
}

// Function to convert binary to decimal
int binToDec(const bitset<32>& binary) {
    return static_cast<int>(binary.to_ulong());
}

int main() {
    int n1, n2;
    cout << "Enter the first decimal number: ";
    cin >> n1;

    cout << "Enter the second decimal number: ";
    cin >> n2;

    bitset<32> binaryNum1 = decToBin(n1);
    bitset<32> binaryNum2 = decToBin(n2);
    bitset<32> result;

    result = multiply_binary(binaryNum1, decToBin(abs(n2)));
       
    // Print binary result
    cout << "Binary result: " << result << endl;

    // Convert result back to decimal and print
    int resultDecimal = binToDec(result);
    cout << "Result in decimal: " << resultDecimal << endl;

    return 0;
}

