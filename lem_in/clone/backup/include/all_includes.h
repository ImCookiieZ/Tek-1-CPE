/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** add_all_includes
*/

#include "my.h"
#include <zconf.h>

#define TRUE 1
#define FALSE 2
#define ERROR_INT 84
#define ERROR_PTR NULL
#define ERROR_CHR 24
#define SUCCESS 0

typedef struct my_stack {
    struct my_stack *next;
    struct my_stack *prev;
    char *str;
    int nb;
} stack_t;

typedef struct my_head {
    stack_t *start;
    stack_t *last;
} head_t;

typedef struct my_rooms_real {
    char *name;
    int x;
    int y;
    struct my_rooms_input **ways;
    int way_len;
    int moves;
    int visited;
    struct my_rooms_real *backtrack;
} room_t;

typedef struct my_rooms_input {
    struct my_rooms_input *next;
    struct my_rooms_input *prev;
    room_t *room;
} room_stack_t;

typedef struct my_head_rooms {
    room_stack_t *start;
    room_stack_t *last;
} rooms_head_t;

typedef struct project_structure {
    int ants;
    rooms_head_t *rooms;
    room_t *start;
    room_t *end;
    int len;
} object;

typedef struct way_to_walk {
    struct way_to_walk *next;
    struct way_to_walk *prev;
    room_t *room;
    int len_until_now;
} way_t;

typedef struct possible_way_to_end_stack {
    way_t *way_start;
    way_t *way_end;
    int len;
    int shortest;
    int active;
} possible_way_stack_t;

/*
typedef struct possible_way_to_end_head {
    struct possible_way_to_end_stack *start;
    struct possible_way_to_end_stack *end;
} possible_way_head_t;
*/

typedef struct possible_ways_to_end_stack {
    struct possible_ways_to_end_stack *next;
    struct possible_ways_to_end_stack *prev;
    possible_way_stack_t *cur;
} possible_ways_stack_t;

typedef struct possible_ways_to_end_head {
    possible_ways_stack_t *start;
    possible_ways_stack_t *end;
} possible_ways_head_t;

typedef struct stack_for_alg {
    struct stack_for_alg *next;
    struct stack_for_alg *prev;
    room_t *cur;
} alg_stack_t;

typedef struct head_for_alg_stack {
    alg_stack_t *start;
    alg_stack_t *end;
} alg_head_t;

//delete_comments.c
void delete_comments(head_t *stack);
void delete_empty_lines(head_t *stack);
void my_delete_node(stack_t *el, head_t *stack);

//error.c
void my_put_error_str(char *str);

//stacks.c
char *my_pop(head_t *stack);
int my_push(char *str, head_t *stack);
int my_push_way(possible_way_stack_t *way, possible_ways_head_t *stack);
int my_push_room(room_t *room, possible_way_stack_t *stack);

//process.c
int start_process(head_t *stack);

//alg.c
possible_ways_head_t get_ways(object *my_struct);
possible_way_stack_t *find_shortest_way(object *my_struct);
room_t *my_pop_alg(alg_head_t *stack);
int my_push_alg(room_t *room, alg_head_t *stack, room_t *backtrack, int len);

//main.c
int print_end(object *project, head_t *tunnel);
