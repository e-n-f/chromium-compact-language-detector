#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "encodings/compact_lang_det/compact_lang_det.h"
#include "encodings/compact_lang_det/ext_lang_enc.h"
#include "encodings/compact_lang_det/unittest_data.h"

// gcc -I. -L. -o example example.cc -lcld

int main(int argc, char **argv) {
    bool is_plain_text = true;
    bool is_reliable;

    char s[10000];

    while (fgets(s, 10000, stdin)) {
	char *cp = s;

	for (; *cp && !isspace(*cp); cp++)
	    ; /* name */
	for (; *cp && isspace(*cp); cp++)
	    ;

	for (; *cp && !isspace(*cp); cp++)
	    ; /* date */
	for (; *cp && isspace(*cp); cp++)
	    ;

	for (; *cp && !isspace(*cp); cp++)
	    ; /* time */
	for (; *cp && isspace(*cp); cp++)
	    ;

	for (; *cp && !isspace(*cp); cp++)
	    ; /* where */
	for (; *cp && isspace(*cp); cp++)
	    ;

	for (; *cp && !isspace(*cp); cp++)
	    ; /* url */
	for (; *cp && isspace(*cp); cp++)
	    ;

	for (; *cp && !isspace(*cp); cp++)
	    ; /* client */
	for (; *cp && isspace(*cp); cp++)
	    ;

        Language lang = CompactLangDet::DetectLanguage(0, cp, strlen(cp),
                                                       is_plain_text,
                                                       &is_reliable);
	
	char *c;
	for (c = s; c < cp; c++) {
	    putchar(*c);
	}
        printf("%c %s %s %s", is_reliable ? 'y' : 'n', LanguageCode(lang), LanguageName(lang), cp);
    }
}
