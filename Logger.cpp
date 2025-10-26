/**
 * @file Logger.cpp
 * @brief Implementacja klasy Logger — prosty singleton do logowania wiadomości.
 * 
 * Klasa Logger umożliwia wypisywanie komunikatów w konsoli lub pliku logu.
 * W projekcie służy do wypisywania elementów listy oraz informacji diagnostycznych.
 * 
 * @author 
 * @date 2025-10-25
 */

#ifndef LOGGER_CPP
#define LOGGER_CPP

#include "Logger.h"

/** Inicjalizacja wskaźnika singletona */
Logger* Logger::instance = nullptr;

/**
 * @brief Konstruktor klasy Logger.
 * 
 * Prywatny, aby wymusić użycie singletona.
 */
Logger::Logger() {
}

/**
 * @brief Zwraca wskaźnik na jedyną instancję Loggera.
 * 
 * Jeśli instancja nie istnieje, tworzy ją.
 * @return Wskaźnik na singleton Logger.
 */
Logger* Logger::getInstance() {
    if (instance == nullptr)
        instance = new Logger();
    return instance;
}

/**
 * @brief Wypisuje komunikat.
 * @param msg Wiadomość do wypisania.
 */
void Logger::log(string msg) {
    cout << msg;
}

#endif // LOGGER_CPP
