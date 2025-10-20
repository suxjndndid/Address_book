#ifndef CONTACT_C_H
#define CONTACT_C_H

#include <time.h>

#define MAX_LEN 256

typedef struct {
    int id;
    char name[MAX_LEN];
    char phone[MAX_LEN];
    char email[MAX_LEN];
    char address[MAX_LEN];
    char notes[MAX_LEN];
    char group_name[MAX_LEN];
    time_t created_time;
} ContactC;

#endif // CONTACT_C_H
