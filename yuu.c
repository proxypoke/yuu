/* 
 * Yuu - A small UTF-8 de/encoder.
 *
 * Copywrong (c) 2012 slowpoke <proxypoke at lavabit dot com>
 *
 * Yuu is Free Software under the terms of the WTFPLv2.
 * See COPYING or head to http://sam.zoy.org/wtfpl/COPYING.
 *
 * Visit me at irc.datnode.net in #hacking
 *
 */

#include <stdio.h>
#include <math.h>

#include "yuu.h"

int bytetype(unsigned char c) {
	if (c < ASCII) {
		printf("%d - ASCII\n", c);
		return ASCII; }
	else if (c < CONT) {
		printf("%d - CONT\n", c);
		return CONT; }
	else if (c == 192 || c == 193) {
		/* 192 and 193 are invalid 2 byte sequences */
		printf("%d - INVALID\n", c);
		return INVALID; }
	else if (c < LEAD2) {
		printf("%d - LEAD2\n", c);
		return LEAD2; }
	else if (c < LEAD3) {
		printf("%d - LEAD3\n", c);
		return LEAD3; }
	else if (c < LEAD4) {
		printf("%d - LEAD4\n", c);
		return LEAD4; }
	else {
		printf("%d - INVALID\n", c);
		return INVALID; } }

int main(void) {
	//*
	for (int i = 0; i <= 255; ++i) {
		bytetype(i); }
	//*/
	return 0; }

void decode(char* unicode) {
	int	c
	,	cont		/* how many cont bytes are currently expected */
	,	result		/* where the result is built */
	;
	cont = result = 0;
	for ( ; (c = *unicode) != EOF ; ++unicode) {
		if (cont == 0) { 
			switch (bytetype(c)) {
				case ASCII:
					result = c;
					break;
				case LEAD2:
					cont = 1;
					result = c & (~LEAD2);
					break;
				case LEAD3:
					cont = 2;
					result = c & (~LEAD3);
					break;
				case LEAD4:
					cont = 3;
					result = c & (~LEAD4);
					break;
				default:
					/* either an unexpected CONT byte showed up
					 * or an invalid byte.
					 * TODO: Error handling
					 */
					printf("\nInvalid byte or unexpected CONT byte.\n");
					return; } }
		else {
			switch (bytetype(c)) {
				case CONT:
					result <<= 6; /* room for 6 more bits */
					result += c & (~CONT);
					--cont;
					break;
				default:
					/* There was something other than a CONT byte, either
					 * and invalid byte or and unexpected LEAD or ASCII byte
					 * TODO: Error handling
					 */
					printf("Invalid byte or unexpected non-CONT byte.\n");
					return; } }
		/* finally, write the finished byte sequence */
		if (cont == 0) {
			/* Outside valid Unicode */
			/* TODO: Error handling */
			if (result > 0x10FFFF) {
				printf("\nResult too large.\n");
				return; }

			/* 3 bytes */
			if (result > 0x10000) {
				putchar(result >> 16);
				result &= 0xFFFF; }
			/* 2 bytes */
			if (result > 0x100) {
				putchar(result >> 8);
				result &= 0xFF; }
			/* 1 byte */
			if (result > 0x1) {
				putchar(result); } } } }
