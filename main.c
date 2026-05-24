#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("%d",	ft_printf("hhhh\n%c\nerste %c zweite %s dritte %s vierte %i %d %u %%  ", 'c', 'a', "steffi ist ein", "bastard", 0, -42, 4294967295));
    
    printf("%d",	printf("hhhh\n%c\nerste %c zweite %s dritte %s vierte %i %d %lu %%  ", 'c', 'a', "steffi ist ein", "bastard", 0, -42, 4294967295));
}
                                                                                                            
