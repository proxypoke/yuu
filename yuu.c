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
