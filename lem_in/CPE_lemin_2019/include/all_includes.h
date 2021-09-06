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
#define ERR 84
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
} head_t; //pointers to my_stack

typedef struct my_rooms_real {
    char *name;
    int x;
    int y;
    struct my_rooms_input **ways;
    int way_len;
    int moves;
    int visited;
    struct my_rooms_real *backtrack; //pointer to backtrack own struct
} room_t;

typedef struct my_rooms_input {
    struct my_rooms_input *next;
    struct my_rooms_input *prev;
    room_t *room; //pointer to my_rooms_input
} room_stack_t;

typedef struct my_head_rooms {
    room_stack_t *start; //pointer to my_rooms input
    room_stack_t *last;
} rooms_head_t;

typedef struct project_structure {
    int ants;
    rooms_head_t *rooms; //pointer to my_head_rooms
    room_t *start; //pointer for my_rooms_real
    room_t *end;
    int len;
} object; //object structure with relevant infos

typedef struct way_to_walk {
    struct way_to_walk *next; //pointer to itself
    struct way_to_walk *prev;
    room_t *room;
    int len_until_now;
} way_t;

typedef struct possible_way_to_end_stack {
    way_t *way_start; //pointer to way_to_walk
    way_t *way_end;
    int len;
    int shortest;
    int active;
    int max_ants;
} possible_way_stack_t;
//called in find_shortest_way function

typedef struct possible_ways_to_end_stack {
    struct possible_ways_to_end_stack *next; //pointing to itself
    struct possible_ways_to_end_stack *prev;
    possible_way_stack_t *cur;
} possible_ways_stack_t;

typedef struct possible_ways_to_end_head {
    possible_ways_stack_t *start; //pointer für possible_ways_to_end_stack
    possible_ways_stack_t *end;
} possible_ways_head_t;
//function get ways returned ways die man gehen kann
//ways.start ist der kürzeste weg
//ways.start->next der 2. kürzeste etc.
//ways.end ist der längste weg

typedef struct stack_for_alg {
    struct stack_for_alg *next;
    struct stack_for_alg *prev;
    room_t *cur; //den wert hier in die ways to walk struct übergeben als wert
} alg_stack_t;

typedef struct head_for_alg_stack {
    alg_stack_t *start;
    alg_stack_t *end;
} alg_head_t;

typedef struct ant_number {
    struct ant_number *next;
    struct ant_number *prev;
    int ant_name;
    way_t *way;
} ant_nbr_t;

typedef struct head_ant_number {
    ant_nbr_t *start;
    ant_nbr_t *last;
} head_ant_nbr_t;

typedef struct names_s {
    char *name;
    int has_tunnel;
    struct names_s *next;
} names_t;

/*
typedef struct possible_way_to_end_head {
    struct possible_way_to_end_stack *start;
    struct possible_way_to_end_stack *end;
} possible_way_head_t;
*/

//error_handling.c
int check_first_line(char *input);
int is_valid(char *input, int last);

//name_error_handling.c
names_t *add_name(names_t *head, char *input);
int name_twice(names_t *head);
int find_name(char *input, names_t *head);

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

//len.c
int get_max_value(possible_ways_head_t *head, int max);

//print_alg.c
int my_push_ants(head_ant_nbr_t *stack, possible_way_stack_t *way);
void my_pop_ants(head_ant_nbr_t *stack, ant_nbr_t *el);
void print_alg(possible_ways_head_t *ways, object *my_struct);

