#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Open input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1; 
    }

    // Read the size of the array
    int n;
    inputFile >> n;

    // Read array elements from the file
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        inputFile >> a[i];

    // Close input file
    inputFile.close();

    // Find the two largest elements in O(n)
    int x = a[0], y = a[1];
    for (int i = 2; i < n; i++) {
        if (a[i] > x && a[i] > y) {
            if (x < y)
                x = a[i];
            else
                y = a[i];
        } else if (a[i] > x) {
            x = a[i];
        } else if (a[i] > y) {
            y = a[i];
        }
    }

    // Open output file
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening output file!" << endl;
        return 1;  
    }

   
    outputFile << (x + y);
    
    // Close output file
    outputFile.close();

    return 0;
}
