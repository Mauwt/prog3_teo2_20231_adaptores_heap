//
// Created by rrivas on 19/06/2023.
//

#ifndef PROG3_TEO2_20231_ADAPTORES_HEAP_COLA_PRIORIZADA_H
#define PROG3_TEO2_20231_ADAPTORES_HEAP_COLA_PRIORIZADA_H

#include <vector>
using namespace std;

// Inicialmente vamos a crear un max heap
template <typename T, typename Container=vector<T>>
class cola_priorizada {
    Container cnt;
    size_t get_parent_index(size_t index) { return index / parent; }
    size_t get_left_index(size_t parent_index) { return parent_index * 2; }
    size_t get_right_index(size_t parent_index) { return parent_index * 2 + 1; }
    bool is_root(size_t index) { return index == 1; }
    bool has_children(size_t parent_index) {
        return get_left_index(parent_index) < size(cnt); }
    bool has_right_child(size_t parent_index) {
        return get_right_index(parent_index) < size(cnt); }

    void percolate_up(size_t index) {
        // 1. Condicion base
        // 1.1 root
        if (is_root(index) == true) return;
        // 1.2 Obtener el indice del padre
        auto parent_index = get_parent_index(index);
        // 1.3 Comparar el padre con el hijo
        if (cnt[index] < cnt[parent_index]) return;
        // 2. Condicion recursiva
        // 2.1 Realizo el swap
        swap(cnt[index], cnt[parent_index]);
        // 2.2 llamar percolate up (parent index)
        percolate_up(parent_index);
    }
public:
    cola_priorizada(): cnt(1) {}




};

#endif //PROG3_TEO2_20231_ADAPTORES_HEAP_COLA_PRIORIZADA_H
