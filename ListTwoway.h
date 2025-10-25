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
};


template<typename Type>
int ListTwoway<Type>::getSize()
{
    return size;
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

    cout << "New item" << newItem->data;
}

#endif