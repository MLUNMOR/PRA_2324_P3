#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "dict.h"
#include "BSTREE.h"
#include "tableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        BSTreeDict() : tree(nullptr){}


        ~BSTreeDict(){
            if (tree != nullptr) {
                delete tree;
                tree = nullptr;
            }
        }


        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
            if (bs.tree != nullptr) {
                out << *(bs.tree);
            } else {
                out << "(diccionario vacío)";
            }
            return out;
        }



        V operator[](std::string key){
            TableEntry<V> te(key, V());
            TableEntry<V> result = tree->search(te);
            return result.value;
        }

        // Override methods from Dict<V> interface
        void insert(std::string key, V value) override {
            if (tree == nullptr) {
                tree = new BSTree<TableEntry<V>>();
            }
            TableEntry<V> te(key, value);
            tree->insert(te);
        }

        V search(std::string key) override {
            if (tree == nullptr) {
                throw std::runtime_error("Diccionario vacío");
            }
            TableEntry<V> te(key, V());
            TableEntry<V> result = tree->search(te);
            return result.value;
        }

        V remove(std::string key) override {
            if (tree == nullptr) {
                throw std::runtime_error("Diccionario vacío");
            }
            TableEntry<V> te(key, V());
            TableEntry<V> result = tree->search(te);
            tree->remove(te);
            return result.value;
        }

        int entries() override {
            if (tree == nullptr) {
                return 0;
            }
            return tree->size();
        }
        
};

#endif