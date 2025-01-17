#include "Tree.h"
#include "DataPoint.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

void logMessage(const std::string& filename, const std::string& message) {
    std::ofstream logFile(filename, std::ios::app);
    if (logFile.is_open()) {
        logFile << message << "\n";
        logFile.close();
    }
}

void loadDataFromCSV(const std::string& filePath, Tree& tree) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << "\n";
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header

    int valid = 0, invalid = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string datetime;
        double selfConsumption, exportEnergy, importEnergy, consumption, production;

        if (std::getline(ss, datetime, ',') &&
            ss >> selfConsumption && ss.ignore() &&
            ss >> exportEnergy && ss.ignore() &&
            ss >> importEnergy && ss.ignore() &&
            ss >> consumption && ss.ignore() &&
            ss >> production) {

            auto dataPoint = std::make_shared<DataPoint>(datetime, selfConsumption, exportEnergy,
                importEnergy, consumption, production);
            tree.insertDataPoint(dataPoint);
            valid++;
        }
        else {
            invalid++;
            logMessage("log_error.txt", "Invalid line: " + line);
        }
    }

    std::cout << "Valid records: " << valid << "\nInvalid records: " << invalid << "\n";
    file.close();
}

void menu(Tree& tree) {
    int choice;
    do {
        std::cout << "1. Load CSV\n2. Calculate Sum\n3. Exit\nChoose: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string filename;
            std::cout << "Enter file name: ";
            std::cin >> filename;
            loadDataFromCSV(filename, tree);
        }
        else if (choice == 2) {
            std::string start, end;
            char type;
            std::cout << "Enter start datetime: ";
            std::cin >> start;
            std::cout << "Enter end datetime: ";
            std::cin >> end;
            std::cout << "Enter type (A - Autoconsumption, E - Export, I - Import, C - Consumption, P - Production): ";
            std::cin >> type;
            double result = tree.calculateSum(start, end, type);
            std::cout << "Result: " << result << " W\n";
        }
    } while (choice != 3);
}

int main() {
    Tree tree;
    menu(tree);
    return 0;
}
