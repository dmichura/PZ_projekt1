/**
 * @file ListTwoway.cpp
 * @brief Implementacja klasy ListTwoway — listy dwukierunkowej w C++.
 * @tparam Type Typ danych przechowywanych w liście.
 * 
 * Plik zawiera implementację wszystkich metod klasy ListTwoway, 
 * umożliwiającej dodawanie, usuwanie i przeszukiwanie elementów listy 
 * w obu kierunkach. Klasa wykorzystuje strukturę Item oraz klasę Logger.
 * 
 * @author dmichura
 * @date 2025-10-25
 */

#ifndef LIST_TWOWAY_CPP
#define LIST_TWOWAY_CPP

#include "Item.h"
#include "ListTwoway.h"

/**
 * @brief Zwraca liczbę elementów w liście.
 * @return Liczba elementów listy.
 */
template<typename Type>
int ListTwoway<Type>::getSize()
{
    return size;
}

/**
 * @brief Zwraca wskaźnik na pierwszy element listy.
 * @return Wskaźnik na głowę listy (`head`).
 */
template<typename Type>
Item<Type>* ListTwoway<Type>::getHead()
{
    return head;
}

/**
 * @brief Zwraca wskaźnik na ostatni element listy.
 * @return Wskaźnik na ogon listy (`tail`).
 */
template<typename Type>
Item<Type>* ListTwoway<Type>::getTail()
{
    return tail;
}

/**
 * @brief Konstruktor domyślny klasy ListTwoway.
 * 
 * Tworzy pustą listę, ustawiając wskaźniki `head` i `tail` na `nullptr`.
 */
template<typename Type>
ListTwoway<Type>::ListTwoway()
{
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Destruktor klasy ListTwoway.
 * 
 * Obecnie nie usuwa automatycznie elementów (należy wywołać clear()).
 */
template<typename Type>
ListTwoway<Type>::~ListTwoway()
{
    // Można dodać clear(), jeśli chcesz automatycznie usuwać elementy.
}

/**
 * @brief Dodaje nowy element na początek listy.
 * @param data Wartość, którą ma przechowywać nowy element.
 */
template<typename Type>
void ListTwoway<Type>::unshift(Type data)
{
    Item<Type>* newItem = new Item<Type>(data);

    if(!head)
    {
        head = tail = newItem;
    }
    else
    {
        newItem->next = head;
        head->prev = newItem;
        head = newItem;
    }
    size++;
}

/**
 * @brief Dodaje nowy element na koniec listy.
 * @param data Wartość, którą ma przechowywać nowy element.
 */
template<typename Type>
void ListTwoway<Type>::push(Type data)
{
    Item<Type>* newItem = new Item<Type>(data);

    if(!head)
    {
        head = tail = newItem;
    }
    else
    {
        tail->next = newItem;
        newItem->prev = tail;
        tail = newItem;
    }
    size++;
}

/**
 * @brief Wstawia nowy element w określone miejsce w liście.
 * @param index Indeks, pod który ma zostać wstawiony element.
 * @param data Wartość elementu do wstawienia.
 */
template<typename Type>
void ListTwoway<Type>::insertAt(int index, Type data)
{
    if (index < 0 || index > size) {
        Logger::getInstance()->log("Index jest niepoprawny!\nIndex musi byc >= 0 i nie moze byc > size!\n");
        return;
    }

    if (index == 0) {
        unshift(data);
        return;
    }

    if (index == size) {
        push(data);
        return;
    }

    Item<Type>* newItem = new Item<Type>(data);
    Item<Type>* current = head;

    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    newItem->next = current->next;
    if (current->next) {
        current->next->prev = newItem;
    }

    current->next = newItem;
    newItem->prev = current;

    size++;
}

/**
 * @brief Usuwa element z określonego indeksu.
 * @param index Indeks elementu do usunięcia.
 */
template<typename Type>
void ListTwoway<Type>::removeAt(int index)
{
    if (index < 0 || index >= size) {
        Logger::getInstance()->log("Nieprawidłowy indeks!\n");
        return;
    }

    if (index == 0) {
        shift();
        return;
    }

    if (index == size - 1) {
        pop();
        return;
    }

    Item<Type>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->prev->next = current->next;
    if (current->next) {
        current->next->prev = current->prev;
    }

    delete current;
    size--;
}

/**
 * @brief Usuwa pierwszy element listy.
 */
template<typename Type>
void ListTwoway<Type>::shift()
{
    if (!head) {
        Logger::getInstance()->log("Lista jest pusta!\n");
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Item<Type>* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    size--;
}

/**
 * @brief Usuwa ostatni element listy.
 */
template<typename Type>
void ListTwoway<Type>::pop()
{
    if (!tail) {
        Logger::getInstance()->log("Lista jest pusta!\n");
        return;
    }

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    }
    else {
        Item<Type>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    size--;
}

/**
 * @brief Usuwa wszystkie elementy z listy i resetuje jej rozmiar.
 */
template<typename Type>
void ListTwoway<Type>::clear()
{
    Item<Type>* current = head;
    while (current != nullptr) {
        Item<Type>* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

#endif // LIST_TWOWAY_CPP
