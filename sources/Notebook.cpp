
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>

using ariel::Direction;

using namespace std;

namespace ariel{
    void Notebook::write(int x,int y,int z, Direction direct,const string &str){
        unsigned int x1 = (unsigned int)x;
        unsigned int y1 = (unsigned int)y;
        unsigned int z1 = (unsigned int)z;
        for(int i = 0 ; i < NUM_RANGE_OF_CHARS ; i++){
            if(i < START_RANGE_OF_CHARS || i > END_RANGE_OF_CHARS){
                if (str.find(i) != std::string::npos) {

                // std::cout << "Character found" << std::endl;
                    throw std::out_of_range{"error"};
                }
            }
        }
        if (str.find('\n') != std::string::npos) {

                // std::cout << "Character found" << std::endl;
                    throw std::out_of_range{"error"};
        }
        if (str.find('~') != std::string::npos) {

                // std::cout << "Character found" << std::endl;
                    throw std::out_of_range{"error"};
        }
        int lines = 1;
        // note_mat->at(x1).size() <= y+(int)str.size() &&
        if(direct == Direction::Vertical){
            lines += y + (int)str.size();
        }
        else{
            lines += y;
        }
        if(exist){
            exist =false;
        }
        if(z + (int)str.size() > NUM_OF_COLUMNS && direct == Direction::Horizontal){
            throw std::out_of_range{"error"};
        }

        if(x >= note_mat->size()){
            int addelements = x - (int)note_mat->size()+1;
            for(int i = 0; i < addelements; i++){
                vector<vector<char>> page;
                for(int j = 0; j < lines; j++){
                    vector<char> line;
                    line.assign(NUM_OF_COLUMNS,'_');
                    page.push_back(line);
                }
                note_mat->push_back(page);
            }
        }
        if(y < lines){
            int addlines = lines - (int)note_mat->at(x1).size();
            for(int j = 0; j < addlines; j++){
                vector<char> line;
                line.assign(NUM_OF_COLUMNS,'_');
                note_mat->at(x1).push_back(line);
            }
        }
        if(direct == Direction::Vertical){
            for(unsigned int i = 0; i < (int)str.size(); ++i){
                if(note_mat->at(x1).at(y1+i).at(z1) != EMPTY_PLACE){
                    throw std::out_of_range{"error"};
                }
            }
        }
        else{
            for(unsigned int i = 0; i < (int)str.size(); ++i){
                if(note_mat->at(x1).at(y1).at(z1+i) != EMPTY_PLACE){
                    throw std::out_of_range{"error"};
                }
            } 
        }
        if(direct == Direction::Vertical){
            for(unsigned int i = 0; i < (int)str.size(); ++i){
                note_mat->at(x1).at(y1+i).at(z1) = str[i];
            }
        }
        else{
            for(unsigned int i = 0; i < (int)str.size(); ++i){
                note_mat->at(x1).at(y1).at(z1+i) = str[i];
            } 
        }
    }

    string Notebook::read(int x,int y,int z, Direction direct,int length) const{
        unsigned int x1 = (unsigned int)x;
        unsigned int y1 = (unsigned int)y;
        unsigned int z1 = (unsigned int)z;
        int lines = 1;
        if(direct == Direction::Vertical){
            lines += y + length+1;
        }
        else{
            lines = y;
        }
        //notebook.read(2, 1, 20, Direction::Horizontal, 30);
        if(x >= (int)note_mat->size()){
            int addelements = x - (int)note_mat->size()+1;
            for(int i = 0; i < addelements; i++){
                vector<vector<char>> page;
                for(int j = 0; j < lines; j++){
                    vector<char> line;
                    line.assign(NUM_OF_COLUMNS,EMPTY_PLACE);
                    page.push_back(line);
                }
                note_mat->push_back(page);
            }
        }
        if(y <= lines){
            int addlines = lines - (int)note_mat->at(x1).size()+1;
            for(int j = 0; j < addlines+2; j++){
                vector<char> line;
                line.assign(NUM_OF_COLUMNS,EMPTY_PLACE);
                note_mat->at(x1).push_back(line);
            }
        }

        string result;
        if(direct == Direction::Vertical){
            for(unsigned int i = 0; i < length; ++i){
                result+=note_mat->at(x1).at(y1+i).at(z1);
            }
        }
        else{
            for(unsigned int i = 0; i < length; ++i){
                result+=note_mat->at(x1).at(y1).at(z1+i);
            } 
        }

        return result;

    }

    void Notebook::erase(int x,int y,int z, Direction direct,int length) const{
        int lines = 0;
        unsigned int x1 = (unsigned int)x;
        unsigned int y1 = (unsigned int)y;
        unsigned int z1 = (unsigned int)z;
        if(direct == Direction::Vertical){
            lines += y + length;
        }
        else{
            lines += y;
        }
        if(x >= note_mat->size()){
            int addelements = x - (int)note_mat->size()+1;
            for(int i = 0; i < addelements; i++){
                vector<vector<char>> page;
                for(int j = 0; j < lines; j++){
                    vector<char> line;
                    line.assign(NUM_OF_COLUMNS,EMPTY_PLACE);
                    page.push_back(line);
                }
                note_mat->push_back(page);
            }
        }
        if(y <= lines){
            int addlines = lines - (int)note_mat->at(x1).size()+1;
            for(int j = 0; j < addlines; j++){
                vector<char> line;
                line.assign(NUM_OF_COLUMNS,EMPTY_PLACE);
                note_mat->at(x1).push_back(line);
            }
        }
        if(direct == Direction::Vertical){
            for(unsigned int i = 0; i < length; ++i){
                note_mat->at(x1).at(y1+i).at(z1) = ERASE_PLACE;
            }
        }
        else{
            for(unsigned int i = 0; i < length; ++i){
                note_mat->at(x1).at(y1).at(z1+i) = ERASE_PLACE;
            } 
        }
    }

    void  Notebook::show(int page) const{
        if(page >= note_mat->size()){
            int addelements = page - (int)note_mat->size()+1;
            for(int i = 0; i < addelements; i++){
                vector<vector<char>> page1;
                for(int j = 0; j < DEFULT_LENGTH; j++){
                    vector<char> line;
                    line.assign(NUM_OF_COLUMNS,EMPTY_PLACE);
                    page1.push_back(line);
                }
                note_mat->push_back(page1);
            }
        }
        unsigned int p = (unsigned int)page;
        int lengthpage = (int)note_mat->at(p).size();
        string s = to_string(lengthpage);
        int size = (int)s.size();
        int l = 0;
        for(unsigned int i = 0 ; i < note_mat->at(p).size(); ++i){
            int sp = size - (int)to_string(i).size();
            string spc = " ";
            for(int j = 0; j < sp ; j++){
                spc += " ";
            }
            cout << to_string(l) + ":" + spc;
            for(unsigned int j = 0; j < NUM_OF_COLUMNS; j++){
                cout << note_mat->at(p).at(i).at(j);
            }
            l++;
            cout << endl;
        }
    }
}

