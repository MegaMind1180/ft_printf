#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    void *str;
    printf("%d",	ft_printf("hhhh\n%c\nerste %c zweite %s dritte %s vierte %i %d %u %% %y %p", 'c', 'a', "steffi ist ein", "bastard", 0, -42, 4294967295, str));
    printf("\n\n");    
    printf("%d",	printf("hhhh\n%c\nerste %c zweite %s dritte %s vierte %i %d %lu %% %p ", 'c', 'a', "steffi ist ein", "bastard", 0, -42, 4294967295, str));
}
                                                                                                            
