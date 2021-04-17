#include "TextBox.h"

TextBox::TextBox()
{
    current_size = 0;
    text = "";
    max_size = 15;
}

TextBox::~TextBox()
{

}

std::string TextBox::getText()
{
    return text;
}

void TextBox::addLetter( char let )
{
    if( current_size < max_size )
    {
        text += let;
        current_size ++;
    }
}

void TextBox::deleteLastLetter()
{
    if( current_size >= 1 )
    {
        current_size --;
        std::string tmp_str="";

        for( int i = 0; i < current_size; i++ )
        {
            tmp_str += text[i];
        }
        text = tmp_str;
    }
}





