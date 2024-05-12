#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    std::ofstream outputFile("input.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < 200000; ++i) {
        int randomNum = rand() % 1000000 + 1;
        outputFile << randomNum << "\n";
    }

    outputFile.close();
    return 0;
}
