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
 * Plik nag³ówkowy LineData zawiera deklaracje klasy LineData która umo¿liwia odczytywanie oraz zarz¹dzania danymi zapisanymi w pliku cvs o odpowiednim formatowaniu.
 */

 /**
  * @class LineData
  * @brief  Klasa przechowuj¹ca dane z jednej linii pliku CSV
  *
  * Klasa \c LineData umo¿liwia:
  * - Odczytywanie danych z ró¿nych Ÿróde³.
  * - Wypisywanie odczytanych danych w ró¿noraki sposób.
  * - Zapisywanie obiektu z danymi do pików.
  * - Zwrócenia poszczególnych danych.
  * 
  *  Klasa ta tak¿e przechowuje pobrane dane.
  */
class LineData {
public:
    // Konstruktor przyjmuj¹cy liniê tekstu i rozdzielaj¹cy dane w tej linii na poszczególne pola
    LineData(const string& line);

    // Konstruktor przyjmuj¹cy obiekt ifstream i odczytuj¹cy dane z pliku
    LineData(ifstream& in);

    // Funkcja do wypisania wszystkich danych na standardowe wyjœcie
    void print() const;

    // Funkcja do wypisania tylko wartoœci danych (np. autokonsumpcja, eksport itp.)
    void printData() const;

    // Funkcja, która zwraca dane jako jeden ci¹g tekstowy
    string printString();

    // Funkcja do zapisania obiektu do pliku
    void serialize(ofstream& out) const;

    // Funkcja do odczytania obiektu z pliku
    void deserialize(ifstream& in);

    // Funkcja do zwrócenia daty
    string getDate() const { return date; }

    // Funkcje do zwracania poszczególnych danych z linii
    float getAutokonsumpcja() const { return autokonsumpcja; }
    float getEksport() const { return eksport; }
    float getImport() const { return import; }
    float getPobor() const { return pobor; }
    float getProdukcja() const { return produkcja; }

private:
    // Zmienna przechowuj¹ca datê (np. "2025-01-01")
    string date;

    // Zmienne przechowuj¹ce ró¿ne wartoœci w watttach
    float autokonsumpcja;  // Autokonsumpcja w watach
    float eksport;         // Eksport energii w watach
    float import;          // Import energii w watach
    float pobor;           // Pobór energii w watach
    float produkcja;       // Produkcja energii w watach
};

#endif // LINEDATA_H
