#include "tokenDistributor.h"

tokenDistributor::tokenDistributor(const string& lexema, size_t line, size_t pos)
{
    _lexeme = lexema;
//   _type = which_token_type(lexeme);

    _line = line;
    _pos = pos;
}

tokenModel tokenDistributor::retunrTokenType(const string &lexema)
{
    if (lexema == "const")
        return tokenModel::CONST;

    // типы данных
    if (lexema == "int")
        return tokenModel::INT;
    if (lexema == "double")
        return tokenModel::DOUBLE;
    if (lexema == "bool")
        return tokenModel::BOOL;
    if (lexema == "void")
        return tokenModel::VOID;
    if (lexema == "char")
        return tokenModel::CHAR;
    if (lexema == "auto")
        return tokenModel::AUTO;

    // циклы
    if (lexema == "for")
        return tokenModel::FOR;
    if (lexema == "while")
        return tokenModel::WHILE;
    if (lexema == "do")
        return tokenModel::DO_WHILE;

    // операции с циклами
    if (lexema == "break")
        return tokenModel::BREAK;
    if (lexema == "continue")
        return tokenModel::CONTINUE;

    // операторы условия
    if (lexema == "if")
        return tokenModel::IF;
    if (lexema == "else")
        return tokenModel::ELSE;

    // операторы отношений
    if (lexema == ">")
        return tokenModel::GREATER;
    if (lexema == "<")
        return tokenModel::LESS;
    if (lexema == "<=")
        return tokenModel::LESS_EQUAL;
    if (lexema == ">=")
        return tokenModel::GREATER_EQUAL;

    if (lexema == "==")
        return tokenModel::EQUAL;
    if (lexema == "!=")
        return tokenModel::NOT_EQUAL;

    // логические операторы
    if (lexema == "&&")
        return tokenModel::AND;
    if (lexema == "||")
        return tokenModel::OR;
    if (lexema == "!")
        return tokenModel::EXCLAMATION;

    // математические операторы
    if (lexema == "+")
        return tokenModel::PLUS;
    if (lexema == "-")
        return tokenModel::MINUS;
    if (lexema == "*")
        return tokenModel::STAR;
    if (lexema == "/")
        return tokenModel::SLASH;
    if (lexema == "++")
        return tokenModel::INC;
    if (lexema == "--")
        return tokenModel::DEC;
    if (lexema == "^")
        return tokenModel::DEG;


    // скобки
    if (lexema == "{")
        return tokenModel::LBRA;
    if (lexema == "}")
        return tokenModel::RBRA;
    if (lexema == "(")
        return tokenModel::LPAR;
    if (lexema == ")")
        return tokenModel::RPAR;
    if (lexema == "[")
        return tokenModel::LSQR;
    if (lexema == "]")
        return tokenModel::RSQR;

    // assign
    if (lexema == "=")
        return tokenModel::ASSIGN;
    if (lexema == "+=")
        return tokenModel::ADD_ASSIGN;
    if (lexema == "-=")
        return tokenModel::SUB_ASSIGN;
    if (lexema == "*=")
        return tokenModel::MUL_ASSIGN;
    if (lexema == "/=")
        return tokenModel::DIV_ASSIGN;


    // функция
    if (lexema == "return")
        return tokenModel::RETURN;

    if (lexema == "procedure")
        return tokenModel::PROCEDURE;


    // выделение памяти
    if (lexema == "new")
        return tokenModel::NEW;
    if (lexema == "delete")
        return tokenModel::DELETE;


    // логические операторы
    if (lexema == "true")
        return tokenModel::TRUE;
    if (lexema == "false")
        return tokenModel::FALSE;


    if (lexema == "switch")
        return tokenModel::SWITCH;
    if (lexema == "case")
        return tokenModel::CASE;
    if (lexema == "default")
        return tokenModel::DEFAULT;

    // другие символы
    if (lexema == ";")
        return tokenModel::SEMICOLON;
    if (lexema == ":")
        return tokenModel::COLON;
    if (lexema == ",")
        return tokenModel::COMMA;
    if (lexema == ".")
        return tokenModel::POINT;
    if (lexema == "?")
        return tokenModel::QUESTION;
    if (lexema == "::")
        return tokenModel::ACCESS_OPERATOR;
    if (lexema == "&")
        return tokenModel::AMPERSAND;

    // комментарии
    if (lexema == "//")
        return tokenModel::LINE_COMMENT;
    if (lexema == "/*")
        return tokenModel::BLOCK_COMMENT_START;
    if (lexema == "*/")
        return tokenModel::BLOCK_COMMENT_END;

    if (lexema[0] == '#')
        return tokenModel::PREPROCESSOR_DIRECTIVE;

    if (is_integer(lexema))
        return tokenModel::INTEGER_CONST;

    if (is_double(lexema))
        return tokenModel::DOUBLE_CONST;

    if (is_string(lexema))
        return tokenModel::STRING_CONST;

    if (is_char(lexema))
        return tokenModel::CHAR_CONST;

    return tokenModel::IDENTIFIER;
}

bool tokenDistributor::is_string(const string &current_lexeme)
{
    return current_lexeme.front() == '"' && current_lexeme.back() == '"';
}

bool tokenDistributor::is_char(const string &current_lexeme)
{
    return current_lexeme.front() == '\'' && current_lexeme.back() == '\'';
}

bool tokenDistributor::is_integer(const string &current_lexeme)
{
    for (const auto& symbol : current_lexeme)
        if (symbol < '0' || symbol > '9')
            return false;
    return true;
}

