#ifndef TREE_H
#define TREE_H

#include "DataPoint.h"
#include <map>
#include <vector>
#include <memory>

class Tree {
private:
    struct QuarterNode {
        std::vector<std::shared_ptr<DataPoint>> dataPoints;
    };

    struct DayNode {
        std::map<int, QuarterNode> quarters;
    };

    struct MonthNode {
        std::map<int, DayNode> days;
    };

    struct YearNode {
        std::map<int, MonthNode> months;
    };

    std::map<int, YearNode> years;

public:
    void insertDataPoint(const std::shared_ptr<DataPoint>& dataPoint) {
        const std::string& datetime = dataPoint->getDatetime();
        int year = std::stoi(datetime.substr(0, 4));
        int month = std::stoi(datetime.substr(5, 2));
        int day = std::stoi(datetime.substr(8, 2));
        int hour = std::stoi(datetime.substr(11, 2));

        int quarter = hour / 6;

        years[year].months[month].days[day].quarters[quarter].dataPoints.push_back(dataPoint);
    }

    double calculateSum(const std::string& start, const std::string& end, char type) const {
        double sum = 0.0;
        for (const auto& [year, yearNode] : years) {
            for (const auto& [month, monthNode] : yearNode.months) {
                for (const auto& [day, dayNode] : monthNode.days) {
                    for (const auto& [quarter, quarterNode] : dayNode.quarters) {
                        for (const auto& dataPoint : quarterNode.dataPoints) {
                            if (dataPoint->getDatetime() >= start && dataPoint->getDatetime() <= end) {
                                if (type == 'A') sum += dataPoint->getSelfConsumption();
                                if (type == 'E') sum += dataPoint->getExportEnergy();
                                if (type == 'I') sum += dataPoint->getImportEnergy();
                                if (type == 'C') sum += dataPoint->getConsumption();
                                if (type == 'P') sum += dataPoint->getProduction();
                            }
                        }
                    }
                }
            }
        }
        return sum;
    }
};

#endif // TREE_H
