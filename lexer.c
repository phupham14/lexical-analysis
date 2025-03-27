#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_KEYWORDS 11

const char *keywords[MAX_KEYWORDS] = {"BEGIN", "END", "IF", "THEN", "WHILE", "DO", "VAR", "CONST", "CALL", "PROCEDURE", "PROGRAM"};

FILE *source_file;
char current_char;
int is_keyword(const char *str) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}

void advance() {
    current_char = fgetc(source_file);
}

void init_lexer(const char *filename) {
    source_file = fopen(filename, "r");
    if (!source_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    advance();
}

void close_lexer() {
    fclose(source_file);
}

Token make_token(TokenType type, const char *value) {
    Token token;
    token.type = type;
    strncpy(token.value, value, MAX_TOKEN_LENGTH);
    return token;
}

Token get_token() {
    while (isspace(current_char)) advance();

    if (current_char == EOF) return make_token(EOF_TOKEN, "EOF");

    if (isalpha(current_char)) {
        char buffer[MAX_TOKEN_LENGTH] = {0};
        int i = 0;
        while (isalnum(current_char)) {
            buffer[i++] = current_char;
            advance();
        }
        return is_keyword(buffer) ? make_token(KEYWORD, buffer) : make_token(IDENT, buffer);
    }

    if (isdigit(current_char)) {
        char buffer[MAX_TOKEN_LENGTH] = {0};
        int i = 0;
        while (isdigit(current_char)) {
            buffer[i++] = current_char;
            advance();
        }
        return make_token(NUMBER, buffer);
    }

    switch (current_char) {
        case '+': advance(); return make_token(PLUS, "+");
        case '-': advance(); return make_token(MINUS, "-");
        case '*': advance(); return make_token(TIMES, "*");
        case '/': advance(); return make_token(SLASH, "/");
        case '=': advance(); return make_token(EQU, "=");
        case '<':
            advance();
            if (current_char == '>') { advance(); return make_token(NEQ, "<>"); }
            if (current_char == '=') { advance(); return make_token(LEQ, "<="); }
            return make_token(LSS, "<");
        case '>':
            advance();
            if (current_char == '=') { advance(); return make_token(GEQ, ">="); }
            return make_token(GTR, ">");
        case '(': advance(); return make_token(LPARENT, "(");
        case ')': advance(); return make_token(RPARENT, ")");
        case '[': advance(); return make_token(LBRACK, "[");
        case ']': advance(); return make_token(RBRACK, "]");
        case ':':
            advance();
            if (current_char == '=') { advance(); return make_token(ASSIGN, ":="); }
            return make_token(UNKNOWN, ":");
        case ';': advance(); return make_token(SEMICOLON, ";");
        case ',': advance(); return make_token(COMMA, ",");
        case '.': advance(); return make_token(PERIOD, ".");
        case '%': advance(); return make_token(PERCENT, "%");
        default:
            advance();
            return make_token(UNKNOWN, "?");
    }
}
