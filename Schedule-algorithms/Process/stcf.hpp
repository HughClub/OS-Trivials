#include "../sche_base.h"
#ifndef _STCF_HPP_
#define _STCF_HPP_ 1

class stcf : public Sched {
   public:
    stcf(uint slice, std::initializer_list<uint> const& list)
        : Sched(slice) {
        loadtask(list);
    }
    virtual Sched& loadtask(std::initializer_list<uint> const& list);
    virtual Sched& append(int timetake);
    virtual Sched& process();
    virtual Sched& finish(bool show_detail);
};
#endif  //_STCF_HPP_