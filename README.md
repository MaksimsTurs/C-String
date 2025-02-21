# CString Library

The `CString` library is a C-based utility designed to handle dynamic strings and perform various string operations, such as splitting, appending, copying, slicing, and more. The library provides functions that ensure safe memory allocation and management for string operations.

## Features

- **Memory Safe:** Handles dynamic memory allocation for strings and performs checks to avoid memory issues.
- **Efficient String Operations:** Provides operations like appending, slicing, splitting, and searching within strings.
- **Error Handling:** Uses error codes for handling invalid operations.

## Functions

### `cstr_build(CSTR_String* const this, CSTR_Char_Ptr const value)`
Allocates memory and initializes a `CSTR_String` object with a given string.

- **Parameters:**
  - `this`: A pointer to the `CSTR_String` object.
  - `value`: The string to assign to the `CSTR_String`.
  
- **Returns:** `CSTR_Ret_Code` (success or error code)

### `cstr_free(CSTR_String* const this)`
Frees the memory used by a `CSTR_String` object.

- **Parameters:**
  - `this`: A pointer to the `CSTR_String` object.

- **Returns:** `CSTR_Ret_Code` (success or error code)

### `cstr_append(CSTR_String* const this, CSTR_Char_Ptr append_string, CSTR_UChar const count)`
Appends a given string `append_string` to the existing string `this` a specified number of times.

- **Parameters:**
  - `this`: A pointer to the `CSTR_String` object.
  - `append_string`: The string to append.
  - `count`: The number of times to append the string.
  
- **Returns:** `CSTR_Ret_Code` (success or error code)

### `cstr_split(CSTR_Slices* const this, CSTR_Char_Ptr const to_split, CSTR_Char const spliter)`
Splits a string into multiple slices based on a delimiter character.

- **Parameters:**
  - `this`: A pointer to the `CSTR_Slices` structure to hold the resulting slices.
  - `to_split`: The string to split.
  - `spliter`: The delimiter character.
  
- **Returns:** `CSTR_Ret_Code` (success or error code)

### `cstr_split_free(CSTR_Slices* const this)`
Frees the memory used by the `CSTR_Slices` structure.

- **Parameters:**
  - `this`: A pointer to the `CSTR_Slices` structure.

- **Returns:** `CSTR_Ret_Code` (success or error code)

### `cstr_index_of(CSTR_String* const this, CSTR_Char const ch, CSTR_ULLong const start_position)`
Finds the first occurrence of a character `ch` starting from a specified position in the string.

- **Parameters:**
  - `this`: A pointer to the `CSTR_String` object.
  - `ch`: The character to search for.
  - `start_position`: The position in the string to start searching from.
  
- **Returns:** The index of the character or an error code if not found.

### `cstr_slice(CSTR_String* const this, CSTR_ULLong const start, CSTR_ULLong const end)`
Creates a slice of the string from `start` to `end` (exclusive).

- **Parameters:**
  - `this`: A pointer to the `CSTR_String` object.
  - `start`: The start position of the slice.
  - `end`: The end position of the slice.
  
- **Returns:** `CSTR_Ret_Code` (success or error code)

### `cstr_len(CSTR_Char_Ptr const value)`
Returns the length of the string (excluding the null terminator).

- **Parameters:**
  - `value`: The string whose length is to be determined.
  
- **Returns:** The length of the string.

### `cstr_cpy(CSTR_Char_Ptr const dest, CSTR_Char_Ptr const source, CSTR_LLong const length)`
Copies `length` characters from `source` to `dest`.

- **Parameters:**
  - `dest`: The destination string.
  - `source`: The source string.
  - `length`: The number of characters to copy.
  
- **Returns:** `CSTR_Ret_Code` (success or error code)

### `cstr_comp(CSTR_Char_Ptr const str_one, CSTR_Char_Ptr const str_two)`
Compares two strings for equality.

- **Parameters:**
  - `str_one`: The first string to compare.
  - `str_two`: The second string to compare.
  
- **Returns:** `CSTR_TRUE` if the strings are equal, `CSTR_FALSE` if they are not.

## Example Usage

```c
#include "CString.h"

int main() {
    // Create and build a string
    CSTR_String my_string;
    cstr_build(&my_string, "Hello");

    // Append text to the string
    cstr_append(&my_string, " World", 1);

    // Split the string by space
    CSTR_Slices slices;
    cstr_split(&slices, my_string.value, ' ');

    // Print the results
    for (int i = 0; i < slices.size; i++) {
        printf("Slice %d: %.*s\n", i, (int)slices.items[i].length, slices.items[i].start);
    }

    // Clean up
    cstr_free(&my_string);
    cstr_split_free(&slices);

    return 0;
}
```