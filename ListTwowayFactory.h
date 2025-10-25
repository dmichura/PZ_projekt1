#ifndef LIST_TWOWAY_FACTORY_H
#define LIST_TWOWAY_FACTORY_H

#include "ListTwoway.h"

template<typename Type>
class ListTwowayFactory {
    public:
        static ListTwoway<Type>* createList() {
            return new ListTwoway<Type>();
        }
};

#endif