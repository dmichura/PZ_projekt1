# PZ_projekt1

## Opis projektu

Celem projektu jest stworzenie dwukierunkowej listy, której elementy będą przechowywane na stercie. Implementacja ma wykorzystywać wzorce projektowe **Factory** oraz **Iterator**. Program umożliwi dodawanie, usuwanie i wyświetlanie elementów listy, a także przeglądanie jej elementów w obu kierunkach

## Wymagania

### Klasy i ich funkcjonalność

1. **Item** - reprezentuje pojedynczy element listy
    - Właściwości:
        - `data` - dane przechowywane w Item.
        - `next` - wskaźnik do następnego Item'a.
        - `prev` - wskaźnik do poprzedniego Item'a.

1. **ListTwoway** - klasa listy dwukierunkowej
   - **Właściwości:**
     - `head` - wskaźnik do pierwszego **Item** w liście, który zawiera dane oraz wskaźnik na następny element.
     - `tail` - wskaźnik do ostatniego **Item** w liście, który zawiera dane oraz wskaźnik na poprzedni element.
   
   - **Metody:**

     - **`unshift(data)`**  
       - Dodaje element na początek listy. Tworzy nowy **Item** i ustawia go na `head` listy.
       - **Argumenty:** `data` – dane do zapisania w nowym **Item**.
       - **Działanie:** Jeśli lista jest pusta, nowy **Item** staje się zarówno `head`, jak i `tail`. W przeciwnym przypadku nowy **Item** jest ustawiany na początek listy.

     - **`push(data)`**  
       - Dodaje element na koniec listy. Tworzy nowy **Item** i ustawia go na `tail` listy.
       - **Argumenty:** `data` – dane do zapisania w nowym **Item**.
       - **Działanie:** Jeśli lista jest pusta, nowy **Item** staje się zarówno `head`, jak i `tail`. W przeciwnym przypadku nowy **Item** jest dodawany na koniec listy.

     - **`insertAt(index, data)`**  
       - Dodaje element w określonym miejscu w liście na podstawie indeksu. Jeśli indeks jest poza zakresem, nic się nie dzieje.
       - **Argumenty:** 
         - `index` – indeks, pod którym ma zostać dodany nowy **Item**.
         - `data` – dane do zapisania w nowym **Item**.
       - **Działanie:** Jeśli indeks jest 0, dodawany jest element na początek listy. Jeśli indeks jest równy liczbie elementów, dodawany jest element na koniec. W przeciwnym przypadku element jest wstawiany w odpowiednie miejsce w liście.

     - **`shift()`**  
       - Usuwa element z początku listy. Przesuwa wskaźnik `head` na następny **Item**.
       - **Argumenty:** Brak.
       - **Działanie:** Jeśli lista ma tylko jeden **Item**, zarówno `head`, jak i `tail` zostaną ustawione na `nullptr`. W przeciwnym przypadku wskaźnik `head` jest zmieniany na następny **Item**.

     - **`pop()`**  
       - Usuwa element z końca listy. Przesuwa wskaźnik `tail` na poprzedni **Item**.
       - **Argumenty:** Brak.
       - **Działanie:** Jeśli lista ma tylko jeden **Item**, zarówno `head`, jak i `tail` zostaną ustawione na `nullptr`. W przeciwnym przypadku wskaźnik `tail` jest zmieniany na poprzedni **Item**.

     - **`removeAt(index)`**  
       - Usuwa element pod wskazanym indeksem. Jeśli indeks jest poza zakresem, nic się nie dzieje.
       - **Argumenty:**
         - `index` – indeks **Item**u, który ma zostać usunięty.
       - **Działanie:** Usuwa **Item** o podanym indeksie i odpowiednio aktualizuje wskaźniki sąsiednich elementów.

     - **`toArray()`**  
       - Zwraca wszystkie **Item**y listy od `head` do `tail` w postaci tablicy.
       - **Argumenty:** Brak.
       - **Zwraca:** Tablicę z danymi wszystkich **Item**ów listy.
       - **Działanie:** Przechodzi przez listę, zaczynając od `head`, i dodaje dane każdego **Item**u do tablicy.

     - **`reverseToArray()`**  
       - Zwraca wszystkie **Item**y listy od `tail` do `head` w postaci tablicy.
       - **Argumenty:** Brak.
       - **Zwraca:** Tablicę z danymi wszystkich **Item**ów listy w odwrotnej kolejności.
       - **Działanie:** Przechodzi przez listę w odwrotnej kolejności, zaczynając od `tail`, i dodaje dane każdego **Item**u do tablicy.

     - **`next()`**  
       - Zwraca następny **Item** w iteracji po liście.
       - **Argumenty:** Brak.
       - **Zwraca:** Dane następnego **Item**u listy.
       - **Działanie:** Zwraca dane następnego **Item**u w liście i przesuwa wskaźnik na następny **Item**.

     - **`prev()`**  
       - Zwraca poprzedni **Item** w iteracji po liście.
       - **Argumenty:** Brak.
       - **Zwraca:** Dane poprzedniego **Item**u listy.
       - **Działanie:** Zwraca dane poprzedniego **Item**u w liście i przesuwa wskaźnik na poprzedni **Item**.

     - **`clear()`**  
       - Usuwa wszystkie **Item**y listy, ustawiając wskaźniki `head` i `tail` na `nullptr`.
       - **Argumenty:** Brak.
       - **Działanie:** Usuwa wszystkie **Item**y listy i resetuje wskaźniki `head` i `tail` na `nullptr`, co skutkuje opróżnieniem listy.


### Struktura projektu

- main.cpp ( Funkcja main i testowanie funkcji )

- Item.h ( Definicja klasy Item )

- ListTwoway.h ( Definicja klasy ListTwoway )

### Wzorce projektowe

- **Factory**: Wzorzec factory powinien umożliwiać tworzenie instancji listy. Dzięki temu użytkownik nie musi martwić się o szczegóły tworzenia obiektów
- **Iterator**: Iteratory pozwalają na łatwą nawigację po liście w obu kierunkach. Implementacja iteratora umożliwi łatwe przeglądanie elementów listy

## Lista zadań (TODO)

1. **main.cpp**:
    - [ ✅ ] Zaimplementuj funkcję `main()`, która testuje wszystkie metody listy oraz iteratora.
    - [ ] Przetestuj wszystkie funkcjonalności listy (dodawanie, usuwanie, iteracja, wyświetlanie).
2. **Item**:
    - [ ✅ ] Stwórz klasę `Item` z odpowiednimi właściwościami: `data`, `next`, `prev`.
    - [ ✅ ] Zaimplementuj konstruktor oraz destruktor.
3. **ListTwoway**:
    - [ ✅ ] Stwórz klasę `ListTwoway` z odpowiednimi właściwościami: `head`, `tail`.
    - [ ] Stwórz **`unshift(data)`**.
    - [ ] Stwórz **`push(data)`**.
    - [ ] Stwórz **`insertAt(index, data)`**.
    - [ ] Stwórz **`shift()`**.
    - [ ] Stwórz **`pop()`**.
    - [ ] Stwórz **`removeAt(index)`**.
    - [ ] Stwórz **`clear()`**.

4. **Iterator**:
    - [ ] Zaimplementuj klasę `Iterator`, która będzie umożliwiać iterację po elementach listy.
    - [ ] Dodaj metody do przechodzenia do następnego i poprzedniego elementu oraz sprawdzania, czy są elementy do przeglądania.

5. **Factory**:
    - [ ] Stwórz klasę `Factory`, która będzie odpowiedzialna za tworzenie instancji listy.
