#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>

#include "dict.h"
#include "tableEntry.h"

#include "../../PRACT1/PRA_2324_P1/list.h"
#include "../../PRACT1/PRA_2324_P1/node.h"
#include "../../PRACT1/PRA_2324_P1/listlinked.h"


template <typename V>
class HashTable: public Dict<V> {

    private:
        //Atributos privados de la clase
        int n;
        int max;
        listlinked<TableEntry<V>> * table;

    public:
        //métodos de dict.h
        
        void insert(std::string key, V value) override {}
        V search(std::string key) override {}
        V remove(std::string key) override {}
        int entries() override { return n; }

    
        //Función hash
        int h(std::string key){
            int sum = 0;
            for(int i = 0; i < key.size(); ++i){
                sum += static_cast<int>(clave.at(i));
            }
            return sum % max;
        }
        
        //Método constructor
        HashTable(int size){
            table = new TableEntry<V>[max];
        }
        
        //Método destructor
        ~HashTable(){
            delete[] table;
        }

        //Devuelve el número total de cubetas
        int capacity(){
            return max;
        }
        
        //Sobrecarga del operador << (devolver la tabla hash entera)
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
            for(int i = 0; i < th.max; ++i){
                out << "[" << i << "] ";
                out << th.table[i].key << "->" << th.table[i].value << "\n";
            }
            return out;
        }
        
        V operator[](std::string key){
            int index = h(key);
            
            for(int i = 0; i < max; ++i){
                if(table[index].key == key){
                return table[index].value;
                }
            }
            return runtime_error("Elemento no encontrado");   
        }
        
};

#endif