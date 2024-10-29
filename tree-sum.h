//
// Created by KayotKlimenko on 29.10.2024.
//

#pragma once

#ifndef TREE_SUM_H
#define TREE_SUM_H

#include <iostream>
#include <vector>

template <typename T>
class TreeSum {
private:
    inline static const T valueZeroType = static_cast<T>(0);

private:
    size_t n{ 0 };
    std::vector<T> tree{ 0 };
    std::vector<T> data{ 0 };

public:
    TreeSum(const std::vector<T>& data) : data(data) {
        n = data.size();
        tree.resize(4 * n, valueZeroType);
        Build(1, 0, n - 1);
    }
    TreeSum(const size_t n) : n(n) {
        tree.resize(4 * n, valueZeroType);
        Build(1, 0, n - 1);
    }

    void Build(size_t i, size_t l, size_t r);

    void Update(size_t i, size_t l, size_t r, size_t idx, T value);

    void Update(const size_t i, const T value) {
        Update(1, 0, n - 1, i, value);
    }

    T GetValue(size_t i, size_t l, size_t r, size_t left, size_t right);

    T GetValue(const size_t l, const size_t r) {
        return GetValue(1, 0, n - 1, l, r);
    }

    T GetValue(const size_t i) {
        return GetValue(1, 0, n - 1, i, i);
    }
};

#endif //TREE_SUM_H
