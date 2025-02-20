#pragma once

/*=======================================================================*/

#include <stdlib.h>

/*=======================================================================*/

typedef char*              C_Char_Ptr;
typedef unsigned char      C_Ret_Code;
typedef unsigned char      C_Bool;

typedef unsigned char      C_UChar;
typedef signed char        C_SChar;
typedef char               C_Char;

typedef unsigned long long C_ULLong;
typedef signed long long   C_SLLong;
typedef long long          C_LLong;
typedef long               C_Long;

typedef unsigned short     C_UShort;
typedef signed short       C_SShort;
typedef short              C_Short;

typedef float              C_Float;

typedef double             C_Double;

/*=======================================================================*/

// Boolean constants.
#define C_TRUE                    (C_UChar)1
#define C_FALSE                   (C_UChar)0
// Error/success constants.
#define C_ERROR_MEMALLOC          (C_UChar)0
#define C_ERROR_INVALID_PTR       (C_UChar)1
#define C_ERROR_INVALID_LENGTH    (C_UChar)2
#define C_ERROR_INVALID_POSITION  (C_UChar)3
#define C_ERROR_INVALID_COUNT     (C_UChar)4
#define C_ERROR_VALUE_IS_NOT_NULL (C_UChar)5
#define C_ERROR_NOT_FOUND         (C_UChar)6
#define C_SUCCESS                 (C_UChar)7
// Character constants.
#define C_NULL_TERMINATOR         (C_UChar)'\0'

/*=======================================================================*/

typedef struct {
	C_Char_Ptr value;
	C_ULLong length;
} C_String;

typedef struct {
	C_Char_Ptr start;
	C_ULLong length;
} C_Slice;

typedef struct {
	C_Slice* items;
	C_UShort size;
} C_Slices;

/*=======================================================================*/

C_Ret_Code cstr_build(C_String* const this, C_Char_Ptr const value);
C_Ret_Code cstr_free(C_String* const this);
C_Ret_Code cstr_append(C_String* const this, C_Char_Ptr append_string, C_UChar const count);
C_Ret_Code cstr_slice(C_String* const this, C_ULLong const start, C_ULLong const end);
C_LLong    cstr_index_of(C_String* const this, C_Char const ch, C_ULLong const start_position);
C_Ret_Code cstr_split(C_Slices* const this, C_Char_Ptr const to_split, C_Char const spliter);
C_Ret_Code cstr_split_free(C_Slices* const this);

C_Ret_Code cstr_cpy(C_Char_Ptr const dest, C_Char_Ptr const source, C_LLong const length);
C_ULLong   cstr_len(C_Char_Ptr const value);
C_Bool     cstr_comp(C_Char_Ptr const str_one, C_Char_Ptr const str_two);

/*=======================================================================*/