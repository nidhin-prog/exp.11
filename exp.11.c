/* Name: Nidhi Nandepalli
 UIN: 251P092
 CLASS: comps/D */


#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int n, i;

    // Use /tmp/ which online compilers allow
    fp = fopen("/tmp/emp.txt", "w");
    if (fp == NULL) {
        printf("Cannot open file for writing.\n");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        printf("\nEnter details of employee %d\n", i+1);
        printf("ID: ");
        scanf("%d", &e.id);
        printf("Name: ");
        scanf("%s", e.name);
        printf("Salary: ");
        scanf("%f", &e.salary);

        fprintf(fp, "%d %s %.2f\n", e.id, e.name, e.salary);
    }

    fclose(fp);

    // reading
    fp = fopen("/tmp/emp.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file for reading.\n");
        return 1;
    }

    printf("\nEmployee Details from File:\n");
    while (fscanf(fp, "%d %s %f", &e.id, e.name, &e.salary) == 3) {
        printf("ID: %d\tName: %s\tSalary: %.2f\n", e.id, e.name, e.salary);
    }

    fclose(fp);
    return 0;
}
