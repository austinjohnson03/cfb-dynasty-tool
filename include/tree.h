#pragma once

#include <queue>
#include <iostream>

template <typename T>
class Node {
  public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
  public:
    Tree() : root(nullptr) {}
    ~Tree() {
      clear(root);
    }

    void clear(Node<T>* node) {
      if (!node) return;
      clear(node->left);
      clear(node->right);
      delete node;
    }

    void insert_node(T value) {
      root = insert_recursive(root, value);
    }

    void delete_node(T value) {
      root = delete_recursive(root, value);
    }

    bool search(T value) {
      return search_recursive(root, value);
    }

    void inorder() {
      inorder_recursive(root);
      std::cout << std::endl;
    }

    void preorder() {
      preorder_recursive(root);
      std::cout << std::endl;
    }

    void postorder() {
      postorder_recursive(root);
      std::cout << std::endl;
    }

    void levelOrder() {
      if (!root) return;

      std::queue<Node<T>*> q;
      q.push(root);
      while(!q.empty()) {
        Node<T>* curr = q.front();
        q.pop();
        std::cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      std::cout << std::endl;
    }

  private:
    Node<T>* root;

    Node<T>* insert_recursive(Node<T>* node, T value) {
      if (!node) return new Node<T>(value);
      if (value < node->data) node->left = insert_recursive(node->left, value);
      else node->right = insert_recursive(node->right, value);
      return node;
    }

    Node<T>* delete_recursive(Node<T>* node, T value) {
      if (!node) return nullptr;
      if (value < node->data) {
        node->left = delete_recursive(node->left, value);
      } else if (value > node->data) {
        node->right = delete_recursive(node->right, value);
      } else {
        if (!node->left && !node->right) {
          delete node;
          return nullptr;
        } else if (!node->left) {
          Node<T>* temp = node->right;
          delete node;
          return temp;
        } else if (!node->right) {
          Node<T>* temp = node->left;
          delete node;
          return temp;
        } else {
          Node<T>* successor = find_min(node->right);
          node->data = successor->data;
          node->right = delete_recursive(node->right, successor->data);
        }
      }
      return node;
    }

    Node<T>* find_min(Node<T>* node) {
      while (node && node->left) node = node->left;
      return node;
    }

    bool search_recursive(Node<T>* node, T value) {
      if (!node) return false;
      if (node->data == value) return true;

      return (value < node->data)
        ? search_recursive(node->left, value)
        : search_recursive(node->right, value);
    }

    void inorder_recursive(Node<T>* node) {
      if (node) {
        inorder_recursive(node->left);
        std::cout << node->data << " ";
        inorder_recursive(node->right);
      }
    }

    void preorder_recursive(Node<T>* node) {
      if (node) {
        std::cout << node->data << " ";
        preorder_recursive(node->left);
        preorder_recursive(node->right);
      }
    }

    void postorder_recursive(Node<T>* node) {
      if (node) {
        postorder_recursive(node->left);
        postorder_recursive(node->right);
        std::cout << node->data << " ";
      }
    }
};
