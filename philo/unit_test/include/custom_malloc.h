#ifndef CUSTOM_MALLOC_H
# define CUSTOM_MALLOC_H
# ifdef __linux__
# define _GNU_SOURCE
# endif

# include <stddef.h>
# include <dlfcn.h>
// Custom malloc function
void *custom_malloc(size_t size);

// Set malloc failure condition
void set_malloc_failure_condition(int condition);

void activate_malloc_hook(void);
void deactivate_malloc_hook(void);

int get_malloc_failure_condition(void);
#endif // CUSTOM_MALLOC_H
