/*
 * Implementation file for a clean and simple linked list
 * std::forward_list syntax
 */

// These are freebies, touch only if attempting doubly-linked list
// Tests may depend on these working!
template <typename T> ListNode<T> *MyList<T>::begin() { return head; }

template <typename T> MyList<T>::MyList() {
  num_elements = 0;
  head = new ListNode<T>;
  head->next = nullptr;
}

template <typename T> int MyList<T>::size() { return num_elements; }

template <typename T> T &MyList<T>::front() { return head->data; }

template <typename T> void MyList<T>::push_front(const T &value) {
  ListNode<T> *tmp = new ListNode<T>;
  tmp->data = value;
  tmp->next = head;
  head = tmp;
  num_elements++;
}

template <typename T> void MyList<T>::pop_front() {

  if (num_elements > 0) {
    ListNode<T> *tmp = head->next;
    delete head;
    head = tmp;
    num_elements--;
  }
}

// Implement each of the functions below
// PLEASE READ MyList.h carefully for details on each!
// Check out unit_tests/ and mem_tests/ for grading details

template <typename T> MyList<T>::~MyList() {
  clear();
  delete head;
}

template <typename T> MyList<T> &MyList<T>::operator=(const MyList<T> &rhs) {

  clear();
  ListNode<T> *pos_ptr = head;
  ListNode<T> *data_ptr = rhs.head;
  while (data_ptr->next != nullptr) {
    insert(pos_ptr, data_ptr->data);
    pos_ptr = pos_ptr->next;
    data_ptr = data_ptr->next;
  }

  return *this;
}

template <typename T> MyList<T>::MyList(const MyList<T> &rhs) {
  head = new ListNode<T>;
  head->next = nullptr;

  *this = rhs;
}

template <typename T> void MyList<T>::assign(int count, const T &value) {
  ListNode<T> *runner = head;
  for (int i = 0; i < count; ++i) {
    if (runner->next == nullptr) {
      push_front(value);
    } else {
      runner->data = value;
      runner = runner->next;
    }
  }
}

template <typename T> void MyList<T>::clear() {
  ListNode<T> *tmp;
  tmp = head->next;
  while (tmp != nullptr) {
    delete head;
    head = tmp;
    tmp = head->next;
  }
  num_elements = 0;
}

template <typename T>
void MyList<T>::insert(LinkedListIterator<T> iter, const T &value) {
  ListNode<T> *tmp = new ListNode<T>;
  tmp->data = iter->data;
  tmp->next = iter->next;
  iter->data = value;
  iter->next = tmp;
  num_elements++;
}

template <typename T> void MyList<T>::erase(LinkedListIterator<T> iter) {
  if (iter->next != nullptr) {
    ListNode<T> *tmp = iter->next;
    iter->data = tmp->data;
    iter->next = tmp->next;
    delete tmp;
    tmp = nullptr;
    num_elements--;
  }
}

template <typename T> void MyList<T>::reverse() {
  ListNode<T> *tmp = head->next;
  head->next = nullptr;

  while (tmp->next != nullptr) {
    ListNode<T> *forward = tmp->next;
    tmp->next = head;
    head = tmp;
    tmp = forward;
  }
  delete tmp;
}

template <typename T> LinkedListIterator<T> MyList<T>::find(const T &value) {
  ListNode<T> *runner = head;
  while (runner->next != nullptr) {
    if (value == runner->data)
      return runner;
    runner = runner->next;
  }
  return nullptr;
}

template <typename T>
void MyList<T>::splice_after(ListNode<T> *splice_point, MyList<T> &source) {
  ListNode<T> *tmp = splice_point->next;
  ListNode<T> *tmp_2 = source.head;
  splice_point->next = tmp_2;
  while (tmp_2->next->next != nullptr) {
    tmp_2 = tmp_2->next;
  }
  source.head = tmp_2->next;
  tmp_2->next = tmp;
  num_elements += source.size();
  source.num_elements = 0;
}
