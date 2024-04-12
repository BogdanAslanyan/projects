#ifndef S21_set_H
#define S21_set_H

#include <cstddef>
#include <iostream>
#include <limits>
#include <utility>

#include "s21_vector.h"

namespace s21 {
template <typename T>
class set {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  //  *Set Member functions*
  set() : root(nullptr), size_(0) {}
  ~set() { clear(); }

  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s);
  set& operator=(set&& s);

 private:
  template <typename value_type>
  class Node {
   public:
    value_type value;
    Node* left;
    Node* right;
    Node* parent;
    size_type count;

    Node(value_type key)
        : value(key), left(nullptr), right(nullptr), parent(nullptr) {}
  };

  Node<value_type>* root;
  size_type size_;

  template <typename value_type>
  class setIterator {
   public:
    setIterator(Node<value_type>* node = nullptr) : cur(node), counter(0) {}

    value_type operator*() { return cur ? cur->value : value_type(); }

    setIterator& operator++() {
      if (!cur) return *this;

      counter++;

      if (cur->right) {
        cur = cur->right;
        while (cur->left) {
          cur = cur->left;
        }
      } else {
        if (cur->parent) {
          value_type tmp = cur->value;
          while (cur->parent && cur->parent->value < tmp) cur = cur->parent;
          cur = cur->parent;
        } else {
          cur = nullptr;
        }
      }

      return *this;
    }
    setIterator& operator--() {
      if (!cur) return *this;
      counter--;

      if (counter <= 0) {
        if (cur->left) {
          cur = cur->left;
          while (cur->right) {
            cur = cur->right;
          }
        } else {
          if (cur->parent) {
            value_type tmp = cur->value;
            while (cur->parent && cur->parent->value > tmp) cur = cur->parent;
            cur = cur->parent;
          } else {
            cur = nullptr;
          }
        }
      }

      return *this;
    }

    setIterator operator++(int) {
      setIterator tmp(*this);
      ++*this;
      return tmp;
    }

    setIterator operator--(int) {
      setIterator tmp(*this);
      --*this;
      return tmp;
    }

    bool operator==(const setIterator& other) const noexcept {
      return cur == other.cur;
    }
    bool operator!=(const setIterator& other) const noexcept {
      return cur != other.cur;
    }

   private:
    Node<value_type>* cur;
    size_type counter;
  };

  template <typename value_type>
  class setConstIterator : public setIterator<value_type> {
   public:
    setConstIterator(const Node<value_type>* node = nullptr)
        : setIterator<value_type>(const_cast<Node<value_type>*>(node)) {}

    setConstIterator(const setIterator<value_type>& other)
        : setIterator<value_type>(other) {}
  };

 public:
  using iterator = setIterator<value_type>;
  using const_iterator = setConstIterator<value_type>;

  //  *Set Iterators*
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  //  *Set Capacity*
  bool empty() const { return !size_; }
  size_type size() const { return size_; }
  size_type max_size() const { return std::numeric_limits<size_type>::max(); }

  //  *Set Modifiers*
  void clear();
  typename std::pair<typename s21::set<value_type>::iterator, bool> insert(
      const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

  //  *Set Lookup*
  iterator find(const_reference key);
  bool contains(const_reference key);

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

 private:
  Node<value_type>* insertNode(Node<value_type>* node, const_reference val,
                               Node<value_type>* parent);
  Node<value_type>* findNode(Node<value_type>* node, const_reference val);
  Node<value_type>* eraseNode(Node<value_type>* node, const_reference val);
  Node<value_type>* findMinNode(Node<value_type>* node);
  void deleteNode(Node<value_type>* node);
  void copyNode(const Node<value_type>* node);
  iterator last() const;
};

//  ------------------------------------------------------  *Set Iterators*
template <typename value_type>
typename set<value_type>::iterator set<value_type>::begin() {
  if (!root) return iterator(nullptr);
  Node<value_type>* tmp = root;
  while (tmp->left) tmp = tmp->left;
  return iterator(tmp);
}

template <typename value_type>
typename set<value_type>::iterator set<value_type>::end() {
  return iterator(nullptr);
}

//  ------------------------------------------------------  *Set Modifiers*

template <typename value_type>
void set<value_type>::clear() {
  deleteNode(root);
  size_ = 0;
}

template <typename value_type>
typename std::pair<typename s21::set<value_type>::iterator, bool>
s21::set<value_type>::insert(const_reference value) {
  root = insertNode(root, value, nullptr);
  size_++;
  return std::make_pair(find(value), contains(value));
}

template <typename value_type>
void set<value_type>::erase(iterator pos) {
  if (contains(*pos)) {
    if (root) root = eraseNode(root, *pos);
    size_--;
  }
}

template <typename value_type>
void set<value_type>::swap(set& other) {
  std::swap(root, other.root);
  std::swap(size_, other.size_);
}

template <typename value_type>
void set<value_type>::merge(set& other) {
  iterator it = other.begin();
  while (it != other.end()) {
    insert(*it);
    it++;
  }
}

//  ------------------------------------------------------  *Set Lookup*

template <typename value_type>
typename set<value_type>::iterator set<value_type>::find(const_reference key) {
  Node<value_type>* tmp = findNode(root, key);
  return iterator(tmp ? tmp : nullptr);
}

template <typename value_type>
bool set<value_type>::contains(const_reference key) {
  Node<value_type>* tmp = findNode(root, key);
  return tmp ? true : false;
}

//  --------------------------------------------  *Set Member functions*

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const& items)
    : root(nullptr), size_(0) {
  for (auto item : items) {
    insert(item);
  }
}

