#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    int inFile, outFile;
    char ch;
    char inputFile[50], outputFile[50];
    char password[20];
    int passLen, i = 0;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    cout << "Enter password (at least 4-5 numbers): ";
    cin >> password;

    passLen = strlen(password);

    inFile = open(inputFile, O_RDONLY);
    outFile = open(outputFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (inFile < 0 || outFile < 0) {
        cout << "File error!" << endl;
        return 1;
    }

    while (read(inFile, &ch, 1) > 0) {
        ch = ch ^ password[i % passLen];  // password-based XOR
        write(outFile, &ch, 1);
        i++;
    }

    close(inFile);
    close(outFile);

    cout << "Operation completed successfully!" << endl;
    return 0;
}

