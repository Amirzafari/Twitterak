//#include <string>
#include <vector>
#include "message.hpp"

struct birth
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

enum header {white=1, red, orange, yellow, green, blue, purple, black};


class user
{
private:
    std:: vector <message> messages;
    std:: string name;
    std:: string username;
    std:: string bio;
    std:: string country;
    std:: string link;
    birth bd;    
    long long int phone_number;
    std:: string password;
    header color;
    
public:
    void set_name(std:: string);
    void set_username(std:: string);
    void set_bio(std:: string);
    void set_country(std:: string);
    void set_birth(birth);
    void set_phone_number(long long int);
    void set_password(std:: string);
    void set_header(unsigned int);
    void set_like(unsigned int);
    void set_dislike(unsigned int);
    void edit_comment(unsigned int, std:: string);

    std:: string get_name();
    std:: string get_username();
    std:: string get_bio();
    std:: string get_country();
    std:: string get_link();
    birth get_birth();
    long long int get_phone_number();
    std:: string get_password();
    header get_header();
    void add_comment(std:: string);
    void delete_comment(unsigned int);
    void show_comments(int=-1);
};