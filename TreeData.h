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
 * Plik nag��wkowy TreeData.h zawiera deklaracje klasy TreeData, kt�ra pozwala przechowywa� odczytane dane w strukturze "drzewa".
 */


/**
  * @class LineData
  * @brief  Klasa przechowuj�ca dane w strukturze drzewa.
  * Klasa przechowuj�ca dane w strukturze drzewa, zorganizowane wed�ug lat, miesi�cy, dni, kwarta��w i godzin dla uproszczenia odczytu i zarz�dzania danymi podczas dzia�ania programu.
  * Klasa \c TreeData umo�liwia:
  * 
  * Klasa ma metody pozwalaj�ce na :
  * - dodawanie danych w odpowiednie miejsca w "Drzewie".
  * - Wypisania zawarto�ci "Drzewa".
  * - Okre�lania zale�no�ci mi�dzy konkretnymi zestawami danych
  */
class TreeData {
public:
    /// Struktura reprezentuj�ca pojedynczy kwarta� (godzina, minuta) w danym dniu
    struct QuarterNode {
        int quarter;  // Numer kwarta�u (0-3)
        int hour;     // Godzina
        int minute;   // Minuta
        std::vector<LineData> data;  // Zbi�r danych (LineData) dla tego kwarta�u
    };

    /// Struktura reprezentuj�ca dzie� w roku, z map� kwarta��w
    struct DayNode {
        int day;  // Numer dnia w miesi�cu
        std::map<int, QuarterNode> quarters;  // Kwarta�y w danym dniu
    };

    /// Struktura reprezentuj�ca miesi�c w roku, z map� dni
    struct MonthNode {
        int month;  // Numer miesi�ca (1-12)
        std::map<int, DayNode> days;  // Dni w danym miesi�cu
    };

    /// Struktura reprezentuj�ca rok, z map� miesi�cy
    struct YearNode {
        int year;  // Numer roku
        std::map<int, MonthNode> months;  // Miesi�ce w danym roku
    };

    /// Metoda dodaj�ca dane (LineData) do odpowiednich w�z��w drzewa na podstawie daty i godziny
    void addData(const LineData& lineData);

    /// Metoda do wypisania wszystkich danych w drzewie na standardowe wyj�cie
    void print() const;

    /// Metoda zwracaj�ca dane z okre�lonego przedzia�u czasowego
    std::vector<LineData> getDataBetweenDates(const std::string& startDate, const std::string& endDate) const;

    /// Metoda do obliczenia sum dla r�nych kategorii (autokonsumpcja, eksport, itp.) w zadanym przedziale czasowym
    void calculateSumsBetweenDates(const std::string& startDate, const std::string& endDate,
        float& autokonsumpcjaSum, float& eksportSum, float& importSum,
        float& poborSum, float& produkcjaSum) const;

    /// Metoda do obliczenia �rednich warto�ci dla r�nych kategorii w zadanym przedziale czasowym
    void calculateAveragesBetweenDates(const std::string& startDate, const std::string& endDate,
        float& autokonsumpcjaAvg, float& eksportAvg, float& importAvg,
        float& poborAvg, float& produkcjaAvg) const;

    /// Metoda por�wnuj�ca dane w dw�ch r�nych przedzia�ach czasowych i obliczaj�ca r�nice
    void compareDataBetweenDates(const std::string& startDate1, const std::string& endDate1,
        const std::string& startDate2, const std::string& endDate2,
        float& autokonsumpcjaDiff, float& eksportDiff, float& importDiff,
        float& poborDiff, float& produkcjaDiff) const;

    /// Metoda wyszukuj�ca rekordy w okre�lonym przedziale czasowym, kt�re maj� warto�� zbli�on� do zadanej (z tolerancj�)
    std::vector<LineData> searchRecordsWithTolerance(const std::string& startDate, const std::string& endDate,
        float value, float tolerance) const;

private:
    /// G��wna struktura przechowuj�ca dane: mapowanie lat na odpowiednie w�z�y (miesi�ce -> dni -> kwarta�y)
    std::map<int, YearNode> years;
};

#endif // TREEDATA_H
