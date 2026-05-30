#include "ft_printf.h"

int main(void)
{
    char str[] = "hallo";
    printf("%d",	ft_printf("hhhh\n%c\nerste %c zweite %s dritte %s vierte %i %d %u %% %p %x %X ", 'c', 'a', "steffi ist ein", "bastard", 0, -42, 4294967295, (void*)str, 11111111, 11111111));
    printf("\n\n");    
    printf("%d",	printf("hhhh\n%c\nerste %c zweite %s dritte %s vierte %i %d %lu %% %p %x %X ", 'c', 'a', "steffi ist ein", "bastard", 0, -42, 4294967295, (void*)str, 11111111, 11111111));
    printf("\n\n");        
    printf("%p\n", (void*)str);
    ft_printf("%p\n", (void*)str);
}
                                                                                                            
