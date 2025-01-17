#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <string>
#include <iostream>
#include <iomanip>

class DataPoint {
private:
    std::string datetime;
    double selfConsumption;
    double exportEnergy;
    double importEnergy;
    double consumption;
    double production;

public:
    DataPoint(const std::string& datetime, double selfConsumption, double exportEnergy,
        double importEnergy, double consumption, double production)
        : datetime(datetime), selfConsumption(selfConsumption), exportEnergy(exportEnergy),
        importEnergy(importEnergy), consumption(consumption), production(production) {
    }

    std::string getDatetime() const {
        return datetime;
    }

    double getSelfConsumption() const {
        return selfConsumption;
    }

    double getExportEnergy() const {
        return exportEnergy;
    }

    double getImportEnergy() const {
        return importEnergy;
    }

    double getConsumption() const {
        return consumption;
    }

    double getProduction() const {
        return production;
    }

    void print() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Datetime: " << datetime << ", Self-Consumption: " << selfConsumption
            << " W, Export: " << exportEnergy << " W, Import: " << importEnergy
            << " W, Consumption: " << consumption << " W, Production: " << production << " W\n";
    }
};

#endif // DATAPOINT_H