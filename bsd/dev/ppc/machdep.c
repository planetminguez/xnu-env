/*
 * Copyright (c) 2000-2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 1997 Apple Computer, Inc.  All rights reserved.
 * Copyright (c) 1992 NeXT Computer, Inc.  All rights reserved.
 *
 *
 * Machine dependent cruft.
 *
 * 27-Apr-1997  A.Ramesh at Apple 
 *
 *
 */

#include <mach/mach_types.h>
#include <mach/machine.h>
#include <sys/reboot.h>

int reboot_how;
extern struct tty	cons;
extern struct tty	*constty;		/* current console device */

extern int getchar(void);
extern int cngetc(void);
extern void cnputc(char);

#define putchar cnputc

int
getchar(void)
{
	int c;

	c = cngetc();
#if 0
	if (c == 0x1b)		/* ESC ? */
		call_kdp();
#endif

	if (c == '\r')
		c = '\n';
        cnputc(c);
	return c;
}

