class DoublyLinkedList {
private:
  Node* head; 
  Node* tail;   
  int nodeCount;

public:
  void insertItemAtFront(int value);

  void insertItemAtEnd(int value);

  void insertItemAtIndex(int index, int value);

  void removeFirstItem();

  void removeLastItem();

  void removeItemFromIndex(int index);

  void removeAllItems();

  void displayAllItems() const;

  void displayAllItemsReversed() const;

  void displayNextItemFromIndex(int index) const;

  void displayPreviousItemFromIndex(int index) const;
};
