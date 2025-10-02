#include <string>

class message
{
private:
    std:: string comment;
    unsigned int like=0;
    unsigned int dislike=0;
public:
    void set_like();
    void set_dislike();
    unsigned int get_likes();
    unsigned int get_dislikes();
    void set_comment(std:: string);
    void show_comment();
};
