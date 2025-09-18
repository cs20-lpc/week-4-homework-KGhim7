// default constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {
    this->length = 0;
}

// destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// add the argument to the end of the list
template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    this->length++;
}

// remove all elements in the list, resetting to the initial state
template <typename T>
void LinkedList<T>::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    this->length = 0;
}

// return the element at the given position (argument)
template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw "getElement: error, position out of bounds";
    }
    Node* curr = head;
    int index = 0;
    while (curr != nullptr && index < position) {
        curr = curr->next;
        index++;
    }
    if (curr == nullptr) {
        throw "getElement: internal error";
    }
    return curr->value;
}

// return the current length of the list
template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

// insert the given element (argument 2) at
// the given position (argument 1)
template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw "insert: error, position out of bounds";
    }
    Node* newNode = new Node(elem);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head;
        int index = 0;
        while (index < position - 1) {
            curr = curr->next;
            index++;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    this->length++;
}

// determine if the list currently empty
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

// remove the element at the given position (argument)
template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw "remove: error, position out of bounds";
    }
    Node* target = nullptr;
    if (position == 0) {
        target = head;
        head = head->next;
    } else {
        Node* curr = head;
        int index = 0;
        while (index < position - 1) {
            curr = curr->next;
            index++;
        }
        target = curr->next;
        curr->next = target->next;
    }
    delete target;
    this->length--;
}

// replace the element at the given position (argument 1) with
// the value given (argument 2)
template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw "replace: error, position out of bounds";
    }
    Node* curr = head;
    int index = 0;
    while (curr != nullptr && index < position) {
        curr = curr->next;
        index++;
    }
    if (curr == nullptr) {
        throw "replace: internal error";
    }
    curr->value = elem;
}

// overloaded stream insertion operator to make printing easier
template <typename U>
ostream& operator<<(ostream& os, const LinkedList<U>& list) {
    if (list.isEmpty()) {
        os << "[empty]\n";
        return os;
    }
    typename LinkedList<U>::Node* curr = list.head;
    while (curr != nullptr) {
        os << curr->value;
        if (curr->next != nullptr) os << " -> ";
        curr = curr->next;
    }
    os << endl;
    return os;
}
