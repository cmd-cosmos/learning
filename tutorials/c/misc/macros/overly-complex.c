// over complicating a basic program using macros 

#include <stdio.h>
#include <stdint.h>

#define WMSTIX_POSIXUNIXGNUMETER uint32_t
#define WINPROC_KILL 42
#define PROC_KILL_MESSAGE "hello world"
#define BUFFER_OUT printf
#define FORMAT_SPEC "%d\n"
#define PROG_ENTRY main
#define INTEGER_4_BYTES int
#define __global_ {
#define _global_exit__ }
#define STATEMENT_TERMINATOR ;
#define STRING_FORMAT_BUFFER_FLUSH_NEW_LINE "%s\n"

INTEGER_4_BYTES PROG_ENTRY()

__global_

    WMSTIX_POSIXUNIXGNUMETER POSIXPNEUMATOPHORE = WINPROC_KILL STATEMENT_TERMINATOR
    BUFFER_OUT(FORMAT_SPEC, WINPROC_KILL)STATEMENT_TERMINATOR
    BUFFER_OUT(STRING_FORMAT_BUFFER_FLUSH_NEW_LINE, PROC_KILL_MESSAGE)STATEMENT_TERMINATOR
    return 0;
    
_global_exit__