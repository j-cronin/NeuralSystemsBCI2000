/*
 * @(#)mat.h    generated by: makeheader 4.21  Mon Aug 16 03:05:43 2004
 *
 *		built from:	../../src/include/copyright.h
 *				../../src/include/pragma_interface.h
 *				./fmatapi.cpp
 *				./fmatapiv5.cpp
 *				./matapi.cpp
 *				./matapiv5.cpp
 *				./matlvl4.cpp
 *				./matlvl5.cpp
 *				matdbg.h
 */

#ifndef mat_h
#define mat_h


/*
 * Copyright 1984-2003 The MathWorks, Inc.
 * All Rights Reserved.
 */



/* Copyright 2003 The MathWorks, Inc. */

/*
 * Prevent g++ from making copies of vtable and typeinfo data
 * in every compilation unit.  By allowing for only one, we can
 * save space and prevent some situations where the linker fails
 * to coalesce them properly into a single entry.
 *
 * References:
 *    http://gcc.gnu.org/onlinedocs/gcc/Vague-Linkage.html#Vague%20Linkage
 *    http://gcc.gnu.org/onlinedocs/gcc/C---Interface.html
 */

#ifdef __cplusplus
#  ifdef GLNX86
#    pragma interface
#  endif
#endif



#include <stdio.h>


#include "matrix.h"


typedef struct MATFile_tag MATFile;

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Allocate and initialize a MATFile structure for a file "filename".
 * file "filename" must already have been fopened with a mode corresponding
 * to "mode" ("r" == "rb", "w" == "w+b", "u" == "r+b"), and the result
 * of that fopen must be passed in as "fp".
 *
 * WARNING:
 * THIS FILE IS FOR INTERNAL MATHWORKS USE ONLY.  IT IS AN UNDOCUMENTED
 * FUNCTION, AND MAY AT ANY TIME BE REMOVED FROM THE MAT API.
 */
extern MATFile * matCreateMATFile(const char * filename, FILE *fp, const char * mode);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/* 
 * Open a MAT-file "filename" using mode "mode".  Return
 * a pointer to a MATFile for use with other MAT API functions.
 *
 * Current valid entries for "mode" are
 * "r"  == read only.
 * "w"  == write only (deletes any existing file with name <filename>).
 * "w4" == as "w", but create a MATLAB 4.0 MAT-file.
 * "u"  == update.  Read and write allowed, existing file is not deleted.
 * 
 * Return NULL if an error occurs.
 */
extern MATFile * matOpen(const char *filename, const char * mode);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Close a MAT-file opened with matOpen.
 *
 * Return zero for success, EOF on error.
 */
extern int matClose(MATFile *pMF);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Return the ANSI C FILE pointer obtained when the MAT-file was opened.
 */
extern FILE * matGetFp(MATFile *pMF);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Write array value with the specified name to the MAT-file, deleting any 
 * previously existing variable with that name in the MAT-file.
 *
 * Return zero for success, nonzero for error.
 */
extern int matPutVariable(
		   MATFile * pMF, 
		   const char * name,
		   const mxArray * pA
		   );
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Write array value with the specified name to the MAT-file pMF, deleting any 
 * previously existing variable in the MAT-file with the same name.
 *
 * The variable will be written such that when the MATLAB LOAD command 
 * loads the variable, it will automatically place it in the 
 * global workspace and establish a link to it in the local
 * workspace (as if the command "global <varname>" had been
 * issued after the variable was loaded.)
 *
 * Return zero for success, nonzero for error.
 */
extern int matPutVariableAsGlobal(
			   MATFile * pMF, 
			   const char * name,
			   const mxArray * pA
			   );
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Read the array value for the specified variable name from a MAT-file.
 *
 * Return NULL if an error occurs.
 */
extern mxArray * matGetVariable(
			 MATFile * pMF, 
			 const char * name
			 );
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/* 
 * Read the next array value from the current file location of the MAT-file
 * pMF.  This function should only be used in conjunction with 
 * matOpen and matClose.  Passing pMF to any other API functions
 * will cause matGetNextVariable() to work incorrectly.
 *
 * Return NULL if an error occurs.
 */
extern mxArray * matGetNextVariable(MATFile *pMF, const char **nameptr);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Read the array header of the next array value in a MAT-file.  
 * This function should only be used in conjunction with 
 * matOpen and matClose.  Passing pMF to any other API functions
 * will cause matGetNextVariableInfo to work incorrectly.
 * 
 * See the description of matGetVariableInfo() for the definition
 * and valid uses of an array header.
 *
 * Return NULL if an error occurs.
 */ 
