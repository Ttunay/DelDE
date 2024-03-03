#include "hypr.h"


struct hypr {
    char usr[10];
};

void deleteDE()
{
      struct hypr User;

    printf("какую DE удалить?\n");
    char de[3][10] = {"Gnome", "KDE", "XFCE"};
    for(int i = 0; i < 3; i++)
  {
    printf("%s\n", de[i]);
  }
  scanf("%s",User.usr);
  if(strcmp(User.usr, "Gnome") == 0 || strcmp(User.usr,"gnome") == 0)
  {
    printf("Выполнение дейсвия...\n");
    deleteGnome();
  } else {
    printf("hello world");
  }
}

void deleteGnome() {
    if (geteuid() != 0) {
        printf("please, start program for use (sudo)\n");
        return 1;
    }

    // Выполняем команду для удаления пакетов GNOME
    system("apt purge gnome*");

    // Очищаем оставшиеся зависимости
    system("apt autoremove");

    // Удаляем остаточные конфигурационные файлы
    system("rm -rf ~/.gnome");
    system("rm -rf ~/.gnome2");
    system("rm -rf ~/.config/gnome*");
    system("rm -rf ~/.cache/gnome*");
    system("rm -rf ~/.local/share/gnome*");

    printf("GNOME deleted.\n");

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
