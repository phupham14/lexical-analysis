#ifndef LEXER_H
#define LEXER_H

#define MAX_TOKEN_LENGTH 100

typedef enum {
    PLUS, MINUS, TIMES, SLASH,
    EQU, NEQ, LSS, LEQ, GTR, GEQ,
    LPARENT, RPARENT, LBRACK, RBRACK,
    ASSIGN, SEMICOLON, COMMA, PERIOD, PERCENT,
    IDENT, NUMBER, KEYWORD, EOF_TOKEN, UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

void init_lexer(const char *filename);
Token get_token();
void close_lexer();

#endif
