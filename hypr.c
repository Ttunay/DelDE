#include <stdio.h>
#include <string.h>
struct hypr {
    char usr[10];
};

void deleteDE()
{
    printf("какую DE удалить?\n");
    char de[3][10] = {"Gnome", "KDE", "XFCE"};
    for(int i = 0; i < 3; i++)
    {
        printf("%s\n", de[i]);
    }
}


int main()
{   
    struct hypr User;
    
    printf("Delete your DE? (Y/n): ");
    scanf("%s",User.usr);


if (strcmp(User.usr, "Y")  == 0|| strcmp(User.usr, "y") == 0) {

        printf("Выполнение действия...\n");
        deleteDE();
        

    } else {
        printf("Операция отменена.\n");
    }

}
