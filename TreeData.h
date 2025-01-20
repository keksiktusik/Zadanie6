#ifndef TREEDATA_H
#define TREEDATA_H

#include <map>
#include <string>
#include <vector>
#include "LineData.h"

/**
 * @file TreeData.h
 * @brief Deklaracja klasy \c TreeData.
 *
 * Plik nag³ówkowy TreeData.h zawiera deklaracje klasy TreeData, która pozwala przechowywaæ odczytane dane w strukturze "drzewa".
 */


/**
  * @class LineData
  * @brief  Klasa przechowuj¹ca dane w strukturze drzewa.
  * Klasa przechowuj¹ca dane w strukturze drzewa, zorganizowane wed³ug lat, miesiêcy, dni, kwarta³ów i godzin dla uproszczenia odczytu i zarz¹dzania danymi podczas dzia³ania programu.
  * Klasa \c TreeData umo¿liwia:
  * 
  * Klasa ma metody pozwalaj¹ce na :
  * - dodawanie danych w odpowiednie miejsca w "Drzewie".
  * - Wypisania zawartoœci "Drzewa".
  * - Okreœlania zale¿noœci miêdzy konkretnymi zestawami danych
  */
class TreeData {
public:
    /// Struktura reprezentuj¹ca pojedynczy kwarta³ (godzina, minuta) w danym dniu
    struct QuarterNode {
        int quarter;  // Numer kwarta³u (0-3)
        int hour;     // Godzina
        int minute;   // Minuta
        std::vector<LineData> data;  // Zbiór danych (LineData) dla tego kwarta³u
    };

    /// Struktura reprezentuj¹ca dzieñ w roku, z map¹ kwarta³ów
    struct DayNode {
        int day;  // Numer dnia w miesi¹cu
        std::map<int, QuarterNode> quarters;  // Kwarta³y w danym dniu
    };

    /// Struktura reprezentuj¹ca miesi¹c w roku, z map¹ dni
    struct MonthNode {
        int month;  // Numer miesi¹ca (1-12)
        std::map<int, DayNode> days;  // Dni w danym miesi¹cu
    };

    /// Struktura reprezentuj¹ca rok, z map¹ miesiêcy
    struct YearNode {
        int year;  // Numer roku
        std::map<int, MonthNode> months;  // Miesi¹ce w danym roku
    };

    /// Metoda dodaj¹ca dane (LineData) do odpowiednich wêz³ów drzewa na podstawie daty i godziny
    void addData(const LineData& lineData);

    /// Metoda do wypisania wszystkich danych w drzewie na standardowe wyjœcie
    void print() const;

    /// Metoda zwracaj¹ca dane z okreœlonego przedzia³u czasowego
    std::vector<LineData> getDataBetweenDates(const std::string& startDate, const std::string& endDate) const;

    /// Metoda do obliczenia sum dla ró¿nych kategorii (autokonsumpcja, eksport, itp.) w zadanym przedziale czasowym
    void calculateSumsBetweenDates(const std::string& startDate, const std::string& endDate,
        float& autokonsumpcjaSum, float& eksportSum, float& importSum,
        float& poborSum, float& produkcjaSum) const;

    /// Metoda do obliczenia œrednich wartoœci dla ró¿nych kategorii w zadanym przedziale czasowym
    void calculateAveragesBetweenDates(const std::string& startDate, const std::string& endDate,
        float& autokonsumpcjaAvg, float& eksportAvg, float& importAvg,
        float& poborAvg, float& produkcjaAvg) const;

    /// Metoda porównuj¹ca dane w dwóch ró¿nych przedzia³ach czasowych i obliczaj¹ca ró¿nice
    void compareDataBetweenDates(const std::string& startDate1, const std::string& endDate1,
        const std::string& startDate2, const std::string& endDate2,
        float& autokonsumpcjaDiff, float& eksportDiff, float& importDiff,
        float& poborDiff, float& produkcjaDiff) const;

    /// Metoda wyszukuj¹ca rekordy w okreœlonym przedziale czasowym, które maj¹ wartoœæ zbli¿on¹ do zadanej (z tolerancj¹)
    std::vector<LineData> searchRecordsWithTolerance(const std::string& startDate, const std::string& endDate,
        float value, float tolerance) const;

private:
    /// G³ówna struktura przechowuj¹ca dane: mapowanie lat na odpowiednie wêz³y (miesi¹ce -> dni -> kwarta³y)
    std::map<int, YearNode> years;
};

#endif // TREEDATA_H
