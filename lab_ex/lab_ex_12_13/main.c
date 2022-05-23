#include "lab_ex_12.h"

void ex_1()
{
    int n;
    float average;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    Articals *articals = (Articals *)malloc(sizeof(Articals)*n);
    if(articals == NULL)
    {
        perror(NULL);
        exit(1);
    }

    information(articals, n);

    average = average_price(articals, n);
    printf("Average price = %.2f\n\n", average);

    sorted_array(articals, n);
    displaying_array(articals, n);

    free(articals);
}

void ex_2()
{
    int n;
    printf("Number of students: ");
    scanf("%d", &n);

    Students *students = (Students *)malloc(sizeof(Students)*n);

    students_info(students, n);
    printf("Sudents with grade < 4.50:\n");
    func_mark4(students, n);
    printf("Sudents with grade >= 5.50 and age < 25:\n");
    func_mark6_25(students, n);
    printf("Bigger grade:\n");
    bigger_grade(students, n);

}

void ex_3()
{
    char *name, *number;
    name = (char *)malloc(sizeof(char)*20);
    number = (char *)malloc(sizeof(char)*20);
    int code;

    FILE *fp_t = fopen("telephon.txt", "w");
    if(fp_t == NULL)
    {
        perror(NULL);
        exit(1);
    }

    int cnt = 1;
    char c[2];

    while(1)
    {
        telephon_info(name, &code, number);
        fprintf(fp_t, "%s %d %s\n", name, code, number);
        printf("Do you want to add(Y/N): ");
        scanf("%s", c);
        if(!strcmp(c, "Y"))
        {
            cnt++;
        }
        else
        {
            fclose(fp_t);
            break;
        }
    }

    Telephon *telephon = (Telephon *)malloc(sizeof(Telephon)*cnt);
    if(telephon == NULL)
    {
        perror("Allocation memory error");
        exit(1);
    }

    fp_t = fopen("telephon.txt", "r");
    if(fp_t == NULL)
    {
        perror("Error open");
        exit(1);
    }
    for(int j = 0; j < cnt; j++)
    {
        telephon[j].name = (char *)malloc(sizeof(char)*20);
        telephon[j].number = (char *)malloc(sizeof(char)*20);
        fscanf(fp_t, "%s %d %s", telephon[j].name, &telephon[j].code, telephon[j].number);
    }

    fclose(fp_t);

    for(int j = 0; j < cnt; j++)
    {
        telephon_display(telephon[j]);
    }

    for(int j = 0; j < cnt; j++)
    {
        free(telephon[j].name);
        free(telephon[j].number);
    }
    free(telephon);
}

void ex_4()
{
    printf("Every employee is working 8 hours a day, 5 times a week, additional hours are paid 150 procent and there is 3.65 procent tax of his weekly payment!\n\n");
    int emp;
    printf("How many employees would you like to add: ");
    scanf("%d", &emp);
    Employee *employee;
    employee = (Employee *)malloc(sizeof(Employee)*emp);
    if(employee == NULL)
    {
        perror(NULL);
        exit(1);
    }

    if(emp >= 30)
    {
        employee = (Employee *)realloc(employee, sizeof(Employee)*30);
        if(employee == NULL)
        {
            perror(NULL);
            exit(1);
        }

        emp = 30;
        printf("We can work only with 30 employees...\n");
    }

    employee_info(employee, &emp);
    weekly_paymnet(employee, &emp);

    FILE *fp_b = fopen("employee_b", "wb");
    if(fp_b == NULL)
    {
        perror("Error open_b");
        exit(1);
    }

    if(fwrite(employee, sizeof(employee[0]), emp, fp_b) != emp)
    {
        perror("Error writing_b");
        fclose(fp_b);
        exit(1);
    }

    fflush(stdin);
    char c;
    int m_emp;
    printf("Do you want to add a new employee/s(Y/N): ");
    scanf("%c", &c);
    if(c == 'Y' || c == 'y')
    {
        printf("How many would you like to add: ");
        scanf("%d", &m_emp);
        while(m_emp != 0 && emp <=30)
        {
            employee = add_employee(employee, &emp, fp_b);
            m_emp--;
        }
    }
    for(int i = 0; i < emp; i++)
    {
        printf("Weekly payment of employee #%d = %.2f\n", i + 1, (employee + i)->weekly_payment);
    }
    fclose(fp_b);
    free(employee);
}

int main()
{
    //ex_4();
    //ex_3();
    //ex_2();
    //ex_1();
    return 0;
}
