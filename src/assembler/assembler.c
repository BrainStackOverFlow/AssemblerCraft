#include"assembler.h"

#include<ctype.h>

typedef struct Assembler {
	const char *src;
	int len, index;
	
	int currentLine;
} Assembler;

typedef enum TokenType {
	TOK_IDENTIFIER, TOK_INT, TOK_COMMA, TOK_EOF
} TokenType;

typedef struct Token {
	TokenType type;
	const char *src;
	int len;
} Token;

static Token asmcraft__next_tok(Assembler *s) {
	Token ret = {.src = &s->src[s->index], .len = 1}; /* len is one by default. */
	
	if(s->index == s->len) {
		ret.type = TOK_EOF;
		ret.len = 0;
		return ret;
	}
	
	if(isalpha(s->src[s->index])) {
		int i;
		for(i = s->index; i < s->len; i++) {
			if(!isalpha(s->src[i])) {
				break;
			}
		}
		
		ret.len = i - s->index;
		ret.type = TOK_IDENTIFIER;
	} else if(isdigit(s->src[s->index])) {
		int i;
		for(i = s->index; i < s->len; i++) {
			if(!isdigit(s->src[i])) {
				break;
			}
		}
		
		ret.len = i - s->index;
		ret.type = TOK_INT;
	} else if(isspace(s->src[s->index])) {
		int i;
		for(i = s->index; i < s->len; i++) {
			if(s->src[i] == '\n') {
				s->currentLine++;
			}
			
			if(!isspace(s->src[i])) {
				break;
			}
		}
		
		/* Ignore it, we have no use of whitespace. */
		s->index = i;
		return asmcraft__next_tok(s);
	} else {
		switch(s->src[s->index]) {
			case ',':
				ret.type = TOK_COMMA;
				break;
			case ';': /* Comment. */
				while(s->src[s->index] != '\n') s->index++;
				
				return asmcraft__next_tok(s);
			default:
				/* TODO: Better error handling! */
				printf("Unexpected character '%c' on line %i.\n", s->src[s->index], s->currentLine);
				break;
		}
	}
	
	s->index += ret.len;
	return ret;
}

void asmcraft_assemble_mem(const char *src, int len) {
	Assembler s = {src, len, .currentLine = 0};
	
	Token tok;
	while((tok = asmcraft__next_tok(&s)).type != TOK_EOF) {
		printf("Token of type %i: \"%.*s\".\n", tok.type, tok.len, tok.src);
	}
}
