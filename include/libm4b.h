#ifndef __LIBM4B_H__
#define __LIBM4B_H__

#ifdef __cplusplus
extern "C" {
#endif

#define LIBM4B_API
#define LIBM4B_CALL _cdecl

struct M4BFile;

typedef M4BFile* m4b_t;
typedef int m4b_error_t;
typedef int m4b_int_t;
typedef unsigned int m4b_uint_t;
typedef unsigned char* m4b_byte_t;

enum m4b_error
{
    M4B_ERROR_NONE = 0,
    M4B_ERROR_FILE_FAILED_TO_OPEN,
    M4B_ERROR_FILE_NOT_FOUND,
    M4B_ERROR_FILE_ALREADY_EXISTS,
    M4B_ERROR_READ_ERROR,
    M4B_ERROR_WRITE_ERROR,
    M4B_ERROR_INVALID_FILE,
    M4B_ERROR_INVALID_VERSION,
    M4B_ERROR_INVALID_ARGUMENT,
    M4B_ERROR_OUT_OF_MEMORY,
    M4B_ERROR_NOT_IMPLEMENTED,
    M4B_ERROR_INTERNAL_ERROR
};

enum m4b_flags
{
    M4B_FLAG_NONE = 0,
    M4B_FLAG_TREAT_SUB_M4B_AS_DIR = 1 << 0, // Treat sub m4b files as directories
};

/// Open a M4B file
/// \param filename The path to the M4B file
/// \param flags The flags to open the M4B file with
/// \param m4b A pointer to the M4B file handle
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_open(const char* filename, m4b_uint_t flags, m4b_t** m4b);

/// Create a M4B file
/// \param m4b A pointer to the M4B file handle
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_create(m4b_t** m4b);

/// Close a M4B file
/// \param m4b The M4B file handle
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_close(m4b_t m4b);

/// Get the number of files in the M4B file
/// \param m4b The M4B file handle
/// \return The number of files in the M4B file
LIBM4B_API m4b_int_t LIBM4B_CALL m4b_get_file_count(m4b_t m4b);

/// Get the size of a file in the M4B file
/// \param m4b The M4B file handle
/// \param index The index of the file
/// \return The size of the file
LIBM4B_API m4b_uint_t LIBM4B_CALL m4b_get_file_size(m4b_t m4b, m4b_int_t index);

/// Read a file from the M4B file
/// \param m4b The M4B file handle
/// \param index The index of the file
/// \param buffer A pointer to the buffer to read the file into
/// \param size The size of the buffer
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_read_file(m4b_t m4b, m4b_int_t index, m4b_byte_t* buffer, m4b_uint_t size);

/// Get the error message for a given error code
/// \param error The error code
/// \return The error message
LIBM4B_API const char* LIBM4B_CALL m4b_get_error_message(m4b_error_t error);

/// Add a file to the M4B file
/// \param m4b The M4B file handle
/// \param target The path to add the file to
/// \param filename The path to the file to add
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_add_file(m4b_t m4b, const char* target, const char* filename);

/// Add a file to the M4B file from memory
/// \param m4b The M4B file handle
/// \param target The path to add the file to
/// \param buffer A pointer to the buffer to read the file from
/// \param size The size of the buffer
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_add_file_from_memory(m4b_t m4b, const char* target, m4b_byte_t buffer, m4b_uint_t size);

/// Remove a file from the M4B file
/// \param m4b The M4B file handle
/// \param index The index of the file
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_remove_file(m4b_t m4b, m4b_int_t index);

/// Find a file in the M4B file
/// \param m4b The M4B file handle
/// \param path The path of the file
/// \return The index of the file, or -1 if not found
LIBM4B_API m4b_int_t LIBM4B_CALL m4b_find_file(m4b_t m4b, const char* path);

/// Get the path of a file in the M4B file
/// \param m4b The M4B file handle
/// \param index The index of the file
/// \return The path of the file
LIBM4B_API const char* LIBM4B_CALL m4b_get_file_target(m4b_t m4b, m4b_int_t index);

/// Write the M4B file to disk
/// \param m4b The M4B file handle
/// \param filename The path to write the M4B file to
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_write_to_disk(m4b_t m4b, const char* filename);

/// Write the M4B file to memory
/// \param m4b The M4B file handle
/// \param buffer A pointer to the buffer to write the M4B file to
/// \param size The size of the buffer
/// \return 0 on success, non-zero on failure
LIBM4B_API m4b_error_t LIBM4B_CALL m4b_write_to_memory(m4b_t m4b, m4b_byte_t* buffer, m4b_int_t size);

#ifdef __cplusplus
}
#endif

#endif // __LIBM4B_H__
