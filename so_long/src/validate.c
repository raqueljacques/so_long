#include "../includes/so_long.h"

int validate_file(char *file)
{
    char *extension = ft_strrchr(file, '.');
    if (!extension || ft_strcmp(extension, ".ber") != 0)
    {
        return (0);
    }
    return (1);
}

