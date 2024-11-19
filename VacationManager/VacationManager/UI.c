#include <stdio.h>
#include "domain.h"
#include "dynamic_array.h"
#include "OperationsStack.h"
#include "services.h"
#include "UI.h"


void print(){
    printf("1. Add an offer.\n");
    printf("2. Delete an offer.\n");
    printf("3. Update an offer.\n");
    printf("4. Display by string(ordered ascending after price).\n");
    printf("5. Display by type(after a departure date).\n");
    printf("6. Undo the last operation.\n");
    printf("7. Redo the last operation.\n");
    printf("0. Exit.\n");

    printf("Please enter a choice(0-7): ");
}







int main() {
    int i;
    VacationVector vacations;
    init_vector(&vacations);
    OperationsStack stack;
    init_stack(&stack);
    add_initial_vacations(&vacations);
    test_find_by_type(&vacations, "Mountain");
    //test_after_date(&vacations, 2000, 1, 1);
    // test_add_vacation();
    test_delete_vacation();

    while (1) {
        print();
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char type[50], destination[50];
            int day, month, year, price;
            printf("Please enter the type of vacation: ");
            scanf("%s", type);
            printf("Please enter the destination: ");
            scanf("%s", destination);
            printf("Please enter the departure date (day month year): ");
            scanf("%d %d %d", &day, &month, &year);
            printf("Please enter the price: ");
            scanf("%d", &price);

            Vacation *vacation = createVacation(type, destination, day, month, year, price);
            add_vacation(&vacations, vacation);
            Operation operation;
            push(&operation, &vacations, vacation, 1); // Flag 1 indicates addition
            push_stack(&stack, &operation);

        }


        if (choice == 2) {
            if (vacations.size == vacations.cap) {
                resize(&vacations, vacations.cap * 2);
            }
            printf("Please enter the destination of the offer you want to delete: ");
            char destination[50];
            scanf("%s", destination);
            int found = 0;
            for (i = 0; i < vacations.size; i++) {
                if (strcmp(vacations.data[i].destination, destination) == 0) {
                    found = 1;
                    Vacation deleted_vacation = vacations.data[i]; // Create a temporary variable to store information about the deleted vacation
                    delete_vacation(&vacations, destination);
                    Operation operation;
                    push(&operation, &vacations, &deleted_vacation, 0); // Flag 0 indicates deletion
                    push_stack(&stack, &operation);

                    printf("Vacation deleted successfully.\n");
                    break;
                }
            }
            if (!found) {
                printf("Vacation with destination '%s' not found.\n", destination);
            }
        }
        if (choice == 3) {
            if (vacations.size == vacations.cap) {
                resize(&vacations, vacations.cap * 2);
            }
            printf("Please enter the destination of the offer you want to update: ");
            char destination[50];
            scanf("%s", destination);
            for (i = 0; i < vacations.size; i++) {
                if (strcmp(vacations.data[i].destination, destination) == 0) {
                    // Store the old vacation before making any changes
                    Vacation old_vacation = vacations.data[i];

                    // Perform the update operation
                    int found = i;
                    char destination1[50], type1[50];
                    time dep_date1;
                    int price1;
                    printf("Please enter the new type: ");
                    scanf("%s", type1);
                    printf("Please enter the new destination: ");
                    scanf("%s", destination1);
                    printf("Please enter the new departure date: ");
                    scanf("%d %d %d", &dep_date1.day, &dep_date1.month, &dep_date1.year);
                    printf("Please enter the new price: ");
                    scanf("%d", &price1);

                    if (check_date_and_destination(&vacations, destination1, dep_date1.day, dep_date1.month, dep_date1.year) > 1) {
                        printf("Invalid input!");
                    } else {
                        strcpy(vacations.data[found].type, type1);
                        strcpy(vacations.data[found].destination, destination1);
                        vacations.data[found].dep_date.day = dep_date1.day;
                        vacations.data[found].dep_date.month = dep_date1.month;
                        vacations.data[found].dep_date.year = dep_date1.year;
                        vacations.data[found].price = price1;
                    }
                    stack.updated_vacation = vacations.data[found];
                    // Push the old vacation onto the stack
                    Operation operation;
                    push(&operation, &vacations, &old_vacation, 2); // Flag 2 indicates update
                    push_stack(&stack, &operation);
                }
            }
        }

        if (choice == 4) {
            VacationVector list;
            init_vector( &list);
            if(vacations.size==vacations.cap){
                resize(&vacations, vacations.cap*2);
            }
            int k = 0;
            char string[50];
            printf("Please enter a string: ");
            scanf("%s", &string);
            if (strcmp(string, "0") == 0) {
                for (i = 0; i < vacations.size; i++) {
                    printf("Type: %s | Destination: %s | Departure Date: %d %d %d | Price: %d\n",
                           vacations.data[i].type, vacations.data[i].destination,
                           vacations.data[i].dep_date.day, vacations.data[i].dep_date.month, vacations.data[i].dep_date.year,
                           vacations.data[i].price);
                }


            } else {

                if(find_and_sort(&vacations, string, &k, &list)==0)
                    printf("Invalid input!\n");
                else {
                    for (i = 0; i < k; i++)
                        printf("Type: %s | Destination: %s | Departure Date: %d %d %d | Price: %d\n",
                               list.data[i].type, list.data[i].destination,
                               list.data[i].dep_date.day, list.data[i].dep_date.month, list.data[i].dep_date.year,
                               list.data[i].price);
                }

            }


        }

        if(choice==5){
            char type[50];
            VacationVector list, list1;
            init_vector(&list);
            init_vector(&list1);
            printf("Please enter the type of the vacation: ");
            scanf("%s", type);
            int day, month, year;
            printf("Please enter the date: ");
            scanf("%d %d %d", &day, &month, &year);
            list= find_by_type(&vacations, type);
            list1= after_date(&list, day, month, year);
            for (i = 0; i < list1.size; i++) {
                printf("Type: %s | Destination: %s | Departure Date: %d %d %d | Price: %d\n",
                       list1.data[i].type, list1.data[i].destination,
                       list1.data[i].dep_date.day, list1.data[i].dep_date.month, list1.data[i].dep_date.year,
                       list1.data[i].price);
            }


        }

        if(choice==6){
            Operation operation = pop_stack(&stack);
            undo(&operation, &stack.updated_vacation);

        }

        if(choice==7){
            redo(&stack);
        }

        if(choice==0){
            free_vector(&vacations);
            free_stack(&stack);
            break;
        }
    }
}


