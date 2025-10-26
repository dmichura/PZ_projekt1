/**
 * @file ListTwowayFactory.h
 * @brief Definicja klasy szablonowej ListTwowayFactory — fabryka tworząca obiekty ListTwoway.
 * 
 * Klasa ListTwowayFactory umożliwia wygodne tworzenie nowych instancji listy dwukierunkowej
 * bez bezpośredniego wywoływania konstruktora.
 * 
 * @tparam Type Typ danych przechowywanych w liście.
 * @author dmichura
 * @date 2025-10-25
 */

#ifndef LIST_TWOWAY_FACTORY_H
#define LIST_TWOWAY_FACTORY_H

#include "ListTwoway.cpp"

/**
 * @class ListTwowayFactory
 * @brief Klasa szablonowa implementująca wzorzec fabryki dla listy dwukierunkowej.
 * 
 * Zawiera statyczną metodę `createList()`, która tworzy i zwraca wskaźnik
 * na nową instancję klasy ListTwoway<Type>.
 *
 * @tparam Type Typ danych przechowywanych w liście.
 */
template<typename Type>
class ListTwowayFactory {
public:
    /**
     * @brief Tworzy nową instancję listy dwukierunkowej.
     * @return Wskaźnik na nowo utworzoną listę ListTwoway<Type>.
     */
    static ListTwoway<Type>* createList() {
        return new ListTwoway<Type>();
    }
};

#endif // LIST_TWOWAY_FACTORY_H
