#ifndef _SCHED_BASE_H
#define _SCHED_BASE_H 1
using uint=unsigned int;
class Sched{
    protected:
        uint timeslice;
    public:
        virtual Sched(uint slice):timeslice(slice){}
        virtual Sched& append(int timetake)=0;
        // think of the exec interface
};
#endif//_SCHED_BASE_H