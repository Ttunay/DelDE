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
  if(strcasecmp(User.usr, "Gnome") == 0)
  {
    printf("Выполнение дейсвия...\n");
    deleteGnome();
  } 
  else if (strcasecmp(User.usr, "kde") == 0)
  {
    printf("Выполнение действия...\n");
    deleteKDE();
  } 
  else if (strcasecmp(User.usr, "xfce") == 0)
  {
    printf("Выполнение действия...\n");
    deleteXFCE();
  }   
  else {
    printf("hello world\n");
  }
}

void deleteGnome() {
  if (geteuid() != 0) {
    printf("please, start program for use (sudo)\n");
  }

  system("sudo apt purge gnome*");

  system("sudo apt autoremove");

  system("sudo rm -rf ~/.gnome");
  system("sudo rm -rf ~/.gnome2");
  system("sudo rm -rf ~/.config/gnome*");
  system("sudo rm -rf ~/.cache/gnome*");
  system("sudo rm -rf ~/.local/share/gnome*");

  printf("GNOME deleted. reboot system\n");
}

void deleteKDE()
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

  if (strcasecmp(User.usr, "y") == 0)
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
  if(strcasecmp(User.usr, "Ubuntu") == 0)
  {
    printf("Выполнение дейсвия...\n");
    UbuntuAccept();
  } else if(strcasecmp(User.usr, "Debian") == 0)
  {
    printf("Выполнение дейсвия...\n");
    UbuntuAccept();
  } else if(strcasecmp(User.usr, "Arch") == 0)
  {
    printf("Выполнение дейсвия...\n");
    DeleteArch();
  } else {
    printf("not found your system...");
  }

}
