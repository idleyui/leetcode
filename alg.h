//
// Created by leelddd on 8/2/2018.
//

#ifndef LEETCODE_ALG_H
#define LEETCODE_ALG_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>

using namespace std;

template<typename T>
void print_container(const T& container)
{
    std::copy(std::begin(container),
              std::end(container),
              std::ostream_iterator<typename T::value_type>(cout, " "));
}

#endif //LEETCODE_ALG_H
