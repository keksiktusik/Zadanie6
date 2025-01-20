#ifndef LINEDATA_H
#define LINEDATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @file LineDate.h
 * @brief Deklaracja klasy \c LineData.
 *
 * Plik nag��wkowy LineData zawiera deklaracje klasy LineData kt�ra umo�liwia odczytywanie oraz zarz�dzania danymi zapisanymi w pliku cvs o odpowiednim formatowaniu.
 */

 /**
  * @class LineData
  * @brief  Klasa przechowuj�ca dane z jednej linii pliku CSV
  *
  * Klasa \c LineData umo�liwia:
  * - Odczytywanie danych z r�nych �r�de�.
  * - Wypisywanie odczytanych danych w r�noraki spos�b.
  * - Zapisywanie obiektu z danymi do pik�w.
  * - Zwr�cenia poszczeg�lnych danych.
  * 
  *  Klasa ta tak�e przechowuje pobrane dane.
  */
class LineData {
public:
    /// Konstruktor przyjmuj�cy lini� tekstu i rozdzielaj�cy dane w tej linii na poszczeg�lne pola
    LineData(const string& line);

    /// Konstruktor przyjmuj�cy obiekt ifstream i odczytuj�cy dane z pliku
    LineData(ifstream& in);

    /// Metoda do wypisania wszystkich danych na standardowe wyj�cie
    void print() const;

    /// Metoda do wypisania tylko warto�ci danych (np. autokonsumpcja, eksport itp.)
    void printData() const;

    /// Metoda, kt�ra zwraca dane jako jeden ci�g tekstowy
    string printString();

    /// Metoda do zapisania obiektu do pliku
    void serialize(ofstream& out) const;

    /// Metoda do odczytania obiektu z pliku
    void deserialize(ifstream& in);

    /// Metoda do zwr�cenia daty
    string getDate() const { return date; }

    /// Funkcje do zwracania poszczeg�lnych danych z linii
    float getAutokonsumpcja() const { return autokonsumpcja; }
    float getEksport() const { return eksport; }
    float getImport() const { return import; }
    float getPobor() const { return pobor; }
    float getProdukcja() const { return produkcja; }

private:
    /// Zmienna przechowuj�ca dat� (np. "2025-01-01")
    string date;

    /// Autokonsumpcja w watach
    float autokonsumpcja; 
    /// Eksport energii w watach
    float eksport;         
    /// Import energii w watach
    float import;          
    /// Pob�r energii w watach
    float pobor;           
    /// Produkcja energii w watach
    float produkcja;       
};

#endif // LINEDATA_H
