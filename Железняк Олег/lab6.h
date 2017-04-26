#ifndef LAB6_H_INCLUDED
#define LAB6_H_INCLUDED

#define STR_LEN 101

/*! \fn void* readFile(const char *fileName, size_t n)
    \brief Reads n lines from a file
    \param fileName Source file
    \param n Number of lines to read
    \return A pointer to an array of n elements, each of which is an array of characters of size STR_LEN
*/
void* readFile(const char *fileName, size_t n);


/*! \fn char* shorten(const char *s)
    \brief Shortens the string
    \param s Source string
    \return Returns a pointer to a new line if it is truncated, null pointer otherwise
*/
char* shorten(const char *s);


/*! \fn writeFile(const char *fileName, char (*res)[STR_LEN], size_t n)
    \brief Writes n lines to the file
    \param fileName Output file
    \param res A pointer to an array of n elements, each of which is an array of characters of size STR_LEN
    \param n Number of lines to write
*/
void writeFile(const char *fileName, char (*res)[STR_LEN], size_t n);


/*! \fn void testShorten()
    \brief Testing function for shorten()
*/
void testShorten();

#endif // LAB6_H_INCLUDED
