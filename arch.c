#include "ubuntu.h"


struct hypr {
  char usr[10];
};
void DeleteArch()
{

  struct hypr User;

  printf("какую DE удалить?\n");
  char de[4][10] = {"Gnome", "KDE", "XFCE","Hyprland"};
  for(int i = 0; i < 3; i++)
  {
    printf("%s\n", de[i]);
  }
  scanf("%s",User.usr);
  if (strcasecmp(User.usr, "Gnome") == 0)
  {
    printf("Выполнение действия...\n");
    deleteGnomeArch();
  } 
  else if (strcasecmp(User.usr, "KDE") == 0)
  {
    printf("Выполнение действия...\n");
    deleteKDEArch();
  } 
  else if (strcasecmp(User.usr, "XFCE") == 0)
  {
    printf("Выполнение действия...\n");
    deleteXFCEArch();
  } 
  else if (strcasecmp(User.usr, "Hyperland") == 0)
  {
    printf("Выполнение действия...\n");
    deleteXFCEArch();
  } 
  else
{
    printf("DE не найдено\n");
  }
} 


void deleteGnomeArch() {
  if (geteuid() != 0) {
    printf("please, start program for use (sudo)\n");
  }

  system("sudo pacman -Rns gnome*");

  system("sudo pacman -Rns $(pacman -Qdtq)");

  system("sudo rm -rf ~/.gnome");
  system("sudo rm -rf ~/.gnome2");
  system("sudo rm -rf ~/.config/gnome*");
  system("sudo rm -rf ~/.cache/gnome*");
  system("sudo rm -rf ~/.local/share/gnome*");

  printf("GNOME deleted. reboot system\n");
}

void deleteKDEArch()
{ 
  if (geteuid() != 0) {
    printf("please, start program for use (sudo)\n");
  }

  system("sudo pacman -Rns kde-applications kde-meta --noconfirm");
  system("sudo pacman -Rns $(pacman -Qdtq)");


  system("sudo rm -rf /usr/share/kde5/");
  system("sudo rm -rf /usr/share/kde5/");
  system("sudo rm -rf /usr/share/config/k*rc");
  system("sudo rm -rf /usr/share/applications/k*desktop");
  system("sudo rm -rf /etc/sddm.conf.d/kde.conf");  
  system("sudo rm -rf ~/.kde/");
  system("sudo rm -rf ~/.local/share/kactivitymanagerd/");
}
void deleteXFCEArch()
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