#ifndef LIST_TWOWAY_H
#define LIST_TWOWAY_H

#include "Item.h"

template <typename Type>
class ListTwoway {
    private:
        Item<Type>* head;
        Item<Type>* tail;
        int size=0;
    public:
        ListTwoway();
        ~ListTwoway();

        void unshift(Type data);
        void push(Type data);
        void insertAt(int index, Type data);
        void removeAt(int index);
        void shift();
        void pop();
        void clear();

        int getSize();
        Item<Type>* getHead();
        Item<Type>* getTail();
};


template<typename Type>
int ListTwoway<Type>::getSize()
{
    return size;
}

template<typename Type>
Item<Type>* ListTwoway<Type>::getHead()
{
    return head;
}
template<typename Type>
Item<Type>* ListTwoway<Type>::getTail()
{
    return tail;
}

template<typename Type>
ListTwoway<Type>::ListTwoway()
{
    head = nullptr;
    tail = nullptr;
}

template<typename Type>
ListTwoway<Type>::~ListTwoway()
{
    
}

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

template<typename Type>
void ListTwoway<Type>::insertAt(int index, Type data)
{
    if (index < 0 || index > size) {
        cout << "Index jest niepoprawny!" << endl << "Index musi byc >= 0 i nie moze byc > size!" << endl;
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

template<typename Type>
void ListTwoway<Type>::removeAt(int index)
{
    if (index < 0 || index >= size) {
        cout << "Nieprawidłowy indeks!" << endl;
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

template<typename Type>
void ListTwoway<Type>::shift()
{

    if (!head) {
        cout << "Lista jest pusta!" << endl;
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

template<typename Type>
void ListTwoway<Type>::pop()
{
    if (!tail) {
        cout << "Lista jest pusta!" << endl;
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



#endif