#pragma once

#define max_child_num 26

struct trieNode {
    trieNode *next[max_child_num];
    bool is_end;
    trieNode():is_end(false){
        for ( auto &i : next )
            i = nullptr;
    }
};

class trieTree {

};