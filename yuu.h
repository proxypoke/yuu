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

#define ASCII	0	/* An ASCII byte starts with 0 */
#define CONT	2	/* A continuation byte starts with the bits 10 */
					/* Lead bytes start with: */
#define LEAD2	6	/* 110 */
#define LEAD3	14	/* 1110 */
#define LEAD4	30	/* 11110 */

#define INVALID	-1	/* an invalid byte */

/* Get the byte type of a char.
 */
int bytetype(unsigned char c);
