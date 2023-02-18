#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TODO_STRING_SIZE 1024
#define MAX_TODOS 64
#define MAX_ISCOMPLETE_STRING_SIZE 2

struct Todo {
        char name[1024];
        char is_completed[2];
        char text[1024];
};

char *get_input(void) {
        static char input_buf[MAX_TODO_STRING_SIZE];
        fgets(input_buf, MAX_TODO_STRING_SIZE, stdin);

        return input_buf;
}

int main(int argc, char* argv[]) {

	//struct Todo *todo = (struct Todo*)calloc(100, sizeof(struct Todo));
        
	struct Todo todo[MAX_TODOS];
	int cur_todo = 0;

        if (argc >= 2) {
                //if (strcmp(argv[1], "create") == 0) {
                //        if (argc == 3) {
                //                printf("%s ", argv[1]);
                //                printf("%s", argv[2]);
		//
                //                strncpy(todo->text, argv[2], MAX_TODO_STRING_SIZE);
		//
                //        }
                //}

                return 0;
        }
        
        if (argc == 1) {
                char *input = NULL;
                size_t input_size = 0;

                while (1) {
                        printf(" ctd > ");
                        getline(&input, &input_size, stdin);

                        if (strcmp(input, "create\n") == 0) {
                            	if (cur_todo >= MAX_TODO_STRING_SIZE - 1) {
					printf(" ctd: You can create only 1024 todos");
                            	} else {
                                        printf("Name: ");
                                        strncpy(todo[cur_todo].name, get_input(), MAX_TODO_STRING_SIZE);

                                        printf("Is Completed? (Y/n): ");
                                        if (strcmp(input, "Y\n") == 0 || strcmp(get_input(), "y\n") == 0) {
                                                strncpy(todo[cur_todo].is_completed, "X", MAX_ISCOMPLETE_STRING_SIZE);
                                        } else {
                                                strncpy(todo[cur_todo].is_completed, " ", MAX_ISCOMPLETE_STRING_SIZE);
                                        }

                                        printf("Text: ");
                                        strncpy(todo[cur_todo].text, get_input(), MAX_TODO_STRING_SIZE);
        				cur_todo++;
				}
                        } else if (strcmp(input, "list\n") == 0) {
                        	if (cur_todo == 0) {
                                	printf("------------------\n");
					printf(" No tasks created\n");
                                	printf("------------------\n");
                        	} else {
                                	printf("------------------");

                                        for (int i = 0; i < cur_todo; i++) {
        					printf("\n#%d [%s] %s", i, todo[i].is_completed, todo[i].name);
        					printf("Text: %s", todo[i].text);
                                	}                        

                                	printf("------------------\n");
				}
                        } else if (strcmp(input, "exit\n") == 0) {
                        	
				printf("%s", todo[cur_todo].name);
                                return 0;
                        } else {
				printf(" ctd: Command not found\n");
                        }
                }
        }

        //free(todo);
        return 0;
}
