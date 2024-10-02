#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;

void initializeMatrix(int matrix[][MAX_SIZE], int size) {
    cout << "Enter elements for int matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

void initializeMatrix(double matrix[][MAX_SIZE], int size) {
    cout << "Enter elements for double matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

void initializeMatrix(char matrix[][MAX_SIZE], int size) {
    cout << "Enter elements for char matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrix(double matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrix(char matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findMinMaxDiagonal(int matrix[][MAX_SIZE], int size) {
    int minElement = matrix[0][0];
    int maxElement = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minElement) minElement = matrix[i][i];
        if (matrix[i][i] > maxElement) maxElement = matrix[i][i];
    }
    cout << "Min on diagonal: " << minElement << endl;
    cout << "Max on diagonal: " << maxElement << endl;
}

void findMinMaxDiagonal(double matrix[][MAX_SIZE], int size) {
    double minElement = matrix[0][0];
    double maxElement = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minElement) minElement = matrix[i][i];
        if (matrix[i][i] > maxElement) maxElement = matrix[i][i];
    }
    cout << "Min on diagonal: " << minElement << endl;
    cout << "Max on diagonal: " << maxElement << endl;
}

void findMinMaxDiagonal(char matrix[][MAX_SIZE], int size) {
    char minElement = matrix[0][0];
    char maxElement = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minElement) minElement = matrix[i][i];
        if (matrix[i][i] > maxElement) maxElement = matrix[i][i];
    }
    cout << "Min on diagonal: " << minElement << endl;
    cout << "Max on diagonal: " << maxElement << endl;
}

void sortRows(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        sort(matrix[i], matrix[i] + size);
    }
}

void sortRows(double matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        sort(matrix[i], matrix[i] + size);
    }
}

void sortRows(char matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        sort(matrix[i], matrix[i] + size);
    }
}

int main() {
    int size;

    cout << "Enter matrix size: ";
    cin >> size;
    int intMatrix[MAX_SIZE][MAX_SIZE];
    initializeMatrix(intMatrix, size);
    printMatrix(intMatrix, size);
    findMinMaxDiagonal(intMatrix, size);
    sortRows(intMatrix, size);
    printMatrix(intMatrix, size);

    return 0;
}


//task2
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    cout << "Enter two integers(separated by a space): ";
    cin >> num1 >> num2;

    cout << "gcd of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;

    return 0;
}

//task3
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void checkGuess(const string& secret, const string& guess, int& bulls, int& cows, int position = 0) {
    if (position == 4) return;

    if (guess[position] == secret[position]) {
        bulls++;
    }
    else if (secret.find(guess[position]) != string::npos) {
        cows++;
    }

    checkGuess(secret, guess, bulls, cows, position + 1);
}

string generateSecretNumber() {
    string secret;
    srand(time(0));
    while (secret.length() < 4) {
        char digit = '0' + rand() % 10;
        if (secret.find(digit) == string::npos) {
            secret += digit;
        }
    }
    return secret;
}

void playGame(const string& secret, int attempts = 0) {
    string guess;
    int bulls = 0, cows = 0;

    cout << "Enter your 4-digit guess: ";
    cin >> guess;

    if (guess.length() != 4) {
        cout << "Enter a valid 4-digit num." << endl;
        playGame(secret, attempts);
        return;
    }

    checkGuess(secret, guess, bulls, cows);

    attempts++;

    if (bulls == 4) {
        cout << "Congratulations. U guessed the num in " << attempts << " attempts." << endl;
        return;
    }
    else {
        cout << "Bulls: " << bulls << ", Cows: " << cows << endl;
        playGame(secret, attempts);
    }
}

int main() {
    string secret = generateSecretNumber();
    cout << "Welcome to bulls and cows game!" << endl;
    playGame(secret);
    return 0;
}
