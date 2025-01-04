#include <iostream>
using namespace std;

int main() {
    int x=100;
    while(x--){
        long long a, b, c;
    cin >> a >> b >> c;

    // Calculate the result
    long long result = (a ^ b) + (b ^ c) + (a ^ c);

    // Output the result
    cout << result << endl;}

    return 0;
}
