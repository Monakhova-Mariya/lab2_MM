#ifndef IMITATION_CREATE_H
#define IMITATION_CREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#define KEY_LENGTH 32

void create_imitation(const char *input_file, const char *key, const char *output_file, const char *method);

#endif
