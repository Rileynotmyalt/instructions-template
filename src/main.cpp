
/*
        Check the README for specifications!
*/

#include "MyList.h"

void HashFunction(const string &key);
void ApplyHashFunction(MyList<string> keys);

int main() {
  MyList<string> l;

  string line;
  while (std::cin >> line) {
    l.push_front(line);
  }
  ApplyHashFunction(l);

  return 0;
}

// "Suggested" Functions, feel free to change

// Takes in an integer (hash key) and prints the corresponding hash-code
// (see README)
void HashFunction(const string &key) {
  int sum = 0;
  for (char c : key) {
    sum += c - '0';
  }
  std::cout << sum << std::endl;
}

// Takes a list of hash keys
// Prints the hash codes for every element
void ApplyHashFunction(MyList<string> keys) {
  keys.reverse();
  while (keys.size() > 1) {
    HashFunction(keys.front());
    keys.pop_front();
  }
}
