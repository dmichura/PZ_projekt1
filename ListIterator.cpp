/**
 * @file ListIterator.cpp
 * @brief Implementacja metod klasy ListIterator służącej do iteracji po liście dwukierunkowej.
 * @tparam Type Typ danych przechowywanych w liście.
 * 
 * Plik zawiera implementację metod klasy ListIterator, umożliwiającej przechodzenie
 * po elementach listy dwukierunkowej w obu kierunkach, wypisywanie ich zawartości
 * oraz resetowanie pozycji iteratora.
 */

#ifndef LIST_ITERATOR_CPP
#define LIST_ITERATOR_CPP

#include "ListIterator.h"
#include "ListTwoway.h"

/**
 * @brief Konstruktor klasy ListIterator.
 * 
 * Inicjalizuje iterator, ustawiając wskaźnik bieżącego elementu (`current`)
 * na pierwszy element listy (`head`).
 * 
 * @param list Wskaźnik na listę, po której iterator ma się poruszać.
 */
template<typename Type>
ListIterator<Type>::ListIterator(ListTwoway<Type>* list)
{
    this->list = list;
    current = list->getHead();
}

/**
 * @brief Sprawdza, czy istnieje kolejny element w liście.
 * @return true jeśli istnieje następny element, false w przeciwnym razie.
 */
template<typename Type>
bool ListIterator<Type>::hasNext() const 
{
    return current != nullptr;
}

/**
 * @brief Zwraca wartość bieżącego elementu i przesuwa iterator na następny.
 * @return Wartość aktualnego elementu typu Type.
 * 
 * @note Jeśli iterator jest ustawiony poza końcem listy, metoda zwraca `false`
 * (co w przypadku typów liczbowych może być interpretowane jako `0`).
 */
template<typename Type>
Type ListIterator<Type>::next()
{
    if (current == nullptr) {
        return false;
    }
    Type data = current->data;
    current = current->next;  
    return data;
}

/**
 * @brief Resetuje pozycję iteratora na początek listy.
 */
template<typename Type>
void ListIterator<Type>::reset()
{
    current = list->getHead();
}

/**
 * @brief Wypisuje wszystkie elementy listy w kolejności od początku do końca.
 * 
 * Używa klasy Logger do wypisywania danych w konsoli lub pliku logu.
 */
template<typename Type>
void ListIterator<Type>::printAll() const {
    Item<Type>* currentItem = list->getHead();
    Logger::getInstance()->log("{ ");
    while (currentItem) {
        Logger::getInstance()->log(to_string(currentItem->data) + " ");
        currentItem = currentItem->next;
    }
    Logger::getInstance()->log("}\n");
}

/**
 * @brief Wypisuje wszystkie elementy listy w kolejności od końca do początku.
 * 
 * Używa klasy Logger do wypisywania danych w konsoli lub pliku logu.
 */
template<typename Type>
void ListIterator<Type>::printAllReverse() const {
    Item<Type>* current = list->getTail();
    
    Logger::getInstance()->log("{ ");
    while (current != nullptr) {
        Logger::getInstance()->log(to_string(current->data) + " ");
        current = current->prev;
    }
    Logger::getInstance()->log("}\n");
}

#endif // LIST_ITERATOR_CPP
