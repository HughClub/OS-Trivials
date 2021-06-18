#ifndef _SCHED_BASE_H
#define _SCHED_BASE_H 1
using uint = unsigned int;
#include <queue>
#include <string>

template <typename elem>
using heap = std::priority_queue<elem>;

class Sched {
   protected:
    uint timeslice;
    // heap<uint>queue;
   public:
    Sched(uint slice) : timeslice(slice) {}
    virtual Sched& loadtask(std::initializer_list<uint> const& list) = 0;
    /**
     * @brief a newly coming task with its time slice will take
     */
    virtual Sched& append(int timetake) = 0;
    /**
     * @brief process a timeslice and reschedule
     */
    virtual Sched& process() = 0;
    /**
     * @brief execute all tasks
     */
    virtual Sched& finish(bool show_detail) = 0;
    virtual bool empty() = 0;
};
#endif  //_SCHED_BASE_H