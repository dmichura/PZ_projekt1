/**
 * @file ListTwoway.h
 * @brief Definicja klasy szablonowej ListTwoway — implementacja listy dwukierunkowej w C++.
 * 
 * Klasa ListTwoway umożliwia dodawanie, usuwanie, wstawianie oraz czyszczenie elementów listy.
 * Zawiera wskaźniki do pierwszego i ostatniego elementu listy oraz zmienną przechowującą jej rozmiar.
 * 
 * @tparam Type Typ danych przechowywanych w liście.
 * @author dmichura
 * @date 2025-10-25
 */

#ifndef LIST_TWOWAY_H
#define LIST_TWOWAY_H

#include "Item.h"

/**
 * @class ListTwoway
 * @brief Klasa szablonowa reprezentująca listę dwukierunkową.
 * 
 * Klasa przechowuje elementy typu `Item<Type>` połączone wskaźnikami w obu kierunkach.
 * Umożliwia dodawanie elementów na początek i koniec listy, wstawianie elementów w dowolne miejsce,
 * usuwanie elementów oraz czyszczenie całej listy.
 *
 * @tparam Type Typ danych przechowywanych w liście.
 */
template <typename Type>
class ListTwoway {
private:
    Item<Type>* head;   ///< Wskaźnik na pierwszy element listy.
    Item<Type>* tail;   ///< Wskaźnik na ostatni element listy.
    int size = 0;       ///< Aktualny rozmiar listy (liczba elementów).

public:
    /**
     * @brief Konstruktor domyślny klasy ListTwoway.
     * 
     * Tworzy pustą listę, ustawiając wskaźniki `head` i `tail` na `nullptr`.
     */
    ListTwoway();

    /**
     * @brief Destruktor klasy ListTwoway.
     * 
     * W razie potrzeby może zostać rozszerzony o automatyczne czyszczenie listy.
     */
    ~ListTwoway();

    /**
     * @brief Dodaje nowy element na początek listy.
     * @param data Wartość elementu do dodania.
     */
    void unshift(Type data);

    /**
     * @brief Dodaje nowy element na koniec listy.
     * @param data Wartość elementu do dodania.
     */
    void push(Type data);

    /**
     * @brief Wstawia element w określonym miejscu w liście.
     * @param index Indeks miejsca, w którym element ma zostać wstawiony.
     * @param data Wartość elementu do wstawienia.
     */
    void insertAt(int index, Type data);

    /**
     * @brief Usuwa element z określonego miejsca w liście.
     * @param index Indeks elementu do usunięcia.
     */
    void removeAt(int index);

    /**
     * @brief Usuwa pierwszy element listy.
     */
    void shift();

    /**
     * @brief Usuwa ostatni element listy.
     */
    void pop();

    /**
     * @brief Usuwa wszystkie elementy z listy i resetuje jej rozmiar.
     */
    void clear();

    /**
     * @brief Zwraca aktualną liczbę elementów listy.
     * @return Liczba elementów w liście.
     */
    int getSize();

    /**
     * @brief Zwraca wskaźnik na pierwszy element listy.
     * @return Wskaźnik na głowę listy.
     */
    Item<Type>* getHead();

    /**
     * @brief Zwraca wskaźnik na ostatni element listy.
     * @return Wskaźnik na ogon listy.
     */
    Item<Type>* getTail();
};

#endif // LIST_TWOWAY_H
