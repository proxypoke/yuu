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
	if ((c >> 7) == ASCII) {
		printf("%d - ASCII\n", c);
		return ASCII; }
	else if ((c >> 6) == CONT) {
		printf("%d - CONT\n", c);
		return CONT; }
	else if ((c >> 5) == LEAD2) {
		/* 192 and 193 are invalid 2 byte sequences */
		if (c <= 193) {
			printf("%d - INVALID\n", c);
			return INVALID; }
		printf("%d - LEAD2\n", c);
		return LEAD2; }
	else if ((c >> 4) == LEAD3) {
		printf("%d - LEAD3\n", c);
		return LEAD3; }
	else if ((c >> 3) == LEAD4) {
		/* 245 to 253 are invalid 4 byte sequences */
		if (c >= 245) {
			printf("%d - INVALID\n", c);
			return INVALID; }
		printf("%d - LEAD4\n", c);
		return LEAD4; }
	else {
		printf("%d - INVALID\n", c);
		return INVALID; } }

int main(void) {
	for (int i = 0; i <= 255; ++i) {
		bytetype(i); }
	return 0; }
