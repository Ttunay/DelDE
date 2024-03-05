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
        struct hypr User;

  if (geteuid() != 0) {
    printf("please, start program for use (sudo)\n");
  }
  system("sudo pacman -Rns xcfe4 xcfe4-goodies lxdm ");
    system("sudo systemctl disable lxdm");


  printf("Reboot system now? (Y/n): ");
  scanf("%s", User.usr);

  if (strcmp(User.usr, "Y") == 0 || strcmp(User.usr, "y") == 0)
  {

   system("reboot");
  }
  else
  {
    printf("Операция отменена.\n");
  }
  // system(" pacman -Qs xcfe4");
}