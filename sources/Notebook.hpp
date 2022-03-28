
#ifndef NOTEBOOK
#define NOTEBOOK

#include <string>
#include "Direction.hpp"
#include <vector>
const int NUM_OF_COLUMNS = 100; // should be 100
const char EMPTY_PLACE = '_';
const char ERASE_PLACE = '~';
const int DEFULT_LENGTH = 10;
const int START_RANGE_OF_CHARS = 32;
const int END_RANGE_OF_CHARS = 126;
const int NUM_RANGE_OF_CHARS = 256;

namespace ariel{
    class Notebook{
        public: 
            std::vector<std::vector<std::vector<char>>> * note_mat;
            bool exist;
            Notebook(){
                this-> exist = true;
                this-> note_mat = new std::vector<std::vector<std::vector<char>>>();
            }
            ~Notebook(){
                delete this-> note_mat;
            }
            // void write(uint x,uint y, unsigned int z, Direction direct,const std::string &str);
            // static std::string read(uint x, uint y, uint z, Direction direct,uint length);
            // void erase(uint x,uint y, uint z, Direction direct, uint length);
            // void show(uint page);
            void write(int x,int y, int z, Direction direct,const std::string &str);
            std::string read(int x, int y, int z, Direction direct,int length) const;
            void erase(int x,int y, int z, Direction direct, int length) const;
            void show(int page) const;
        // private:
        //     void addpages(int x,int y, int z,Direction direct, int length,Notebook note_mat);

    };
}


#endif