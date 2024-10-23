#include <Windows.h>

#include "../doubly_linked_list/doubly_linked_list.hpp"
#include "app.hpp"

std::istream& operator>>(std::istream& iStream, MenuOption& menuOption) {
  int num;
  iStream >> num;
  menuOption = static_cast<MenuOption>(num);

  return iStream;
}

DoublyLinkedList App::doublyLinkedList;

int App::mainMenu() {
  while (true) {
    std::cout << "MENU:\n\n";

    std::cout << "---DODAWANIE---\n";
    std::cout << "1. Dodaj element na początek listy\n";
    std::cout << "2. Dodaj element na koniec listy\n";
    std::cout << "3. Dodaj element pod wskazany indeks\n\n";

    std::cout << "---USUWANIE---\n";
    std::cout << "4. Usuń element z początku listy\n";
    std::cout << "5. Usuń element z końca listy,\n";
    std::cout << "6. Usuń element spod wskazanego indeksu\n";
    std::cout << "7. Czyść całą listę\n\n";

    std::cout << "---WYŚWIETLANIE---\n";
    std::cout << "8. Wyświetl całą listę\n";
    std::cout << "9. Wyświetl listę w odwrotnej kolejnośc\n";
    std::cout << "10. Wyświetl następny element\n";
    std::cout << "11. Wyświetl poprzedni element\n\n";

    std::cout << "---OPCJE---\n";
    std::cout << "12. Wyjdź\n\n";

    std::cout << "Wybierz działanie: ";

    MenuOption selectedOption;

    std::cin >> selectedOption;

    if (selectedOption > EXIT) {
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n\n";
      continue;
    }

    std::cout << std::endl;

    switch (selectedOption) {
    case INSERT_ITEM_AT_FRONT:
      handleInsertItemAtFront();
      break;
    case INSERT_ITEM_AT_END:
      handleInsertItemAtEnd();
      break;
    case INSERT_ITEM_AT_INDEX:
      handleInsertItemAtIndex();
      break;
    case REMOVE_ITEM_FROM_FRONT:
      handleRemoveItemFromFront();
      break;
    case REMOVE_ITEM_FROM_END:
      handleRemoveItemFromEnd();
      break;
    case REMOVE_ITEM_FROM_INDEX:
      handleRemoveItemFromIndex();
      break;
    case DISPLAY_ALL_ITEMS:
      handleDisplayAllItems();
      break;
    case DISPLAY_ALL_ITEMS_REVERSED:
      handleDisplayAllItemsReversed();
      break;
    case DISPLAY_NEXT_ITEM_FROM_INDEX:
      handleDisplayNextItemFromIndex();
      break;
    case DISPLAY_PREVIOUS_ITEM_FROM_INDEX:
      handleDisplayPreviousItemFromIndex();
      break;
    case CLEAR_LIST:
      handleClearList();
      break;
    case EXIT: {
      return handleExit();
    }
    default:
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n";
    }

    std::cout << "\n";
  }
}


int App::run() {
  // enable utf-8 printing on windows
  SetConsoleOutputCP(CP_UTF8);

  DoublyLinkedList doublyLinkedList;

  int exitCode = mainMenu();
  return exitCode;
}

void App::handleInsertItemAtFront() {
  std::cout << "Podaj wartosc: ";
  int value;
  std::cin >> value;

  doublyLinkedList.insertItemAtFront(value);
}

void App::handleInsertItemAtEnd() {
  std::cout << "Podaj wartosc: ";
  int value;
  std::cin >> value;

  doublyLinkedList.insertItemAtEnd(value);
}

void App::handleInsertItemAtIndex() {
  std::cout << "Podaj indeks: ";
  int index;
  std::cin >> index;

  std::cout << "Podaj wartosc: ";
  int value;
  std::cin >> value;

  doublyLinkedList.insertItemAtIndex(index, value);
}

void App::handleRemoveItemFromFront() {
  doublyLinkedList.removeFirstItem();
}

void App::handleRemoveItemFromEnd() {
  doublyLinkedList.removeLastItem();
}


void App::handleRemoveItemFromIndex() {
  std::cout << "Podaj indeks: ";
  int index;
  std::cin >> index;

  doublyLinkedList.removeItemFromIndex(index);
}

void App::handleDisplayAllItems() {
  doublyLinkedList.displayAllItems();
}

void App::handleDisplayAllItemsReversed() {
  doublyLinkedList.displayAllItemsReversed();
}

void App::handleDisplayNextItemFromIndex() {
  std::cout << "Podaj indeks: ";
  int index;
  std::cin >> index;

  doublyLinkedList.displayNextItemFromIndex(index);
}

void App::handleDisplayPreviousItemFromIndex() {
  std::cout << "Podaj indeks: ";
  int index;
  std::cin >> index;

  doublyLinkedList.displayPreviousItemFromIndex(index);
}

void App::handleClearList() {
  doublyLinkedList.removeAllItems();
}

int App::handleExit() {
  std::cout << "Dziękujemy za korzystanie z programu\n";
  return 0;
}
