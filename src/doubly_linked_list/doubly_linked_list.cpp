#include "doubly_linked_list.hpp"

DoublyLinkedList::Node::Node(int nodeValue) : value(nodeValue), previous(nullptr), next(nullptr) {}

DoublyLinkedList::Node::Node(int nodeValue, Node* previousNode) : value(nodeValue), previous(previousNode), next(nullptr) {}

std::ostream& operator<<(std::ostream& stream, const DoublyLinkedList::Node* node) {
  stream << node->value;
  return stream;
}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), nodeCount(0) {}

DoublyLinkedList::~DoublyLinkedList() {
  removeAllItems();
}

void DoublyLinkedList::insertItemAtFront(int value) {
  if (head == nullptr) {
    head = new Node(value);
    tail = head;
  } else {
    Node* temporaryNode = head;
    head->previous = new Node(value);
    head = head->previous;
    head->next = temporaryNode;
  }

  ++nodeCount;
}

void DoublyLinkedList::insertItemAtEnd(int value) {
  if (head == nullptr) {
    head = new Node(value);
    tail = head;
  } else {
    tail->next = new Node(value, tail);
    tail = tail->next;
  }

  ++nodeCount;
}

void DoublyLinkedList::insertItemAtIndex(int index, int value) {
  if (index < 0) {
    throw std::out_of_range("The index cannot be less than 0");
  } else if (index == 0) {
    insertItemAtFront(value);
  } else if (index == nodeCount) {
    insertItemAtEnd(value);
  } else {
    if (index > nodeCount) {
      throw std::out_of_range("Cannot insert value under index: " + index);
      return;
    }

    Node* current = head;
    for (int i = 0; i <= index - 1; i++) {
      current = current->next;
    }

    Node* temporaryNode = current;
    Node* previousNode = current->previous;

    current = new Node(value);
    previousNode->next = current;
    current->previous = previousNode;
    current->next = temporaryNode;

    ++nodeCount;
  }
}

void DoublyLinkedList::removeFirstItem() {
  if (head == nullptr) {
    throw std::out_of_range("Cannot remove first item from an empty list");
  }

  if (nodeCount > 1) {
    Node* temporaryNode = head->next;
    delete head;
    head = temporaryNode;
    head->previous = nullptr;
    if (nodeCount == 2) {
      head = tail;
    }
  } else if (nodeCount == 1) {
    delete head;
    head = nullptr;
    tail = nullptr;
  }

  --nodeCount;
}

void DoublyLinkedList::removeLastItem() {
  if (tail == nullptr) {
    throw std::out_of_range("Cannot remove last element from an empty list");
  }

  if (nodeCount > 2) {
    Node* previousNode = tail->previous;
    delete tail;
    tail = previousNode;
    tail->next = nullptr;
  } else if (nodeCount == 2) {
    Node* previousNode = tail->previous;
    delete tail;
    tail = previousNode;
    tail->next = nullptr;
    head = tail;
  } else if (nodeCount == 1) {
    delete tail;
    head = nullptr;
    tail = nullptr;
  }
  --nodeCount;
}

void DoublyLinkedList::removeItemFromIndex(int index) {
  if (index < 0) {
    throw std::out_of_range("Index cannot be less than 0");
  }

  if (index > nodeCount - 1) {
    throw std::out_of_range("Index out of list size");
  }

  if (index == 0) {
    removeFirstItem();
  } else if (index == nodeCount - 1) {
    removeLastItem();
  } else {
    Node* current = head;
    for (int i = 0; i <= index - 1; i++) {
      current = current->next;
    }

    std::cout << current->value << '\n';
    Node* previousNode = current->previous;
    Node* nextNode = current->next;

    delete current;
    previousNode->next = nextNode;
    nextNode->previous = previousNode;

    --nodeCount;
  }
}

void DoublyLinkedList::removeAllItems() {
  Node* current = head;
  while (current != nullptr) {
    Node* temporaryNode = current;
    current = current->next;
    delete temporaryNode;
  }
  head = nullptr;
  tail = nullptr;
  nodeCount = 0;
}

void DoublyLinkedList::displayAllItems() const {
  std::cout << *this;
}

void DoublyLinkedList::displayAllItemsReversed() const {
  if (tail != nullptr) {
    Node* current = tail;
    while (current->previous != nullptr) {
      std::cout << current << ", ";
      current = current->previous;
    }
    std::cout << current << '\n';
  }
}

void DoublyLinkedList::displayNextItemFromIndex(int index) const {
  if (index < -1) {
    throw std::out_of_range("Index cannot be less than -1");
  }

  if (index > nodeCount - 1) {
    throw std::out_of_range("Index out of list size");
  }

  if (nodeCount - 2 >= index) {
    std::cout << (*this)[index + 1] << std::endl;
  } else if (nodeCount - 1 == index) {
    throw std::out_of_range("Next element missing");
  }
}

void DoublyLinkedList::displayPreviousItemFromIndex(int index) const {
  if (index < 0) {
    throw std::out_of_range("Index cannot be less than 0");
  }

  if (index > nodeCount) {
    throw std::out_of_range("Index out of list size");
  }

  if (index < 1) {
    throw std::out_of_range("Previous item missing");
  } else {
    std::cout << (*this)[index - 1] << '\n';
  }
}

const int& DoublyLinkedList::operator[](int index) const {
  if (index < 0) {
    throw std::out_of_range("Index cannot be less than 0");
  }

  if (index > nodeCount - 1) {
    throw std::out_of_range("Index out of list size");
  }

  Node* current = head;
  for (int i = 0; i <= index - 1; i++) {
    current = current->next;
  }

  return current->value;
}

std::ostream& operator<<(std::ostream& stream, const DoublyLinkedList& list) {
  if (list.head != nullptr) {
    DoublyLinkedList::Node* current = list.head;
    while (current->next != nullptr) {
      stream << current << ", ";
      current = current->next;
    }
    stream << current << '\n';
  } else {
    stream << "Lista jest pusta\n";
  }

  return stream;
}
