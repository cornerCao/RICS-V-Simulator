// utility.h 
//	Miscellaneous useful definitions, including debugging routines.
//
//	The debugging routines allow the user to turn on selected
//	debugging messages, controllable from the command line arguments
//	passed to Nachos (-d).  You are encouraged to add your own
//	debugging flags.  The pre-defined debugging flags are:
//
//	'+' -- turn on all debug messages
//   	't' -- thread system
//   	's' -- semaphores, locks, and conditions
//   	'i' -- interrupt emulation
//   	'm' -- machine emulation (USER_PROGRAM)
//   	'd' -- disk emulation (FILESYS)
//   	'f' -- file system (FILESYS)
//   	'a' -- address spaces (USER_PROGRAM)
//   	'n' -- network emulation (NETWORK)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef UTILITY_H
#define UTILITY_H

//#include "copyright.h"

// Miscellaneous useful routines

typedef void (*VoidFunctionPtr)(int arg); 
typedef void (*VoidNoArgFunctionPtr)(); 


// Include interface that isolates us from the host machine system library.
// Requires definition of bool, and VoidFunctionPtr
//#include "sysdep.h"				

// Interface to debugging routines.

extern void DebugInit(char* flags);	// enable printing debug messages

extern bool DebugIsEnabled(char flag); 	// Is this debug flag enabled?

extern void DEBUG (char flag, char* format, ...);  	// Print debug message 
							// if flag is enabled

//----------------------------------------------------------------------
// ASSERT
//      If condition is false,  print a message and dump core.
//	Useful for documenting assumptions in the code.
//
//	NOTE: needs to be a #define, to be able to print the location 
//	where the error occurred.
//----------------------------------------------------------------------
#define ASSERT(condition)                                                     \
    if (!(condition)) {                                                       \
        fprintf(stderr, "Assertion failed: line %d, file \"%s\"\n",           \
                __LINE__, __FILE__);                                          \
	fflush(stderr);							      \
        Abort();                                                              \
    }


#endif // UTILITY_H
