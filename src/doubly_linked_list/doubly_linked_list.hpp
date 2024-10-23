#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>

/// @brief Klasa reprezentująca listę dwukierunkową.
/// Klasa umożliwia dodawanie, usuwanie oraz przeglądanie elementów
/// w obu kierunkach (przód i tył).
class DoublyLinkedList {
  /// @brief Struktura reprezentująca pojedynczy węzeł na liście.
  /// Węzeł przechowuje wartość oraz wskaźniki do poprzedniego i następnego węzła.
  struct Node {
    int value;      ///< Wartość przechowywana w węźle.
    Node* previous; ///< Wskaźnik na poprzedni węzeł w liście.
    Node* next;     ///< Wskaźnik na następny węzeł w liście.

    /// @brief Konstruktor inicjalizujący węzeł z wartością domyślną.
    /// @param nodeValue Wartość do przechowania w węźle (domyślnie 0).
    explicit Node(int nodeValue = 0);

    /// @brief Konstruktor inicjalizujący węzeł z wartością i wskaźnikiem.
    /// @param nodeValue Wartość do przechowania w węźle.
    /// @param nodePointer Wskaźnik na inny węzeł (zazwyczaj następny lub poprzedni).
    Node(int nodeValue, Node* nodePointer);

    /// @brief Przeciążenie operatora << do wyświetlania węzła.
    /// @param stream Strumień wyjściowy.
    /// @param node Wskaźnik na węzeł, który ma być wyświetlony.
    /// @return Referencja do strumienia wyjściowego.
    friend std::ostream& operator<<(std::ostream& stream, const DoublyLinkedList::Node* node);
  };

private:
  Node* head;       ///< Wskaźnik na pierwszy węzeł listy.
  Node* tail;       ///< Wskaźnik na ostatni węzeł listy.
  int nodeCount;    ///< Liczba elementów w liście.

public:
  /// @brief Domyślny konstruktor listy dwukierunkowej.
  /// Inicjalizuje pustą listę.
  DoublyLinkedList();

  /// @brief Destruktor listy dwukierunkowej.
  /// Usuwa wszystkie węzły i zwalnia pamięć.
  ~DoublyLinkedList();

  /// @brief Dodaje nowy element na początku listy.
  /// @param value Wartość elementu do dodania.
  void insertItemAtFront(int value);

  /// @brief Dodaje nowy element na końcu listy.
  /// @param value Wartość elementu do dodania.
  void insertItemAtEnd(int value);

  /// @brief Wstawia nowy element na podaną pozycję.
  /// @param value Wartość elementu do wstawienia.
  /// @param index Indeks, na którym element ma zostać wstawiony.
  void insertItemAtIndex(int index, int value);

  /// @brief Usuwa pierwszy element z listy.
  void removeFirstItem();

  /// @brief Usuwa ostatni element z listy.
  void removeLastItem();

  /// @brief Usuwa element na podanym indeksie.
  /// @param index Pozycja elementu do usunięcia.
  void removeItemFromIndex(int index);

  /// @brief Usuwa wszystkie elementy z listy.
  void removeAllItems();

  /// @brief Wyświetla zawartość listy w kolejności od pierwszego do ostatniego elementu.
  void displayAllItems() const;

  /// @brief Wyświetla zawartość listy w odwrotnej kolejności (od ostatniego do pierwszego elementu).
  void displayAllItemsReversed() const;

  /// @brief Wyświetla elementy listy, zaczynając od podanego indeksu, w kolejności do przodu.
  /// @param index Indeks początkowy.
  void displayNextItemFromIndex(int index) const;

  /// @brief Wyświetla elementy listy, zaczynając od podanego indeksu, w kolejności do tyłu.
  /// @param index Indeks początkowy.
  void displayPreviousItemFromIndex(int index) const;

  /// @brief Przeciążenie operatora [] do dostępu do wartości na podanym indeksie.
  /// @param index Indeks elementu, do którego chcesz uzyskać dostęp.
  /// @return Stała referencja do wartości elementu na podanym indeksie.
  const int& operator[](int index) const;

  /// @brief Przeciążenie operatora << do wyświetlania zawartości listy.
  /// @param stream Strumień wyjściowy.
  /// @param list Lista do wyświetlenia.
  /// @return Referencja do strumienia wyjściowego.
  friend std::ostream& operator<<(std::ostream& stream, const DoublyLinkedList& list);

  /// @brief Przeciążenie operatora << do wyświetlania węzła.
  /// @param stream Strumień wyjściowy.
  /// @param node Wskaźnik na węzeł do wyświetlenia.
  /// @return Referencja do strumienia wyjściowego.
  friend std::ostream& operator<<(std::ostream& stream, const DoublyLinkedList::Node* node);
};

#endif /* DOUBLY_LINKED_LIST_HPP */
