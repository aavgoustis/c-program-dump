#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

char command[10];
char author[40];

char new_id[1024];
int this_id;
char new_name[1024];
char new_desc[1024];
char new_todo_author[1024];

struct todo_item {
    int id;
    char name[1024];
    char desc[1024];
    char todo_author[1024];
};

struct todo_item todo_list[256];

int help(void) {
    printf("[n]ew task, [d]elete task, [l]ist tasks, [q]uit\n");
    return 0;
}

int main(void)
{
    printf("** TODO List **");
    for (int i = 0; i < MAX; i++)
    {
        printf("todolist> ");
        if (fgets(command, 10, stdin))
        {
            command[strcspn(command, "\n")] = 0; // replace \n with 0

            // exit
            if (strcmp(command, "q") == 0) {
                return 0;
            }

            // new task
            else if (strcmp(command, "n") == 0) {

                // get the task id
                do
                {
                    printf("new_id> ");
                    if (!fgets (new_id, 1024, stdin))
                    {
                        // reading input failed, give up:
                        return 1;
                    }

                    // have some input, convert it to integer:
                    this_id = atoi(new_id);
                } while (this_id == 0); // repeat until we get a valid number

                printf("ID of new task is: %i", this_id);
                // assign this id to the todo_list:
                todo_list[this_id].id = this_id;

                // get the task name
                do
                {
                    printf("new_name> ");
                    if (!fgets (new_name, 1024, stdin))
                    {
                        //reading input failed, give up:
                        printf("Enter a tak name!\n");
                    }
                } while (strcmp(new_name, "") == 0); // repeat until we get a correct name

                printf("Name of new task is: %s", new_name);
                // assign new name
                strcpy(todo_list[this_id].name, new_name);

                // get the task description
                do
                {
                    printf("new_desc> ");
                    if(!fgets (new_desc, 1024, stdin))
                    {
                        //reading input failed
                        printf("Enter a description!\n");
                        continue;
                } while (strcmp(new_desc, "") == 0); //repeat until we get a correct desc

                printf("Description added successfully!");
                // assign new description
                strcpy(todo_list[this_id].desc, new_desc);
            }
        }
    }

    return 0;
}