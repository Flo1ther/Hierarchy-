#include <iostream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <string>
class FileHandler {
public:
    virtual void Display(const char* path) const {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << path << std::endl;
            return;
        }

        std::cout << "File content:" << std::endl;
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    }
};

class ASCIIFileHandler : public FileHandler {
public:
    void Display(const char* path) const override {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << path << std::endl;
            return;
        }

        std::cout << "ASCII content:" << std::endl;
        int ch;
        while ((ch = file.get()) != EOF) {
            std::cout << std::setw(3) << ch << " ";
        }

        file.close();
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* path) const override {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << path << std::endl;
            return;
        }

        std::cout << "Binary content:" << std::endl;
        char ch;
        while (file.get(ch)) {
            std::cout << std::bitset<8>(ch) << " ";
        }

        file.close();
    }
};

int main() {
    const char* filePath = "example.txt";

    FileHandler baseHandler;
    baseHandler.Display(filePath);

    ASCIIFileHandler asciiHandler;
    asciiHandler.Display(filePath);

    BinaryFileHandler binaryHandler;
    binaryHandler.Display(filePath);

    return 0;
}
