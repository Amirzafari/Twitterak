#include <string>
#include <vector>
#include "user.hpp"

class Twitterak
{
private:
    std:: string cmnd;
    std:: vector <user> users;
    int  acc=-1;
public:
    Twitterak();
    void run();
    void help();
    void login();
    void signup();
    void edit(unsigned int);
    void exit();
};