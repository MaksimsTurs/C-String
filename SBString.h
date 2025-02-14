#include <stdlib.h>
#include <string.h>

// Types constants.
#define SB_TRUE  (unsigned char)1
#define SB_FALSE (unsigned char)0

// Error and success constants.
#define SB_ERROR_MEMALLOC         (unsigned char)0
#define SB_ERROR_NULL_PTR         (unsigned char)2
#define SB_ERROR_INVALID_POSITION (unsigned char)3
#define SB_ERROR_INVALID_COUNT    (unsigned char)4
#define SB_SUCCESS                (unsigned char)1

// Character constants.
#define SB_NULL_TERMINATOR '\0'

/*===========================================*/
typedef unsigned char      SB_Return_Code;
/*===========================================*/
typedef unsigned char      SB_Boolean;
/*===========================================*/
typedef char*              SB_VString;
typedef const char*        SB_CString;
/*===========================================*/
typedef const char         SB_CChar;
typedef char               SB_Char;
/*===========================================*/
typedef unsigned long long SB_ULLong;
typedef long long          SB_LLong;
/*===========================================*/
typedef unsigned short     SB_UShort;
/*===========================================*/

typedef struct SB_String {
	SB_VString value;
	SB_ULLong length;
} SB_String;

typedef struct SB_Split {
	SB_CString* item;
	SB_UShort length;
} SB_Split;

SB_Return_Code sb_string_create(SB_String* self, SB_CString string);
SB_Return_Code sb_string_delete(SB_String self);
SB_Return_Code sb_string_split_delete(SB_Split self);
SB_Return_Code sb_string_split(SB_Split* split, SB_CString to_split, SB_CChar spliter);
SB_Return_Code sb_string_append(SB_String* self, SB_CString append_string, SB_UShort count);
SB_Return_Code sb_string_slice(SB_String* self, SB_ULLong start, SB_ULLong end);
SB_Return_Code sb_string_repeat(SB_String* self, SB_CString repeater, SB_UShort count);

SB_ULLong sb_string_length(SB_CString self);
SB_ULLong sb_string_index_of(SB_String* self, SB_CChar ch, SB_ULLong start_position);

SB_Boolean sb_string_compare(SB_CString str_one, SB_CString str_two);