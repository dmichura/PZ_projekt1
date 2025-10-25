#ifndef ITEM_H
#define ITEM_H

template <typename Type>
class Item {
    public:
        Type data;
        Item* prev;
        Item* next;

        Item(Type data): data(data), prev(nullptr), next(nullptr) {}

};

#endif