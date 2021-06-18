#include "../sche_base.h"
#ifndef _SJF_HPP_
#define _SJF_HPP_ 1
#include <iostream>
#include <vector>
class sjf : public Sched {
    heap<uint> queue;
    std::vector<uint> finish_list;

   public:
    sjf(uint slice, std::initializer_list<uint> const& list)
        : Sched(slice), queue(), finish_list() {
        loadtask(list);
    }
    virtual Sched& loadtask(std::initializer_list<uint> const& list) {
        for (auto&& it : list) {
            queue.push(it);
        }
        return *this;
    }
    virtual Sched& append(int timetake) {
        queue.push(timetake);
        return *this;
    }
    virtual Sched& process() {
        if (!empty()) {
            finish_list.emplace_back(queue.top());
            queue.pop();
        }
        return *this;
    }
    virtual bool empty() {
        return queue.empty();
    }
    virtual Sched& finish(bool show_detail) {
        while (!empty()) {
            process();
        }
        if (show_detail) {
            finish_show();
        }
    }
    void finish_show() {
        for (auto&& it : finish_list) {
            std::cout << it << ' ';
        }
        std::cout << std::endl;
    }
};
#endif  //_SJF_HPP_