extern mxArray * matGetNextVariableInfo(MATFile *pMF, const char **nameptr);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Read the array header for the variable with the specified name from 
 * the MAT-file.
 * 
 * An array header contains all the same information as an
 * array, except that the pr, pi, ir, and jc data structures are 
 * not allocated for non-recursive data types.  That is,
 * Cells, structures, and objects contain pointers to other
 * array headers, but numeric, string, and sparse arrays do not 
 * contain valid data in their pr, pi, ir, or jc fields.
 *
 * The purpose of an array header is to gain fast access to 
 * information about an array without reading all the array's
 * actual data.  Thus, functions such as mxGetM, mxGetN, and mxGetClassID
 * can be used with array headers, but mxGetPr, mxGetPi, mxGetIr, mxGetJc,
 * mxSetPr, mxSetPi, mxSetIr, and mxSetJc cannot.
 *
 * An array header should NEVER be returned to MATLAB (for example via the
 * MEX API), or any other non-matrix access API function that expects a
 * full mxArray (examples include engPutVariable(), matPutVariable(), and 
 * mexPutVariable()).
 *
 * Return NULL if an error occurs.
 */
extern mxArray * matGetVariableInfo(MATFile *pMF, const char * name);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Remove a variable with with the specified name from the MAT-file pMF.
 *
 * Return zero on success, non-zero on error.
 */
extern int matDeleteVariable(MATFile *pMF, const char *name);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
/* 
 * Get a list of the names of the arrays in a MAT-file.
 * The array of strings returned by this function contains "num"
 * entries.  It is allocated with one call to mxCalloc, and so 
 * can (must) be freed with one call to mxFree.
 *
 * If there are no arrays in the MAT-file, return value 
 * is NULL and num is set to zero.  If an error occurs,
 * return value is NULL and num is set to a negative number.
 */
extern char ** matGetDir(MATFile * pMF, int *num);
#ifdef __cplusplus
}
#endif


#if defined(V5_COMPAT)
#define matPutArray(pMF, pA)         matPutVariable(pMF, mxGetName(pA), pA)
#define matPutNextArray(pMF, pA)     matPutNextVariable(pMF, mxGetName(pA), pA)
#define matPutArrayAsGlobal(pMF, pA) matPutVariableAsGlobal(pMF, mxGetName(pA), pA)
#define matGetArray(pMF, name)       matGetVariable(pMF, name)
#define matGetArrayHeader(pMF, name) matGetVariableInfo(pMF, name)
#define matGetNextArray(pMF)         matGetNextVariable(pMF, NULL)
#define matGetNextArrayHeader(pMF)   matGetNextVariableInfo(pMF, NULL)
#define matDeleteArray(pMF, name)    matDeleteVariable(pMF, name)
#else
#define matPutArray()                matPutArray_is_obsolete
#define matPutNextArray()            matPutNextArray_is_obsolete
#define matPutArrayAsGlobal()        matPutArrayAsGlobal_is_obsolete
#define matGetArray()                matGetArray_is_obsolete
#define matGetArrayHeader()          matGetArrayHeader_is_obsolete
#define matGetNextArray()            matGetNextArray_is_obsolete
#define matGetNextArrayHeader()      matGetNextArrayHeader_is_obsolete
#define matDeleteArray()             matDeleteArray_is_obsolete
#endif  /* defined(V5_COMPAT) */


/* $Revision$ */
#ifdef ARGCHECK

#include "mwdebug.h" /* Prototype _d versions of API functions */

#define matClose(pMAT) 				matClose_d(pMAT, __FILE__, __LINE__)
#define matDeleteVariable(pMAT, name)		matDeleteVariable_d(pMAT, name, __FILE__, __LINE__) 
#define matGetVariable(pMAT, name) 	matGetVariable_d(pMAT, name, __FILE__, __LINE__) 
#define matGetVariableInfo(pMAT, name) matGetVariableInfo_d(pMAT, name, __FILE__, __LINE__) 
#define matGetDir(pMAT, num) 			matGetDir_d(pMAT, num, __FILE__, __LINE__)
#define matGetFp(pMAT) 				matGetFp_d(pMAT, __FILE__, __LINE__) 
#define matGetNextVariable(pMAT, pname) matGetNextVariable_d(pMAT, pname, __FILE__, __LINE__)
#define matGetNextVariableInfo(pMAT, pname) 	matGetNextVariableInfo_d(pMAT, pname, __FILE__, __LINE__)
#define matOpen(fname, permissions) 	        matOpen_d(fname, permissions, __FILE__, __LINE__) 
#define matPutVariable(pMAT, name, pa) 	matPutVariable_d(pMAT, name, pa, __FILE__, __LINE__)
#define matPutVariableAsGlobal(pMAT, name, pa) matPutVariableAsGlobal_d(pMAT, name, pa, __FILE__, __LINE__)
#endif

#endif /* mat_h */


