#ifndef STUDENT_H
#define STUDENT_H

#include <inttypes.h>

typedef struct 
{
    char surname[26];
    char name[11];
    uint32_t marks[4];
} student;

#endif