#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

class TextBox
{
    int current_size;
    int max_size;
    std::string text;
public:
    TextBox();
    ~TextBox();
    std::string getText();
    void addLetter( char let );
    void deleteLastLetter();
};

#endif // TEXTBOX_H
