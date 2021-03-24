#pragma once
#include "Direction.hpp"
using ariel::Direction;
#include <string>
#include <vector>

namespace ariel{

    class Board {
        public:
            Board();
            void post(unsigned int row, unsigned int col, Direction direc, std::string advertis);
            std::string read(unsigned int row, unsigned int col, Direction direc,int adv_len);
            void show();
    };
   
}
