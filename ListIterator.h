/**
 * @file ListIterator.h
 * @brief Definicja klasy szablonowej iterującej po elementach listy dwukierunkowej.
 * @tparam Type Typ danych przechowywanych w liście.
 * @author dmichura
 * @date 2025-10-25
 * Klasa ListIterator pozwala na przechodzenie po liście w obu kierunkach,
 * wypisywanie elementów oraz resetowanie pozycji iteratora.
 * Współpracuje z klasą ListTwoway.
 */

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "ListTwoway.h"

/**
 * @class ListIterator
 * @brief Klasa implementująca iterator dla listy dwukierunkowej.
 * 
 * Klasa umożliwia iterację po elementach listy w przód i w tył.
 * Wykorzystuje wskaźnik do listy (`ListTwoway<Type>`) oraz bieżący element (`Item<Type>*`).
 * 
 * @tparam Type Typ danych przechowywanych w liście.
 */
template<typename Type>
class ListIterator {
private:
    Item<Type>* current;        ///< Wskaźnik na aktualny element listy.
    ListTwoway<Type>* list;     ///< Wskaźnik na listę, po której iterator się porusza.

public:
    /**
     * @brief Konstruktor klasy ListIterator.
     * @param list Wskaźnik na listę, po której iterator ma się poruszać.
     */
    ListIterator(ListTwoway<Type>* list);

    /**
     * @brief Sprawdza, czy istnieje następny element w liście.
     * @return true jeśli istnieje następny element, false w przeciwnym razie.
     */
    bool hasNext() const;

    /**
     * @brief Zwraca wartość następnego elementu i przesuwa iterator.
     * @return Wartość elementu typu Type.
     */
    Type next();

    /**
     * @brief Resetuje iterator do początku listy.
     */
    void reset();

    /**
     * @brief Wypisuje wszystkie elementy listy w kolejności od początku do końca.
     */
    void printAll() const;

    /**
     * @brief Wypisuje wszystkie elementy listy w kolejności od końca do początku.
     */
    void printAllReverse() const;
};

#endif // LIST_ITERATOR_H
