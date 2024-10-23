#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include "../doubly_linked_list/doubly_linked_list.hpp"

/// @brief Wyliczenie opcji dostępnych w menu.
/// Definiuje różne operacje, które użytkownik może wybrać w aplikacji.
enum MenuOption {
  INSERT_ITEM_AT_FRONT = 1,   ///< Dodaj element na początku listy.
  INSERT_ITEM_AT_END,         ///< Dodaj element na końcu listy.
  INSERT_ITEM_AT_INDEX,       ///< Wstaw element na podanym indeksie.

  REMOVE_ITEM_FROM_FRONT,     ///< Usuń pierwszy element z listy.
  REMOVE_ITEM_FROM_END,       ///< Usuń ostatni element z listy.
  REMOVE_ITEM_FROM_INDEX,     ///< Usuń element na podanym indeksie.
  CLEAR_LIST,                 ///< Usuń wszystkie elementy z listy.

  DISPLAY_ALL_ITEMS,          ///< Wyświetl wszystkie elementy listy.
  DISPLAY_ALL_ITEMS_REVERSED, ///< Wyświetl elementy listy w odwrotnej kolejności.
  DISPLAY_NEXT_ITEM_FROM_INDEX,  ///< Wyświetl kolejne elementy listy, zaczynając od podanego indeksu.
  DISPLAY_PREVIOUS_ITEM_FROM_INDEX, ///< Wyświetl poprzednie elementy listy, zaczynając od podanego indeksu.

  EXIT                        ///< Zakończ działanie aplikacji.
};

/// @brief Przeciążenie operatora >> do odczytu opcji menu.
/// @param iStream Strumień wejściowy.
/// @param menuOption Opcja menu, którą należy ustawić.
/// @return Referencja do strumienia wejściowego.
std::istream& operator>>(std::istream& iStream, MenuOption& menuOption);

/// @brief Klasa reprezentująca aplikację obsługującą listę dwukierunkową.
/// Umożliwia operacje takie jak dodawanie, usuwanie i wyświetlanie elementów z listy poprzez menu.
class App {
  static DoublyLinkedList doublyLinkedList; ///< Obiekt listy dwukierunkowej.

  /// @brief Wyświetla główne menu aplikacji i zwraca wybraną opcję.
  /// @return Wybrana opcja menu.
  static int mainMenu();

  // Funkcje obsługi wstawiania elementów

  /// @brief Obsługuje wstawianie elementu na początku listy.
  static void handleInsertItemAtFront();

  /// @brief Obsługuje wstawianie elementu na końcu listy.
  static void handleInsertItemAtEnd();

  /// @brief Obsługuje wstawianie elementu na podanym indeksie.
  static void handleInsertItemAtIndex();

  // Funkcje obsługi usuwania elementów

  /// @brief Obsługuje usunięcie pierwszego elementu z listy.
  static void handleRemoveItemFromFront();

  /// @brief Obsługuje usunięcie ostatniego elementu z listy.
  static void handleRemoveItemFromEnd();

  /// @brief Obsługuje usunięcie elementu na podanym indeksie.
  static void handleRemoveItemFromIndex();

  // Funkcje obsługi wyświetlania elementów

  /// @brief Wyświetla wszystkie elementy listy w kolejności od początku do końca.
  static void handleDisplayAllItems();

  /// @brief Wyświetla wszystkie elementy listy w odwrotnej kolejności (od końca do początku).
  static void handleDisplayAllItemsReversed();

  /// @brief Wyświetla elementy, zaczynając od podanego indeksu, poruszając się do przodu.
  static void handleDisplayNextItemFromIndex();

  /// @brief Wyświetla elementy, zaczynając od podanego indeksu, poruszając się do tyłu.
  static void handleDisplayPreviousItemFromIndex();

  // Inne operacje

  /// @brief Usuwa wszystkie elementy z listy.
  static void handleClearList();

  // Funkcja zakończenia działania aplikacji

  /// @brief Obsługuje zakończenie działania aplikacji.
  /// @return Kod wyjścia z aplikacji.
  static int handleExit();

public:
  /// @brief Uruchamia aplikację.
  /// Wyświetla menu i pozwala użytkownikowi wykonywać operacje na liście.
  /// @return Kod zakończenia aplikacji.
  static int run();
};

#endif /* APP_HPP */