bool tokenDistributor::is_double(const string &current_lexeme)
{
    bool point = false;

    for (const char& s : current_lexeme)
    {
        if (s == '.' && !point)
        {
            point = true;
            continue;
        }

        if (s == '.')
            return false;

        if (s < '0' || s > '9')
            return false;

    }

    return true;
}

string tokenDistributor::token_type_to_string(tokenModel input_type)
{
    switch (input_type)
    {
    case tokenModel::IDENTIFIER:
    {
        return "identifier";
    }
    case tokenModel::INTEGER_CONST:
    {
        return "integer constant";
    }
    case tokenModel::DOUBLE_CONST:
    {
        return "double constant";
    }
    case tokenModel::STRING_CONST:
    {
        return "string constant";
    }
    case tokenModel::CHAR_CONST:
    {
        return "char constant";
    }
    case tokenModel::TRUE:
    {
        return "true";
    }
    case tokenModel::FALSE:
    {
        return "false";
    }
    case tokenModel::CONST:
    {
        return "const";
    }
    case tokenModel::UNDEFINED:
    {
        return "undefined";
    }
    case tokenModel::INT:
    {
        return "int";
    }
    case tokenModel::DOUBLE:
    {
        return "double";
    }
    case tokenModel::BOOL:
    {
        return "bool";
    }
    case tokenModel::CHAR:
    {
        return "char";
    }
    case tokenModel::VOID:
    {
        return "void";
    }
    case tokenModel::AUTO:
    {
        return "auto";
    }
    case tokenModel::DO_WHILE:
    {
        return "do while";
    }
    case tokenModel::WHILE:
    {
        return "while";
    }
    case tokenModel::FOR:
    {
        return "for";
    }
    case tokenModel::BREAK:
    {
        return "break";
    }
    case tokenModel::CONTINUE:
    {
        return "continue";
    }
    case tokenModel::SWITCH:
    {
        return "switch";
    }
    case tokenModel::CASE:
    {
        return "case";
    }
    case tokenModel::DEFAULT:
    {
        return "default";
    }
    case tokenModel::IF:
    {
        return "if";
    }
    case tokenModel::ELSE:
    {
        return "else";
    }
    case tokenModel::LESS:
    {
        return "less";
    }
    case tokenModel::GREATER:
    {
        return "greater";
    }
    case tokenModel::LESS_EQUAL:
    {
        return "less and equal";
    }
    case tokenModel::GREATER_EQUAL:
    {
        return "greater and equal";
    }
    case tokenModel::EQUAL:
    {
        return "equal";
    }
    case tokenModel::NOT_EQUAL:
    {
        return "not equal";
    }
    case tokenModel::AND:
    {
        return "logic and";
    }
    case tokenModel::OR:
    {
        return "logic or";
    }
    case tokenModel::EXCLAMATION:
    {
        return "exclamation";
    }
    case tokenModel::PLUS:
    {
        return "plus";
    }
    case tokenModel::MINUS:
    {
        return "minus";
    }
    case tokenModel::STAR:
    {
        return "star";
    }
    case tokenModel::SLASH:
    {
        return "true";
    }
    case tokenModel::INC:
    {
        return "inc";
    }
    case tokenModel::DEC:
    {
        return "dec";
    }
    case tokenModel::LBRA:
    {
        return "lbra";
    }
    case tokenModel::RBRA:
    {
        return "rbra";
    }
    case tokenModel::LPAR:
    {
        return "lpar";
    }
    case tokenModel::RPAR:
    {
        return "rpar";
    }
    case tokenModel::LSQR:
    {
        return "lsqr";
    }
    case tokenModel::RSQR:
    {
        return "rsqr";
    }
    case tokenModel::ASSIGN:
    {
        return "assign";
    }
    case tokenModel::ADD_ASSIGN:
    {
        return "add assign";
    }
    case tokenModel::SUB_ASSIGN:
    {
        return "sun assign";
    }
    case tokenModel::MUL_ASSIGN:
    {
        return "mul assign";
    }
    case tokenModel::DIV_ASSIGN:
    {
        return "true";
    }
    case tokenModel::FUNCTION:
    {
        return "function";
    }
    case tokenModel::RETURN:
    {
        return "return";
    }
    case tokenModel::SEMICOLON:
    {
        return "semicolon";
    }
    case tokenModel::COLON:
    {
        return "colon";
    }
    case tokenModel::COMMA:
    {
        return "comma";
    }
    case tokenModel::POINT:
    {
        return "point";
    }
    case tokenModel::QUESTION:
    {
        return "question";
    }
    case tokenModel::AMPERSAND:
    {
        return "ampersand";
    }
    case tokenModel::LINE_COMMENT:
    {
        return "line comment";
    }
    case tokenModel::BLOCK_COMMENT_START:
    {
        return "block comment start";
    }
    case tokenModel::BLOCK_COMMENT_END:
    {
        return "block comment end";
    }
    case tokenModel::NEW:
    {
        return "new";
    }
    case tokenModel::DELETE:
    {
        return "delete";
    }
    case tokenModel::PREPROCESSOR_DIRECTIVE:
    {
        return "preprocessor directive";
    }
    case tokenModel::ACCESS_OPERATOR:
    {
        return "access operator";
    }

    default:
        return "";
    }
}

void tokenDistributor::print()
{
    cout << _lexeme << " with type: \"" << token_type_to_string(_type) << "\" " <<
            "\tline:" << _line <<
            "\tposition:" << _pos <<
            "\n";
}
