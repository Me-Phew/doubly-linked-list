  struct Node {
    int value;
    Node* previous;
    Node* next;

    explicit Node(int nodeValue = 0);

    Node(int nodeValue, Node* nodePointer);

    friend std::ostream& operator<<(std::ostream& stream, const DoublyLinkedList::Node* node);
  };
