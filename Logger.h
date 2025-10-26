/**
 * @file Logger.h
 * @brief Definicja klasy Logger — prosty singleton do logowania wiadomości.
 * 
 * Klasa Logger umożliwia wypisywanie komunikatów w konsoli lub pliku logu.
 * Singleton zapewnia jedną globalną instancję klasy w całym projekcie.
 * 
 * @author dmichura
 * @date 2025-10-25
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Logger
 * @brief Singleton do logowania wiadomości w projekcie.
 * 
 * Umożliwia wypisywanie tekstu w konsoli lub pliku logu. 
 * Konstruktor prywatny wymusza użycie metody statycznej getInstance().
 */
class Logger {
private:
    static Logger* instance;   ///< Wskaźnik na jedyną instancję singletona.

    /// Prywatny konstruktor, aby uniemożliwić tworzenie dodatkowych instancji.
    Logger();
    
    /// Usunięcie konstruktora kopiującego.
    Logger(const Logger&) = delete;

    /// Usunięcie operatora przypisania.
    Logger& operator=(const Logger&) = delete;

public:
    /**
     * @brief Zwraca wskaźnik na jedyną instancję Loggera.
     * 
     * Jeśli instancja nie istnieje, tworzy ją.
     * @return Wskaźnik na singleton Logger.
     */
    static Logger* getInstance();

    /**
     * @brief Wypisuje komunikat.
     * @param msg Wiadomość do wypisania.
     */
    void log(string msg);
};

#endif // LOGGER_H