template <typename value_type>
set<value_type>::set(const set& s) : root(nullptr), size_(0) {
  copyNode(s.root);
}

template <typename value_type>
set<value_type>::set(set&& s) : root(s.root), size_(s.size_) {
  s.root = nullptr;
  s.size_ = 0;
}

template <typename value_type>
template <typename... Args>
s21::vector<std::pair<typename set<value_type>::iterator, bool>>
set<value_type>::insert_many(Args&&... args) {
  return s21::vector<std::pair<iterator, bool>>(
      {(std::make_pair(insert(std::forward<Args>(args)), true), ...)});
}

//  ------------------------------------------------------ **

template <typename value_type>
void set<value_type>::copyNode(const Node<value_type>* node) {
  if (node) {
    insert(node->value);
    size_++;
    copyNode(node->left);
    copyNode(node->right);
  }
}

template <typename value_type>
void set<value_type>::deleteNode(Node<value_type>* node) {
  if (node) {
    deleteNode(node->right);
    deleteNode(node->left);
    delete node;
  }
}

template <typename value_type>
typename set<value_type>::template Node<value_type>*
set<value_type>::findMinNode(Node<value_type>* node) {
  if (!node->left) return node;
  return findMinNode(node->left);
}

template <typename value_type>
typename set<value_type>::template Node<value_type>* set<value_type>::eraseNode(
    Node<value_type>* node, const_reference val) {
  if (node->value == val) {
    if (!node->left && !node->right) {
      if (node->parent) {
        if (node->parent->right == node) node->parent->right = nullptr;
        if (node->parent->left == node) node->parent->left = nullptr;
      }
      delete node;
      return nullptr;
    } else if (!node->left) {
      Node<value_type>* tmp = node->right;
      if (node->parent) {
        if (node->parent->right == node) node->parent->right = tmp;
        if (node->parent->left == node) node->parent->left = tmp;
      }
      tmp->parent = node->parent;
      delete node;
      return tmp;
    } else if (!node->right) {
      Node<value_type>* tmp = node->left;
      if (node->parent) {
        if (node->parent->right == node) node->parent->right = tmp;
        if (node->parent->left == node) node->parent->left = tmp;
      }
      tmp->parent = node->parent;
      delete node;
      return tmp;
    }

    Node<value_type>* minNodeInRightSubtree = findMinNode(node->right);
    node->value = minNodeInRightSubtree->value;
    node->right = eraseNode(node->right, minNodeInRightSubtree->value);

    // return node;
  } else if (node->value < val) {
    node->right = node->right ? eraseNode(node->right, val) : nullptr;
  } else if (node->value > val) {
    node->left = node->left ? eraseNode(node->left, val) : nullptr;
  }

  return node;
}

template <typename value_type>
typename set<value_type>::template Node<value_type>* set<value_type>::findNode(
    Node<value_type>* node, const_reference val) {
  if (!node || node->value == val) return node;

  if (node->value < val) {
    node = findNode(node->right, val);
  } else if (node->value > val) {
    node = findNode(node->left, val);
  }

  return node;
}

template <typename value_type>
typename set<value_type>::template Node<value_type>*
set<value_type>::insertNode(Node<value_type>* node, const_reference val,
                            Node<value_type>* parent) {
  if (node) {
    if (val < node->value) {
      node->left = insertNode(node->left, val, node);
    }
    if (val > node->value) {
      node->right = insertNode(node->right, val, node);
    }
  } else {
    node = new Node(val);
    node->parent = parent;
  }
  return node;
}

}  // namespace s21

#endif  // S21_set_H