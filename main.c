#include "lexer.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    init_lexer(argv[1]);
    Token token;
    do {
        token = get_token();
        printf("Token: %-10s Value: %s\n", 
            (token.type == PLUS) ? "PLUS" :
            (token.type == MINUS) ? "MINUS" :
            (token.type == TIMES) ? "TIMES" :
            (token.type == SLASH) ? "SLASH" :
            (token.type == EQU) ? "EQU" :
            (token.type == NEQ) ? "NEQ" :
            (token.type == LSS) ? "LSS" :
            (token.type == LEQ) ? "LEQ" :
            (token.type == GTR) ? "GTR" :
            (token.type == GEQ) ? "GEQ" :
            (token.type == LPARENT) ? "LPARENT" :
            (token.type == RPARENT) ? "RPARENT" :
            (token.type == LBRACK) ? "LBRACK" :
            (token.type == RBRACK) ? "RBRACK" :
            (token.type == ASSIGN) ? "ASSIGN" :
            (token.type == SEMICOLON) ? "SEMICOLON" :
            (token.type == COMMA) ? "COMMA" :
            (token.type == PERIOD) ? "PERIOD" :
            (token.type == PERCENT) ? "PERCENT" :
            (token.type == IDENT) ? "IDENT" :
            (token.type == NUMBER) ? "NUMBER" :
            (token.type == KEYWORD) ? "KEYWORD" :
            (token.type == EOF_TOKEN) ? "EOF" :
            "UNKNOWN",
            token.value);
    } while (token.type != EOF_TOKEN);

    close_lexer();
    return 0;
}
