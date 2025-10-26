/**
 * @file main.cpp
 * @brief Przykładowe użycie listy dwukierunkowej z klas Logger i ListIterator.
 *
 * Plik demonstruje:
 * - tworzenie listy dwukierunkowej za pomocą ListTwowayFactory,
 * - dodawanie i usuwanie elementów (push, unshift, insertAt, pop, shift, clear),
 * - iterację po liście przy pomocy ListIterator,
 * - wypisywanie listy w kolejności normalnej i odwrotnej,
 * - logowanie komunikatów przy użyciu singletona Logger.
 *
 * @author dmichura
 * @date 2025-10-25
 */

#include <iostream>
#include "Logger.cpp"
#include "ListIterator.cpp"
#include "ListTwowayFactory.h"

using namespace std;

int main()
{
    Logger::getInstance()->log("\t[projekt_01 - Listy dwukierunkowe]\n");

    ListTwoway<int>* intList = ListTwowayFactory<int>::createList();
    ListIterator<int> it(intList);

    intList->push(1024);
    intList->push(2048);
    intList->push(2048);

    Logger::getInstance()->log("intList[" + to_string(intList->getSize()) + "] = ");
    it.printAll();

    // dodaje element na początek listy
    intList->unshift(512);

    // dodaje element na koniec listy
    intList->push(8192);

    // dodajemy element pod wskazany index (w tym przypadku przedostatni)
    intList->insertAt(intList->getSize() - 1, 4096);

    Logger::getInstance()->log("intList[" + to_string(intList->getSize()) + "] = ");
    it.printAll();

    intList->unshift(256);
    intList->push(16384);

    Logger::getInstance()->log("intList[" + to_string(intList->getSize()) + "] = ");
    it.printAll();

    // usuwamy pierwszy element z listy
    intList->shift();
    // usuwamy ostatni element z listy
    intList->pop();

    Logger::getInstance()->log("intList[" + to_string(intList->getSize()) + "] = ");
    it.printAll();

    // wypisujemy listę w odwrotnej kolejności
    Logger::getInstance()->log("intList[" + to_string(intList->getSize()) + "] = ");
    it.printAllReverse();

    // czyścimy listę
    intList->clear();

    Logger::getInstance()->log("intList[" + to_string(intList->getSize()) + "] = ");
    it.printAll();

    delete intList;
    return 0;
}
