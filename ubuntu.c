#include "ubuntu.h"


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
    printf("hello world\n");
  }
}

void deleteGnome() {
  if (geteuid() != 0) {
    printf("please, start program for use (sudo)\n");
  }

  // Выполняем команду для удаления пакетов GNOME
  system("sudo apt purge gnome*");

  // Очищаем оставшиеся зависимости
  system("sudo apt autoremove");

  // Удаляем остаточные конфигурационные файлы
  system("sudo rm -rf ~/.gnome");
  system("sudo rm -rf ~/.gnome2");
  system("sudo rm -rf ~/.config/gnome*");
  system("sudo rm -rf ~/.cache/gnome*");
  system("sudo rm -rf ~/.local/share/gnome*");

  printf("GNOME deleted. reboot system\n");
}

void deleteKde()
{ 
  if (geteuid() != 0) {
    printf("please, start program for use (sudo)\n");
  }

  system("sudo apt-get purge kde-standard —autoremove");
  system("sudo apt autoremove");
  system("sudo apt autoclean");
  system("sudo dpkg -l | grep '^rc' | awk '{print $2}' | sudo xargs dpkg -P");

  system("sudo rm -rf /usr/share/kde5/");
  system("sudo rm -rf /usr/share/kde5/");
  system("sudo rm -rf /usr/share/config/k*rc");
  system("sudo rm -rf /usr/share/applications/k*desktop");
  system("sudo rm -rf /etc/sddm.conf.d/kde.conf");  
  system("sudo rm -rf ~/.kde/");
  system("sudo rm -rf ~/.local/share/kactivitymanagerd/");
}
void deleteXFCE()
{
  if (geteuid() != 0) {
    printf("please, start program for use (sudo)\n");
  }
  system("sudo dpkg -l | grep .xfce.");
  printf("эти пакеты будут удалены");

  system("sudo apt remove xfce4");
  system("sudo apt autoremove");
  system("sudo apt autoclean");
  system("sudo apt purge xfce4");
}
void UbuntuAccept()
{
    struct hypr User;

    printf("Hello this appication work on ubuntu or debian");
  printf("Delete your DE? (Y/n): ");
  scanf("%s", User.usr);

  if (strcmp(User.usr, "Y") == 0 || strcmp(User.usr, "y") == 0)
  {

    printf("Выполнение действия...\n");
    deleteDE();
  }
  else
  {
    printf("Операция отменена.\n");
  }
}
int main()
{   
  struct hypr User;

  printf("pick your Linux\n");

  
    char linuxes[3][10] = {"Ubuntu", "Debian", "Arch"};
    for(int i = 0; i < 3; i++)
  {
    printf("%s\n", linuxes[i]);
  }

      scanf("%s",User.usr);
  if(strcmp(User.usr, "Ubuntu") == 0 || strcmp(User.usr,"ubuntu") == 0)
  {
    printf("Выполнение дейсвия...\n");
    UbuntuAccept();
  } else if(strcmp(User.usr, "Debian") == 0 || strcmp(User.usr,"debian") == 0)
  {
    printf("Выполнение дейсвия...\n");
    UbuntuAccept();
  } else if(strcmp(User.usr, "Arch") == 0 || strcmp(User.usr,"arch") == 0)
  {
    printf("Выполнение дейсвия...\n");
    DeleteArch();
  } else {
    printf("not found your system...");
  }
  
}