#include "user.hpp"

    void user:: set_name(std:: string name) {
        this -> name=name;
    }
    void user:: set_username(std:: string username) {
        this -> username=username;
        this -> link = "https://"+username;
    }
    void user:: set_bio(std:: string bio) {
        this -> bio=bio;
    }
    void user:: set_country(std:: string country) {
        this -> country=country;
    }
    
    void user:: set_birth(birth bd) {
        this -> bd.day = bd.day;
        this -> bd.month = bd.month;
        this -> bd.year = bd.year;
    }
    void user:: set_phone_number(long long int phone_number) {
        this -> phone_number = phone_number;
    }
    void user:: set_password(std:: string password) {
        this -> password = password;
    }
    void user:: set_header(unsigned int color) {
        switch (color)
        {
        case 1:
            this -> color = header::white;
            break;
        case 2:
            this -> color = header::red;
            break;
        case 3:
            this -> color = header::orange;
            break;
        case 4:
            this -> color = header::yellow;
            break;
        case 5:
            this -> color = header::green;
            break;
        case 6:
            this -> color = header::blue;
            break;
        case 7:
            this -> color = header::purple;
            break;
        case 8:
            this -> color = header::black;
            break;
        
        }
    }
    void user::add_comment(std:: string cmt){
        message temp;
        messages.push_back(temp);
        messages[messages.size()-1].set_comment(cmt);
    }
    void user:: delete_comment(unsigned int num){
        messages.erase(messages.begin() + (num-1) );
    }
    void user:: show_comments(int n){
        if (n==-1)
        {
            for (size_t i = 0; i < messages.size(); i++)
            {
                messages[i].show_comment();
            }
        }
        else
        {
            messages[n-1].show_comment();
        }
        
    }

    void user:: set_like(unsigned int num){
        messages[num-1].set_like();
    }
    void user:: set_dislike(unsigned int num1){
        messages[num1-1].set_dislike();
    }

    void user:: edit_comment(unsigned int edit, std:: string n) {
        messages[edit].set_comment(n);
    }

    std:: string user:: get_name() { return name;}
    std:: string user:: get_username() { return username;}
    std:: string user:: get_bio() { return bio;}
    std:: string user:: get_country() { return country;}
    std:: string user:: get_link() { return link;}
    birth user:: get_birth() { return bd;}
    long long int user:: get_phone_number() { return phone_number;}
    std:: string user:: get_password() { return password;}
    header user:: get_header() { return color;}