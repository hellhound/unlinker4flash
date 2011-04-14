/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical 
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
** ---------------------------------------------------------------------------*/
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

static int (*unlinkSurrogate)(const char* s) = NULL;

int unlink(const char *pathname)
{
    if (unlinkSurrogate == NULL)
        unlinkSurrogate = dlsym(RTLD_NEXT, "unlink");
    return strstr(pathname , "Flash") != NULL || strstr(pathname, "f_") ?
        0 : unlinkSurrogate(pathname);
}
