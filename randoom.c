#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMLEVELS  13
#define NUMWEAPONS 8
#define PROGNAME   "randoom"
#define VERSION    "0.1.2"

#define args(x, y, z)        \
  strcmp(argv[1], x) == 0 || \
  strcmp(argv[1], y) == 0 || \
  strcmp(argv[1], z) == 0
#define r(x) arc4random_uniform(x)

const char *levels[] = 
  { "The UAC"
  , "Resource Operations"
  , "Foundry"
  , "Argent Facility"
  , "Argent Energy Tower"
  , "Kadingir Sanctum"
  , "Argent Facility (Destroyed)"
  , "Advanced Research Complex"
  , "Lazarus Labs"
  , "Titan's Realm"
  , "The Necropolis"
  , "VEGA Central Processing"
  , "Argent D'Nur"
  };

const char *weapons[] =
  { "Pistol"
  , "Combat Shotgun"
  , "Super Shotgun"
  , "Heavy Assault Rifle"
  , "Chaingun"
  , "Plasma Rifle"
  , "Gauss Cannon"
  , "Rocket Launcher"
  };

int main(int argc, char **argv)
{
  if (argc == 1) {
    printf("Level:  %s\n", levels[r(NUMLEVELS)]);
    printf("Weapon: %s\n", weapons[r(NUMWEAPONS)]);
  } else if (argc == 2) {
    if (args("level", "-l", "--level"))
      printf("%s\n", levels[r(NUMLEVELS)]);
    else if (args("weapon", "-w", "--weapon"))
      printf("%s\n", weapons[r(NUMWEAPONS)]);
    else if (args("version", "-v", "--version"))
      printf("%s %s\n", PROGNAME, VERSION);
    else
      printf("Usage: %s <option>\n", PROGNAME);
  } else {
    printf("Usage: %s <option>\n", PROGNAME);
  }
  return 0;
}
