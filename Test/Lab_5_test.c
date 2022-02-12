char tolower(int c)
{
    // (int)a = 97, (int)A = 65
    // (a)97 - (A)65 = 32
    // therefore 32 + 65 = a
    return c > 64 && c < 91 ? c + 32 : c;
}

// return the specfied letter in uppercase
char toupper(int c)
{
    // (int)a = 97, (int)A = 65
    // (a)97 - (A)65 = 32
    // therefore 97 - 32 = A
    return c > 96 && c < 123 ? c - 32 : c;
}