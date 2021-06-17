#ifndef _LRU_PR_HPP
#define _LRU_PR_HPP 1
#include <iostream>
#include <list>
#include <unordered_map>

using IterMap = std::unordered_map<int, std::list<int>::iterator>;

template <typename DataType = int>
class LRU_PR {                         // list for table
    std::size_t Capability;         // set the size limit
    std::list<DataType> LastTable;  // i.e. Page Table here
    std::unordered_map<DataType, typename std::list<DataType>::iterator> TableMap;

   public:
    LRU_PR(std::size_t cap) : Capability(cap) {}
    std::ostream& ShowTable(std::ostream& StdOut) {
        for (auto&& it : LastTable) {
            StdOut << it << ' ';
        }
        return StdOut << std::endl;
    }
    /**
     * @brief update Table after access
     * @return the replaced one
     *          or itself if no replacement
     * @param CallValue the newest used one
    */
    DataType Update(DataType const& CallValue) {
        if (LastTable.size() < this->Capability) {  // not full
            this->LastTable.emplace_front(CallValue);
            return CallValue;
        } else {
            try {
                auto iter = TableMap.at(CallValue);
                // Update the Access Table
                LastTable.erase(iter);               // erase the old one
                LastTable.emplace_front(CallValue);  // push the new one
                iter = LastTable.begin();            // update the iterator
                return CallValue;
            } catch (std::out_of_range const&) {
                // Replacement Require
                const DataType& back = LastTable.back();
                LastTable.pop_back();  // pop the unneeded
                LastTable.emplace_front(CallValue);
                TableMap[CallValue] = LastTable.begin();  // update the new value
                TableMap.erase(back);                     // remove the old value
                return back;
            }
        }
    }
    DataType Update(DataType const& CallValue, std::ostream& ShowIfReplace, bool step = false) {
        DataType result = Update(CallValue);
        if (step || CallValue != result)
            ShowTable(ShowIfReplace);
        return result;
    }
};

template <typename DataType = int>
std::ostream& operator<<(std::ostream& StdOut, LRU_PR<DataType> const& lru) {
    return lru.ShowTable(StdOut);
}
#endif  //LRU_PR_HPP
