// dynamic_arr.c -- Demostrate dynamic memory management with C.
// This program exemplifies how to manage memory dynamically in C. This
// program allows you to add numbers to a list, print the list, get the
// average, remove a specific number from the list, and clear the list
// completely.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void welcome(void);
void main_menu(void);
void print_menu(void);
char get_char_input(void);
void print_list(int *list, int list_size);
int *add_number(int *list, int *list_size);
int *remove_number(int *list, int *list_size);
void print_list_or(int *list, int list_size);
int get_item_to_rem(void);
void print_avg(int *list, int list_size);
void clear_list(int *list, int *list_size);

int main(void)
{
    system("@CLS||clear");
    welcome();
    main_menu();
    return 0;
}

void welcome(void)
{
    printf("Welcome to the dynamic memory example program.\n"
           "By Rodolfo Andres Rivas Matta.\n");
    return;
}

void main_menu(void)
{
    bool done = false;
    char selection;
    int *numbers_list = NULL, list_size = 0;

    while (!done) {
        print_menu();
        selection = get_char_input();

        switch (selection)
        {
        case '1':
            print_list(numbers_list, list_size);
            break;

        case '2':
            numbers_list = add_number(numbers_list, &list_size);
            break;

        case '3':
            numbers_list = remove_number(numbers_list, &list_size);
            break;

        case '4':
            print_avg(numbers_list, list_size);
            break;

        case '5':
            clear_list(numbers_list, &list_size);
            numbers_list = NULL;
            break;

        case 'q':
        case 'Q':
            done = true;
            break;

        default:
            printf("Invalid input.\n");
            break;
        }
    }

    return;
}

void print_menu(void)
{
    printf(
        "\n-------------------------------------\n"
        "Main menu\n"
        "1. Print list of numbers.\n"
        "2. Add numbers.\n"
        "3. Remove a number.\n"
        "4. Get the average.\n"
        "5. Clear list.\n"
        "q. Exit\n\n"
    );

    return;
}

char get_char_input(void)
{
    char user_input = '\0';
    printf("Enter selection: ");

    user_input = getchar();
    fflush(stdin);
    system("@CLS||clear");

    return user_input;
}

void print_list(int *list, int list_size)
{
    if (list_size == 0) printf("Empty list.");

    else
    {
        printf("Numbers in list: ");
        for (int i = 0; i < list_size; i++)
            printf("%d ", *(list + i));
    }

    printf("\n");

    return;
}

int *add_number(int *list, int *list_size)
{
	int number;
	printf("Enter the number you want to add: ");
	scanf("%d", &number);
	fflush(stdin);

	int *new_p = (int*) realloc(list, sizeof(int) * (*list_size + 1));
	if (new_p)
	{
		*(new_p + *list_size) = number;
		(*list_size)++;
		printf("Number \"%d\" successfully added.\n", number);
	}
	else
	{
		printf("Error: unable to allocate memory.\n");
		new_p = list;
	}

	return new_p;
}

int *remove_number(int *list, int *list_size)
{
    if (*list_size == 0)
    {
        printf("The list is already empty.\n");
        return list;
    }
    else
    {
        // What item do you want to remove?
        print_list_or(list, *list_size);
        int item_to_remove; bool done = false;
        while (!done) {
            item_to_remove = get_item_to_rem();
            if (item_to_remove <= *list_size && item_to_remove > 0)
                done = true;
            else {
                printf("Invalid input. Please, try again.\n");
            }
        }

        // Remove item.
        for (int i = item_to_remove; i < *list_size; i++)
            *(list + i - 1) = *(list + i);
        
        list = (int*) realloc(list, (*list_size - 1) * sizeof(int));
        (*list_size)--;
        return list;
    }
}

void print_list_or(int *list, int list_size)
{
    printf("\n" "%10s | %10s\n", "Item", "Value");
    for (size_t i = 0; i < 23; i++) printf("-");
    printf("\n");    
    for (int i = 0; i < list_size; i++)
        printf("%10d | %10d\n", i + 1, *(list + i));
    
    return;
}

int get_item_to_rem(void)
{
    printf("\nSelect the item you want to remove: ");
    int user_input;
    scanf("%d", &user_input);
    fflush(stdin);
    return user_input;
}

void print_avg(int *list, int list_size)
{
    if (list_size > 0)
    {
        int total_sum = 0;
        print_list(list, list_size);
        for (int i = 0; i < list_size; i++) total_sum += *(list + i);
        double avg = (double) total_sum / (double) list_size;
        printf("\nAverage: %.2f\n", avg);
    }
    else printf("Empty list. No average to calculate.\n");
    return;
}

void clear_list(int *list, int *list_size)
{
    free(list);
    *list_size = 0;
    printf("List cleared.\n");
    return;
}
