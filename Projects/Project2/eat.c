#include <stdio.h>
#include <string.h>

int main(void) {
//Jacob Nelson Project 2
//Purpose: Ask Questions until food can be determined if edible or not.

char str1[20];
char str2[20];
char str3[3];
char str3other[20];
char str4[3];
char str5[3];
char str6[3];


printf("What fell on the floor? (meat, produce, bread, or junk-food)\n");
scanf("%s", str1);

if (strcmp(str1, "meat") == 0){
    printf("What kind? (chicken, beef, or other)\n");
    scanf("%s", str2);
        if (strcmp(str2, "chicken") == 0){
            printf("Nuggets?\n");
            scanf("%s", str3);
            if (strcmp(str3, "yes") == 0){
                printf("On floor for more than three seconds?\n");
                scanf("%s", str5);
                if (strcmp(str5, "no") == 0){
                    printf("You Can Eat What Dropped\n");
                  }
                if (strcmp(str5, "yes") == 0){
                    printf("Do NOT Eat What Dropped\n");
                  }
            }
            if (strcmp(str3, "no") == 0){
                printf("Is the floor clean?\n");
                scanf("%s", str4);
                if (strcmp(str4, "yes") == 0){
                      printf("On floor for more than three seconds?\n");
                      scanf("%s", str5);
                      if (strcmp(str5, "no") == 0){
                          printf("You Can Eat What Dropped\n");
                        }
                      if (strcmp(str5, "yes") == 0){
                          printf("Do NOT Eat What Dropped\n");
                        }
                  }
                if (strcmp(str4, "no") == 0){
                    printf("Do NOT Eat What Dropped\n");
                }
            }
        }

        if (strcmp(str2, "beef") == 0){
            printf("Steak?\n");
            scanf("%s", str3);
            if (strcmp(str3, "no") == 0){
                printf("Is the floor clean?\n");
                scanf("%s", str4);
                if (strcmp(str4, "yes") == 0){
                      printf("On floor for more than three seconds?\n");
                      scanf("%s", str5);
                      if (strcmp(str5, "no") == 0){
                          printf("You Can Eat What Dropped\n");
                        }
                      if (strcmp(str5, "yes") == 0){
                          printf("Do NOT Eat What Dropped\n");
                        }
                  }
                if (strcmp(str4, "no") == 0){
                    printf("Do NOT Eat What Dropped\n");
                }
            }
            if (strcmp(str3, "yes") == 0){
                printf("You Can Eat What Dropped\n");
              }
        }

        if (strcmp(str2, "other") == 0){
            printf("Leftovers or fresh?\n");
            scanf("%s", str3other);
            if (strcmp(str3other, "fresh") == 0){
                printf("Can you brush it off?\n");
                scanf("%s", str3);
                if (strcmp(str3, "yes") == 0){
                    printf("You Can Eat What Dropped\n");
                  }
                if (strcmp(str3, "no") == 0){
                    printf("Do NOT Eat What Dropped\n");
                  }
            }
            if (strcmp(str3other, "leftovers") == 0){
                printf("On floor for more than three seconds?\n");
                scanf("%s", str5);
                if (strcmp(str5, "no") == 0){
                    printf("You Can Eat What Dropped\n");
                  }
                if (strcmp(str5, "yes") == 0){
                    printf("Do NOT Eat What Dropped\n");
                  }
            }
        }
}
if (strcmp(str1, "produce") == 0){
    printf("Does it grow in the ground?\n");
    scanf("%s", str2);
        if (strcmp(str2, "yes") == 0){
            printf("On floor for more than three seconds?\n");
            scanf("%s", str5);
            if (strcmp(str5, "no") == 0){
                printf("You Can Eat What Dropped\n");
              }
            if (strcmp(str5, "yes") == 0){
                printf("Do NOT Eat What Dropped\n");
              }
        }
        if (strcmp(str2, "no") == 0){
            printf("Smashed or bruised?\n");
            scanf("%s", str3);
                if (strcmp(str3, "yes") == 0){
                    printf("Do NOT Eat What Dropped\n");
                }
                if (strcmp(str3, "no") == 0){
                    printf("Is the floor clean?\n");
                    scanf("%s", str4);
                    if (strcmp(str4, "yes") == 0){
                        printf("You Can Eat What Dropped\n");
                    }
                    if (strcmp(str4, "no") == 0){
                        printf("On floor for more than three seconds?\n");
                        scanf("%s", str5);
                        if (strcmp(str5, "no") == 0){
                            printf("You Can Eat What Dropped\n");
                          }
                        if (strcmp(str5, "yes") == 0){
                            printf("Do NOT Eat What Dropped\n");
                          }
                    }
                }
        }
}

if (strcmp(str1, "bread") == 0){
    printf("Buttered?\n");
    scanf("%s", str2);
    if (strcmp(str2, "yes") == 0){
        printf("Butter side up?\n");
        scanf("%s", str3);
            if (strcmp(str3, "no") == 0)
                printf("Do NOT Eat What Dropped\n");
            }
            if (strcmp(str3, "yes") == 0){
                printf("Is the floor clean?\n");
                scanf("%s", str4);
                    if (strcmp(str4, "yes") == 0){
                        printf("You Can Eat What Dropped\n");
                    }
                    if (strcmp(str4, "no") == 0){
                        printf("Do NOT Eat What Dropped\n");
                    }
            }
    if (strcmp(str2, "no") == 0){
        printf("Is the floor clean?\n");
        scanf("%s", str3);
            if (strcmp(str3, "yes") == 0){
                printf("You Can Eat What Dropped\n");
            }
            if (strcmp(str3, "no") == 0){
                printf("Do NOT Eat What Dropped\n");
            }
    }
}

if (strcmp(str1, "junk-food") == 0){
printf("What kind? (candy, donuts, or chips)\n");
scanf("%s", str2);
    if (strcmp(str2, "candy") == 0){
          printf("Is the floor clean?\n");
          scanf("%s", str3);
              if (strcmp(str3, "yes") == 0){
                  printf("You Can Eat What Dropped\n");
              }
              if (strcmp(str3, "no") == 0){
                  printf("Do NOT Eat What Dropped\n");
              }
    }

    if (strcmp(str2, "donuts") == 0){
        printf("Sprinkles?\n");
        scanf("%s", str3);
            if (strcmp(str3, "yes") == 0){
              printf("Is the floor clean?\n");
              scanf("%s", str4);
              if (strcmp(str4, "yes") == 0){
                  printf("You Can Eat What Dropped\n");
                }
              if (strcmp(str4, "no") == 0){
                  printf("Can you brush it off?\n");
                  scanf("%s", str5);
                  if (strcmp(str5, "yes") == 0){
                      printf("On floor for more than three seconds?\n");
                      scanf("%s", str6);
                      if (strcmp(str6, "no") == 0){
                          printf("You Can Eat What Dropped\n");
                        }
                      if (strcmp(str6, "yes") == 0){
                          printf("Do NOT Eat What Dropped\n");
                        }
                    }
                  }
                  if (strcmp(str5, "no") == 0){
                      printf("Do NOT Eat What Dropped\n");
                  }
              }
            if (strcmp(str3, "no") == 0){
              printf("On floor for more than three seconds?\n");
              scanf("%s", str4);
              if (strcmp(str4, "no") == 0){
                  printf("You Can Eat What Dropped\n");
                }
              if (strcmp(str4, "yes") == 0){
                  printf("Do NOT Eat What Dropped\n");
                }
            }


    }

    if (strcmp(str2, "chips") == 0){
        printf("Can you brush it off?\n");
        scanf("%s", str3);
        if (strcmp(str3, "yes") == 0){
            printf("On floor for more than three seconds?\n");
            scanf("%s", str4);
            if (strcmp(str4, "no") == 0){
                printf("You Can Eat What Dropped\n");
              }
            if (strcmp(str4, "yes") == 0){
                printf("Do NOT Eat What Dropped\n");
              }
          }
        if (strcmp(str3, "no") == 0){
            printf("Do NOT Eat What Dropped\n");
        }
    }
}
return 0;
}
