#include "stack.h"
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
#include <memory>
#include <thread>
#include <vector>

using namespace std;

int main()
{
    std::shared_ptr<Stack> stack{new Stack()};
    std::vector<std::thread> threads;
    std::vector<int> values{100, 300, 500, 700, 900};

    for (int value : values)
    {
        stack->Push(value);
    }

    const int num_runs = 500;
    const int num_threads = 10;

    // Run concurrently multiple times to check for correctness.
    for (int run = 0; run < num_runs; run++)
    {
        std::vector<std::thread> threads;

        for (int tid = 0; tid < num_threads; tid++)
        {
            threads.push_back(std::thread([tid, &stack]() {
                stack->Push(tid);
            }));
        }

        for (int i = 0; i < num_threads; i++)
        {
            threads[i].join();
        }
    }

    vector<int> pops;
    int popVal = 0;
    while (stack->Pop(popVal))
    {
        pops.push_back(popVal);
    }

    map<int, int> freq;
    for (int x : pops)
    {
        freq[x]++;
    }

    for (auto &e : freq)
    {
        cout << e.first << " : " << e.second << endl;
    }
}