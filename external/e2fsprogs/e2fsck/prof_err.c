/*
 * prof_err.c:
 * This file is automatically generated; please do not edit it.
 */

#include <stdlib.h>

#define N_(a) a

static const char * const text[] = {
	N_("Profile version 0.0"),
	N_("Bad magic value in profile_node"),
	N_("Profile section not found"),
	N_("Profile relation not found"),
	N_(	"Attempt to add a relation to node which is not a section"),
	N_(	"A profile section header has a non-zero value"),
	N_("Bad linked list in profile structures"),
	N_("Bad group level in profile structures"),
	N_(	"Bad parent pointer in profile structures"),
	N_("Bad magic value in profile iterator"),
	N_("Can't set value on section node"),
	N_("Invalid argument passed to profile library"),
	N_("Attempt to modify read-only profile"),
	N_("Profile section header not at top level"),
	N_("Syntax error in profile section header"),
	N_("Syntax error in profile relation"),
	N_("Extra closing brace in profile"),
	N_("Missing open brace in profile"),
	N_("Bad magic value in profile_t"),
	N_("Bad magic value in profile_section_t"),
	N_(	"Iteration through all top level section not supported"),
	N_("Invalid profile_section object"),
	N_("No more sections"),
	N_("Bad nameset passed to query routine"),
	N_("No profile file open"),
	N_("Bad magic value in profile_file_t"),
	N_("Couldn't open profile file"),
	N_("Section already exists"),
	N_("Invalid boolean value"),
	N_("Invalid integer value"),
	N_("Bad magic value in profile_file_data_t"),
    0
};

struct error_table {
    char const * const * msgs;
    long base;
    int n_msgs;
};
struct et_list {
    struct et_list *next;
    const struct error_table * table;
};
extern struct et_list *_et_list;

const struct error_table et_prof_error_table = { text, -1429577728L, 31 };

static struct et_list link = { 0, 0 };

void initialize_prof_error_table_r(struct et_list **list);
void initialize_prof_error_table(void);

void initialize_prof_error_table(void) {
    initialize_prof_error_table_r(&_et_list);
}

/* For Heimdal compatibility */
void initialize_prof_error_table_r(struct et_list **list)
{
    struct et_list *et, **end;

    for (end = list, et = *list; et; end = &et->next, et = et->next)
        if (et->table->msgs == text)
            return;
    et = malloc(sizeof(struct et_list));
    if (et == 0) {
        if (!link.table)
            et = &link;
        else
            return;
    }
    et->table = &et_prof_error_table;
    et->next = 0;
    *end = et;
}
