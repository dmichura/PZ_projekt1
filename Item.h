/**
 * @file Item.h
 * @brief Definicja klasy szablonowej reprezentującej pojedynczy element (węzeł) listy dwukierunkowej.
 * @tparam Type Typ danych przechowywanych w elemencie listy.
 * @author dmichura
 */

#ifndef ITEM_H
#define ITEM_H

/**
 * @class Item
 * @brief Klasa szablonowa reprezentująca węzeł listy dwukierunkowej.
 *
 * Klasa przechowuje wartość typu `Type` oraz wskaźniki do poprzedniego i następnego elementu.
 * Używana wewnętrznie w implementacji listy dwukierunkowej.
 *
 * @tparam Type Typ danych przechowywanych w elemencie listy.
 */
template <typename Type>
class Item {
public:
    Type data;     ///< Dane przechowywane w elemencie.
    Item* prev;    ///< Wskaźnik na poprzedni element listy.
    Item* next;    ///< Wskaźnik na następny element listy.

    /**
     * @brief Konstruktor inicjalizujący element listy.
     * @param data Wartość, którą ma przechowywać element.
     *
     * Tworzy nowy węzeł listy z danymi `data`. Początkowo wskaźniki `prev` i `next`
     * ustawione są na `nullptr`.
     */
    Item(Type data) : data(data), prev(nullptr), next(nullptr) {}
};

#endif // ITEM_H
