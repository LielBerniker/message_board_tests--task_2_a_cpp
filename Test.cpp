/**
 * AUTHOR: liel berniker
 * 
 */

#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <stdlib.h> 
#include <ctime>
#include <limits>
 
     const int TEN = 10;
    const int ZERO = 0;
    const int ONE = 1;
    const int TWO = 2;
    const int THEREE = 3;
    const int FOUR = 4;
    const int FIVE = 5;
    const int SIX = 6;
    const int SEVEN = 7;
    const int EIGHT = 8;
    const int NINE = 9;
    const int RAND_FOR = 2147483600;
    const std::vector <std::string> arr {"mom","dad","grandad","grandmom","aunt","uncle","cousin","son","daughter","__________"};


TEST_CASE("good post method tests") {

   ariel::Board board;
   std::srand((unsigned)std::time(NULL));
   unsigned int row =0;
   unsigned int col = 0;
   int i=0;

//
// test insert of word in differnt rows in the board Horizontal
//
   for (; i < TEN ; i++)
   {
	row = std::rand()%RAND_FOR;
	board.post(row,col,ariel::Direction::Horizontal,arr.at(ZERO));
 CHECK(board.read(row,col,ariel::Direction::Horizontal,THEREE) == arr.at(ZERO));
   }

//
// test insert of word in differnt rows in the board vertical
//
   for (; i < TEN ; i++)
   {
	row = std::rand()%RAND_FOR;
	board.post(row,col,ariel::Direction::Vertical,arr.at(ZERO));
 CHECK(board.read(row,col,ariel::Direction::Vertical,THEREE) == arr.at(ZERO));
   }

   row = 0;

//
// test insert of word in differnt coloms in the board Vertical
// 
   for ( i = 0; i < TEN ; i++)
   {
	col = std::rand()%RAND_FOR;
	board.post(row,col,ariel::Direction::Vertical,arr.at(ONE));
 CHECK(board.read(row,col,ariel::Direction::Vertical,THEREE) == arr.at(ONE));
   }

  //
 // test insert of word in differnt coloms in the board horizontal
//  
   for ( i = 0; i < TEN ; i++)
   {
	
	col = std::rand()%RAND_FOR;
	board.post(row,col,ariel::Direction::Horizontal,arr.at(ONE));
 CHECK(board.read(row,col,ariel::Direction::Horizontal,THEREE) == arr.at(ONE));
   }

  //
 // test insert of differt words in the board Horizontal
//
   row =0;
   col = 0;
   size_t word_pos=0;
   int word_size = 0;
   
   for (i = 0; i < TEN ; i++)
   {
	word_pos = rand()%TEN;
	word_size = (int)arr.at(word_pos).length();
	board.post(row,col,ariel::Direction::Horizontal,arr.at(word_pos));
   CHECK(board.read(row,col,ariel::Direction::Horizontal,word_size) ==arr.at(word_pos));
   }

     //
    // test insert of differt words in the board vertical
   //
   for (i = 0; i < TEN ; i++)
   {
	word_pos = rand()%TEN;
	word_size = (int)arr.at(word_pos).length();
	board.post(row,col,ariel::Direction::Vertical,arr.at(word_pos));
   CHECK(board.read(row,col,ariel::Direction::Vertical,word_size) == arr.at(word_pos));
   }

   // initalize new board
ariel::Board board_2;

//
// test post part of word override in post, horizontal for vertical
//
     row = 0;
     col = 0;
   board.post(row,col,ariel::Direction::Vertical,arr.at(ZERO));
   CHECK(board_2.read(row,col,ariel::Direction::Horizontal,THEREE) == "m__");
   board.post(row,col,ariel::Direction::Vertical,arr.at(NINE));

//
// test post part of word override in post, vertical for horizontal 
//
     board.post(row,col,ariel::Direction::Horizontal,arr.at(ZERO));
   CHECK(board_2.read(row,col,ariel::Direction::Vertical,THEREE) == "m__");
   board.post(row,col,ariel::Direction::Horizontal,arr.at(NINE));

//
// test post full word override , vertical with randoom rows and cols
//
    for (i = 0; i < TEN ; i++)
   {
    row = rand()%RAND_FOR;
    col = rand()%RAND_FOR;
     board.post(row,col,ariel::Direction::Vertical,arr.at(TWO));
   CHECK(board_2.read(row,col,ariel::Direction::Vertical,SEVEN) == arr.at(TWO));
    board.post(row,col,ariel::Direction::Vertical,arr.at(THEREE));

    CHECK_FALSE(board_2.read(row,col,ariel::Direction::Vertical,SEVEN) == arr.at(TWO));
    CHECK(board_2.read(row,col,ariel::Direction::Vertical,EIGHT) == arr.at(THEREE));
   
   }

//
// test post full word override , horizontal with randoom rows and cols
//
    for (i = 0; i < TEN ; i++)
   {
    row = rand()%RAND_FOR;
    col = rand()%RAND_FOR;
     board.post(row,col,ariel::Direction::Horizontal,arr.at(TWO));
   CHECK(board_2.read(row,col,ariel::Direction::Horizontal,SEVEN) == arr.at(TWO));
    board.post(row,col,ariel::Direction::Horizontal,arr.at(THEREE));

    CHECK_FALSE(board_2.read(row,col,ariel::Direction::Horizontal,SEVEN) == arr.at(TWO));
    CHECK(board_2.read(row,col,ariel::Direction::Horizontal,EIGHT) == arr.at(THEREE));
   
   }

}
TEST_CASE("good read method tests")
{

ariel::Board board_3;
   std::srand((unsigned)std::time(NULL));
   unsigned int row =0;
   unsigned int col = 0;
   int i=0;
   size_t word_pos=0;
   int word_size = 0;
//
// test empty board vertical
//

     for (i = 0; i < TEN ; i++)
   {
    row = rand()%RAND_FOR;
    col = rand()%RAND_FOR;
	
   CHECK(board_3.read(row,col,ariel::Direction::Vertical,TEN) == "__________");
   }

//
// test empty board Horizontal
//
     for (i = 0; i < TEN ; i++)
   {
    row = rand()%RAND_FOR;
    col = rand()%RAND_FOR;
	
   CHECK(board_3.read(row,col,ariel::Direction::Horizontal,TEN) == "__________");
   }

//
// test read of differt words in the board vertical , with randoom of rows and cols
//
   for (i = 0; i < TEN ; i++)
   {
    row = rand()%RAND_FOR;
    col = rand()%RAND_FOR;
	word_pos = rand()%TEN;
	word_size = (int)arr.at(word_pos).length();
	board_3.post(row,col,ariel::Direction::Vertical,arr.at(word_pos));
   CHECK(board_3.read(row,col,ariel::Direction::Vertical,word_size) == arr.at(word_pos));
    CHECK_FALSE(board_3.read(row,col,ariel::Direction::Horizontal,word_size) == arr.at(NINE));
   }


//
// test read of differt words in the board horizontal , with randoom of rows and cols
//
   for (i = 0; i < TEN ; i++)
   {
    row = rand()%RAND_FOR;
    col = rand()%RAND_FOR;
	word_pos = rand()%TEN;
	word_size = (int)arr.at(word_pos).length();
	board_3.post(row,col,ariel::Direction::Horizontal,arr.at(word_pos));
   CHECK(board_3.read(row,col,ariel::Direction::Horizontal,word_size) == arr.at(word_pos));
   CHECK_FALSE(board_3.read(row,col,ariel::Direction::Horizontal,word_size) == arr.at(NINE));
   }
}


TEST_CASE("Bad post code") {

    ariel::Board board_4;
   std::srand((unsigned)std::time(NULL));
   unsigned int row =4294967294;
   unsigned int col = 4294967294;
   int i=0;
   size_t word_pos=0;
   int word_size = 0;

//
// test post of differt words in the max unsigned int location horizontal 
//
   for (i = 0; i < TEN ; i++)
   {
	word_pos = rand()%TEN;
	word_size = (int)arr.at(word_pos).length();
	CHECK_THROWS(board_4.post(row,col,ariel::Direction::Horizontal,arr.at(word_pos)));

   }

//
// test post of differt words in the max unsigned int location vertical
//
   for (i = 0; i < TEN ; i++)
   {
	word_pos = rand()%TEN;
	word_size = (int)arr.at(word_pos).length();
	CHECK_THROWS(board_4.post(row,col,ariel::Direction::Vertical,arr.at(word_pos)));

   }
}




