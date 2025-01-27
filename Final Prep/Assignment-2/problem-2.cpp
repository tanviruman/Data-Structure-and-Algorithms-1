#include <stdio.h>
#define MAX 10

char queue[MAX][10];

int Front = -1;

int  Rear = -1;


void enqueue(char customer[])
{
    if ((Rear + 1) % MAX == Front)
        {
        printf("Capacity is full!\n");
        return;
    }

    if (Front == -1)
        {
        Front = 0;
    }

    Rear = (Rear + 1) % MAX;

    for (int i = 0; customer[i] != '\0'; i++)
        {
        queue[Rear][i] = customer[i];

        queue[Rear][i + 1] = '\0';
    }

    printf("%s is added in the list!\n", customer);
}


void dequeue()
{
    if (Front == -1)

        {
        printf("No customer in the line!\n");
        return;

    }
    printf("Give Biryani to %s\n", queue[Front]);

    if (Front == Rear)

        {
        Front = -1;
        Rear = -1;
    }
    else {

        Front = (Front + 1) % MAX;
    }
}


void Total_Customer()
{
    if (Front == -1)
        {
        printf("No customer in the line!\n");
        return;
    }

    int Count;

    if (Rear >= Front)

        {
        Count = Rear - Front + 1;
    }
    else {


        Count = MAX - Front + Rear + 1;
    }
    printf("Total %d  customers in line.\n", Count);
}

int main() {
    int choice;
    char customer[10];

    while (1) {
        printf("\n");
        printf("1. Add New Customer\n");
        printf("2. Give Biryani to Customer\n");
        printf("3. Total Customers in Line\n");
        printf("4. Close Shop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printf("Enter Customer Name: ");
                getchar();
                fgets(customer, sizeof(customer), stdin);


                for (int i = 0; customer[i] != '\0'; i++)

                    {
                    if (customer[i] == '\n')
                    {
                        customer[i] = '\0';
                        break;
                    }
                }

                enqueue(customer);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                Total_Customer();
                break;

            case 4:
                printf("Closing the shop.\n");
                return 0;

            default:
                printf("Invalid choice..\n");
        }
    }
}
