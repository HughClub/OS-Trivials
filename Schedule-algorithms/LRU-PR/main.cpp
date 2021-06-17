#include"LRU.hpp"
int main(){
    LRU_PR<int> queue(3);
    int data[]={7,0,1,2,0,3,4,2,3,0,3,2,1,2,0,1,7,0,1};
    for(int i:data){
        std::cout<<"update:"<<i<<"|";
        queue.Update(i,std::cout,true);
    }
    return 0;
}