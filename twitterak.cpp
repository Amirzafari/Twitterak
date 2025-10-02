#include "twitterak.hpp"
#include <iostream>
#include <cstring>

Twitterak::Twitterak()
{
    std:: cout << "Welcome to twitterak,\nIf you need any help please use \"help\" command ;)" << std::endl;
    std:: cout << "help\nlogin\nsignup\nedit\nexit" << std::endl;
    //std:: cout << "> ";
    //std:: cin  >> cmnd;
}

void Twitterak::run(){
    std:: string temp;
    while (1)
    {
        if (acc != -1)
        {
            std:: cout << "> " << users[acc].get_username() ;
        }
        std:: cout << "> ";
        getline (std:: cin, cmnd);
        temp = cmnd.substr(0,4);
        if ( temp == "help")
            help();

        temp = cmnd.substr(0,7);
        if (temp == "profile")
        {
            temp = cmnd.substr(8,cmnd.size()-8);
            if (temp.size() > 1)
            {
                for (size_t i = 0; i < users.size(); i++)
                {
                    if (temp == users[i].get_username())
                    {
                        std:: cout << users[i].get_username() << ":\n";
                        std:: cout << "name: " << users[i].get_name() << std:: endl;
                        std:: cout << "biography: " << users[i].get_bio() << std:: endl;
                        std:: cout << "birth date: " << users[i].get_birth().year << "/" <<users[i].get_birth().month << "/" << users[i].get_birth().day << std:: endl;
                        std:: cout << "country: " << users[i].get_country() << std:: endl;
                        std:: cout << "link: " << users[i].get_link() << std:: endl;
                        break;
                    }
                }
                
            }
            else
            {
                std:: cout << users[acc].get_username() << ":\n";
                std:: cout << "name: " << users[acc].get_name() << std:: endl;
                std:: cout << "biography: " << users[acc].get_bio() << std:: endl;
                std:: cout << "birth date: " << users[acc].get_birth().year << "/" <<users[acc].get_birth().month << "/" << users[acc].get_birth().day << std:: endl;
                std:: cout << "country: " << users[acc].get_country() << std:: endl;
                std:: cout << "link: " << users[acc].get_link() << std:: endl;
                std:: cout << "phone number: " << users[acc].get_phone_number() << std:: endl;
            }
            
        }
        temp = cmnd.substr(0,2);
        if ( temp == "me")
        {
            std:: cout << users[acc].get_username() << ":\n";
            std:: cout << "name: " << users[acc].get_name() << std:: endl;
            std:: cout << "biography: " << users[acc].get_bio() << std:: endl;
            std:: cout << "birth date: " << users[acc].get_birth().year << "/" <<users[acc].get_birth().month << "/" << users[acc].get_birth().day << std:: endl;
            std:: cout << "country: " << users[acc].get_country() << std:: endl;
            std:: cout << "link: " << users[acc].get_link() << std:: endl;
            std:: cout << "phone number: " << users[acc].get_phone_number() << std:: endl;
        }
        temp = cmnd.substr(0,5);
        if ( temp == "tweet")
        {
            temp = cmnd.substr(5,cmnd.size()-5);
            users[acc].add_comment(temp);
        }
        temp = cmnd.substr(0,4);
        if ( temp == "like")
        {
            temp = "";
            for (size_t i = cmnd.find("@") ; cmnd[i]!= ':' && i < cmnd.size()  ; i++)
            {
                temp = temp + cmnd[i]; 
            }
                for (size_t i = 0; i < users.size(); i++)
                {
                    if (temp == users[i].get_username())
                    {
                        temp = cmnd.substr(cmnd.find(":")+1);
                        int num1 = std:: stoi(temp);
                        users[i].set_like(num1);
                    }
                }
        }
        temp = cmnd.substr(0,7);
        if ( temp == "dislike")
        {   
            temp = "";
            for (size_t i = cmnd.find("@") ; cmnd[i]!= ':' && i < cmnd.size()  ; i++)
            {
                temp = temp + cmnd[i]; 
            }
                for (size_t i = 0; i < users.size(); i++)
                {
                    if (temp == users[i].get_username())
                    {
                        temp = cmnd.substr(cmnd.find(":")+1);
                        int num1 = std:: stoi(temp);
                        users[i].set_dislike(num1);
                    }
                }
        }
        else if (cmnd[0] == '@')
        {
            for (size_t i = 0; i < users.size(); i++)
            {
                if (cmnd == users[i].get_username())
                {
                    users[i].show_comments();
                    break;
                }
            }
        }
        else if (cmnd == "login" && acc == -1)
            login();
        else if (cmnd == "signup" && acc == -1)
            signup();
        temp = cmnd.substr(0,4);
        if (cmnd == "edit")
        {
            temp = cmnd.substr(cmnd.find("tweet "));
            int num1 = std:: stoi(temp);
            edit(num1);
        }        
        else if (cmnd == "logout")
            acc = -1;
        else if (cmnd == "exit" || cmnd == "q" || cmnd == "quit")
        {
            exit();
            break;
        }

    }
}

