#ifndef TOKENDISTRIBUTOR_H
#define TOKENDISTRIBUTOR_H

#include "tockens.h"


class tokenDistributor
{
public:
    explicit tokenDistributor(const string& lexema,
                              size_t line = 0,
                              size_t pos = 0);

    static tokenModel retunrTokenType(const string& lexema);

    static bool is_string(const string& current_lexeme);
    static bool is_char(const string& current_lexeme);
    static bool is_integer(const string& current_lexeme);
    static bool is_double(const string& current_lexeme);

    static string token_type_to_string(tokenModel input_type);

    void print();


    tokenModel type() const {return _type;}
    string lexeme() const   {return _lexeme;}
    size_t line() const     {return _line;}
    size_t pos() const      {return _pos;}

    void setType(const tokenModel& type) {_type = type;}
    void setLexeme(const string& lexeme) {_lexeme = lexeme;}
    void setLine(const size_t& line)     {_line = line;}
    void setPos(const size_t& pos)       {_pos = pos;}

private:
    tokenModel _type;
    string _lexeme;

    size_t _line;
    size_t _pos;
};

#endif // TOKENDISTRIBUTOR_H
