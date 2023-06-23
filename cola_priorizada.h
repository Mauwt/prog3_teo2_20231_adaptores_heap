//
// Created by rrivas on 19/06/2023.
//

#ifndef PROG3_TEO2_20231_ADAPTORES_HEAP_COLA_PRIORIZADA_H
#define PROG3_TEO2_20231_ADAPTORES_HEAP_COLA_PRIORIZADA_H

#include <vector>
#include <functional>
using namespace std;

namespace utec {
// Inicialmente vamos a crear un max heap
    template <
            typename T,
            typename Container=vector<T>,
            typename Compare=less<T>>
    class priority_queue {
        Container cnt;
        size_t get_parent_index(size_t index) { return index / 2; }
        size_t get_left_index(size_t parent_index) { return parent_index * 2; }
        size_t get_right_index(size_t parent_index) { return parent_index * 2 + 1; }
        bool is_root(size_t index) { return index == 1; }
        bool has_children(size_t parent_index) {
            return get_left_index(parent_index) < cnt.size(); }
        bool has_right_child(size_t parent_index) {
            return get_right_index(parent_index) < cnt.size(); }

        size_t get_selected_index(size_t parent_index) {
            auto left_index = get_left_index(parent_index);
            if (has_right_child(parent_index)) {
                auto right_index = get_right_index(parent_index);
                return cnt[right_index] < cnt[left_index] ?
                    left_index:
                    right_index;
            }
            return left_index;
        }

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

        void percolate_down(size_t index) {
            // Condiciones basicas
            if (!has_children(index)) return;
            auto child_index = get_selected_index(index);
            if (cnt[child_index] < cnt[index]) return;
            // Condiciones recursivas
            swap(cnt[child_index], cnt[index]);
            percolate_down(child_index);
        }

        void heapify(size_t index) {
            // Obtener el indice del padre
            auto current_index = get_parent_index(index);
            while (current_index >= 1) {
                percolate_down(current_index);
                --current_index;
            }
        }
    public:
        priority_queue(): cnt(1) {}
        explicit priority_queue(const Container& container)
                : cnt(1 + container.size()) {
            copy(begin(container),
                 end(container),
                 next(begin(cnt)));     // O(n)
            heapify(size());              // O(n)
        }
        size_t size() { return cnt.size() - 1; }
        bool empty() { return size() == 0; }
        T top() { return cnt[1]; }

        void push(T value) {
            cnt.push_back(value);
            percolate_up(size()); // Mantenerlo como heap
        }

        template <typename ...Params>
        void emplace(Params ...params) {
            cnt.emplace_back(params...);
            percolate_up(size()); // Mantenerlo como heap
        }

        void pop() {
            // Intercambio entre el ultimo valor y el primer valor
            swap(cnt[1], cnt[size()]);
            // Elimino el ultimo
            cnt.pop_back();
            percolate_down(1);
        }




    };
}

#endif //PROG3_TEO2_20231_ADAPTORES_HEAP_COLA_PRIORIZADA_H
