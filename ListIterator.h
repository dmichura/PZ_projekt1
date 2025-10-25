#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "ListTwoway.h"

template<typename Type>
class ListIterator {
    private:
        Item<Type>* current;  // Bieżący element w iteracji
        ListTwoway<Type>* list;
    public:
        ListIterator(ListTwoway<Type>* list);
        bool hasNext() const;
        Type next();
        void reset();
        void printAll() const;
        void printAllReverse() const;
};

template<typename Type>
ListIterator<Type>::ListIterator(ListTwoway<Type>* list)
{
    this->list = list;
    current = list->getHead();
}

template<typename Type>
bool ListIterator<Type>::hasNext() const 
{
    return current != nullptr;
}

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

template<typename Type>
void ListIterator<Type>::reset()
{
    current = list->getHead();
}

template<typename Type>
void ListIterator<Type>::printAll() const {
    Item<Type>* currentItem = list->getHead();
    cout << "{ ";
    while (currentItem) {
        cout << currentItem->data << " ";
        currentItem = currentItem->next;
    }
    cout << "}" << endl;
}

template<typename Type>
void ListIterator<Type>::printAllReverse() const {
    Item<Type>* current = list->getTail();
    
    cout << "{ ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << "}" << endl;
}

#endif