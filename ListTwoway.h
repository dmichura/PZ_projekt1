#ifndef LIST_TWOWAY_H
#define LIST_TWOWAY_H

#include "Item.h"

template <typename Type>
class ListTwoway {
    private:
        Item<Type>* head;
        Item<Type>* tail;
    public:
        ListTwoway();
        ~ListTwoway();

        void unshift(Type data);
        void push(Type data);
        void insertAt(int index, Type data);
        void shift();
        void pop();
        void removeAt(int index);
        void clear();
};

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
}

#endif