//
// Created by rrivas on 19/06/2023.
//

#ifndef PROG3_TEO2_20231_ADAPTORES_HEAP_PILA_H
#define PROG3_TEO2_20231_ADAPTORES_HEAP_PILA_H

#include <deque>
using namespace std;

template <typename T, typename Container=deque<T>>
class pila {
    Container cnt;
public:
    pila() = default;
    explicit pila(const Container& cnt): cnt(cnt) {}

    size_t size() { return cnt.size();}
    bool empty() { return size() == 0; }
    T top() { return cnt.back(); }
    void pop() { cnt.pop_back(); }
    void push(T value) { cnt.push_back(value); }
    template<typename ...Params>
    void emplace(Params... params) {
        cnt.emplace_back(params...);
    }
};

#endif //PROG3_TEO2_20231_ADAPTORES_HEAP_PILA_H
