#include "message.hpp"
#include <iostream>

    void message:: set_like(){
        like++;
    }
    void message:: set_dislike(){
        dislike++;
    }
    unsigned int message:: get_likes() {return like;}
    unsigned int message:: get_dislikes() {return dislike;}
    void message:: set_comment(std:: string com){
        comment = com;
    }
    void message:: show_comment(){
        std:: cout << comment  << "\nlikes:" << like << "\t\tdislike:" << dislike << std:: endl;
    }