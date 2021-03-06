/*
 * File:         helpers.h
 * Author:       Mike Frysinger <michael.frysinger@analog.com>
 * Description:  some common utility functions
 * Modified:     Copyright 2006-2008 Analog Devices Inc.
 * Bugs:         Enter bugs at http://blackfin.uclinux.org/
 * Licensed under the GPL-2, see the file COPYING in this dir
 */

#ifndef __HELPERS_H__
#define __HELPERS_H__

#include "headers.h"

#ifndef VERSION
# define VERSION "svn"
#endif

extern int force, verbose, quiet;

extern const char *argv0;

#define warn(fmt, args...) \
	fprintf(stderr, "%s: " fmt "\n", argv0 , ## args) 
#define warnf(fmt, args...) warn("%s(): " fmt, __FUNCTION__ , ## args)
#define warnp(fmt, args...) warn(fmt ": %s" , ## args , strerror(errno))
#define _err(wfunc, fmt, args...) \
	do { \
		wfunc(fmt, ## args); \
		exit(EXIT_FAILURE); \
	} while (0)
#define err(fmt, args...) _err(warn, fmt, ## args)
#define errf(fmt, args...) _err(warnf, fmt, ## args)
#define errp(fmt, args...) _err(warnp, fmt , ## args)


void *xmalloc(size_t);
void *xrealloc(void *, size_t);
char *xstrdup(const char *);
int parse_bool(const char *);
size_t parse_int_hex(const char *);
ssize_t read_retry(int, void *, size_t);

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#endif