void Twitterak::help(){
    std:: cout << "login: you can use this command to login to your account" << std::endl;
    std:: cout << "signup: if you want to create an account, you can use this command " << std::endl;
    std:: cout << "edit: with this icon you change your profile.  for example (name , country , username , password , ...) " << std::endl;
    std:: cout << "exit: this icon will help you to leave the app." << std:: endl;
}

void Twitterak::login(){
    std:: string temp;
    unsigned int acnum;
    std:: cout << "Username: ";
    std:: cin >> temp;
    if (temp[0] != '@')
    {
        temp = '@' + temp;
    }
    
    for (int i = 0; i < users.size(); i++)
    {
        if (temp == users[i].get_username())
        {
            acnum = i;
            break;
        }   
        else if (i == users.size()-1) {
            std:: cout << "! invalid username. try again: ";
            std:: cin >> temp;
            i = -1; 
        }
    }
    std:: cout << "Password: ";
    std:: cin >> temp;
    while (1)
    {
        if (users[acnum].get_password() == temp) {
            std:: cout << "* welcome " << users[acnum].get_name() << "." << std:: endl;
            break;
        }
        else
        {
            std:: cout << "! invalid password. try again: ";   
            std:: cin >> temp;
        }
    }
    acc = acnum;
}

void Twitterak::signup(){
    user temp;
    users.push_back(temp);
    std:: string temp2;
    long long int phone;
    birth br;
    unsigned int backGround;

    std:: cout << "enter your name pls: ";
    std:: cin >> temp2;
    users[users.size()-1].set_name(temp2);
    std:: cout << "enter username: ";
    std:: cin >> temp2;
    if (temp2[0] != '@')
    {
        temp2 = '@' + temp2;
    }
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].get_username() == temp2)
        {
            std:: cout << "! this username is already taken. enter another one: ";
            std:: cin >> temp2;
            if (temp2[0] != '@')
            {
                temp2 = '@' + temp2;
            }
            i = -1;
        }
    }
    users[users.size()-1].set_username(temp2);
    std:: cout << "enter password: ";
    std:: cin >> temp2;
    users[users.size()-1].set_password(temp2);

    std:: cout << "enter your country: ";
    std:: cin >> temp2;
    users[users.size()-1].set_country(temp2);

    getchar();

    std:: cout << "enter your biography: ";
    getline(std:: cin,temp2);
    users[users.size()-1].set_bio(temp2);

    std:: cout << "enter phone number: ";
    std:: cin >> phone;
    users[users.size()-1].set_phone_number(phone);

    std:: cout << "enter your birthday\nday: ";
    std:: cin >> br.day;
    std:: cout << "\nmonth: ";
    std:: cin >> br.month;
    std:: cout << "\nyear: ";
    std:: cin >> br.year;
    users[users.size()-1].set_birth(br);

    std:: cout << "choose your header color (1:white, 2:red, 3:orange, 4:yellow, 5:green, 6:blue, 7:purple, 8:black): ";
    std:: cin >> backGround;
    while (backGround < 1 || backGround > 8)
    {
        std:: cout << "invalid color. enter again: ";
        std:: cin >> backGround;
    }
    users[users.size()-1].set_header(backGround);
    
    acc = users.size()-1;
}

void Twitterak::edit(unsigned int num){
    std:: cout << num << ": ";
    users[acc].show_comments(num);
    std::string temp;
    std:: cout << " Enter your new text for tweet " << num << ":";
    getline(std:: cin, temp);
    users[acc].edit_comment(num, temp);
}

void Twitterak::exit(){
    if (acc==-1)
        return;
    std:: string temp;

    do
    {
        std:: cout << "1: delete account.\n2: logout account.\n> ";
        getline(std:: cin, temp);
    } while (temp != "delete account" || temp != "logout account");
    
    if (temp == "delete account" )
    {
        char ans;
        do
        {
            std:: cout << "? this operation cannot be reverset in any way. are you sure? (y/n): ";
            std:: cin >> ans;
        } while (ans != 'y' || ans != 'n');
        
        if (ans == 'y')
        {
            users.erase(users.begin() + acc);
        }
        

    }
    
    acc = -1;
}