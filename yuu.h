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

/* the respective byte types are always smaller
 * than their representative values, not accounting
 * for invalid bytes
 */
#define ASCII	128
#define CONT	192

#define LEAD2	224
#define LEAD3	240
#define LEAD4	245

#define INVALID -1

/* Get the byte type of a char.
 */
int bytetype(unsigned char c);
