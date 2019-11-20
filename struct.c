#include "fillit.h"

void	free_map(t_mp *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_memdel((void **)&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}


int		crmap(void)
{
	t_mp	*mep;
	char	i;

	i = 0;
	mep = (t_mp*)malloc(sizeof(t_mp));
	if (mep == NULL)
		return (0);
	mep->map = (char**)malloc(sizeof(char*) * 4);
	while (i < 4)
	{
		mep->map[i] = ft_strnew(4);
		ft_memset(mep->map[i], '.', 4);
		printf("%s\n", *mep->map);
		i++;
	}
	free_map(mep);
	return(0);
}

int		korlist(char **buf)
{
	static t_fig	*first;
	t_fig			*figurs;
	int				i;
	char			letters;

	letters = 'A';
	i = 0;
	while (i < 4)
	{
		if (letters == 'A')
		{
			first = korzap(buf, i, letters);
			printf("[%d, ", figurs->coord[0]);
			printf("%d]\n", figurs->coord[1]);
			printf("[%d, ", figurs->coord[2]);
			printf("%d]\n", figurs->coord[3]);
			printf("[%d, ", figurs->coord[4]);
			printf("%d]\n", figurs->coord[5]);
			printf("[%d, ", figurs->coord[6]);
			printf("%d]\n", figurs->coord[7]);
			figurs = first;
		}
		else
		{
			figurs->next = korzap(buf, i, letters);
			printf("[%d, ", figurs->coord[0]);
			printf("%d]\n", figurs->coord[1]);
			printf("[%d, ", figurs->coord[2]);
			printf("%d]\n", figurs->coord[3]);
			printf("[%d, ", figurs->coord[4]);
			printf("%d]\n", figurs->coord[5]);
			printf("[%d, ", figurs->coord[6]);
			printf("%d]\n", figurs->coord[7]);
			figurs = figurs->next;
		}
		i++;
		letters++;
	}
	figurs->next = NULL;
	return (0);
}

t_fig	*korzap(char	**buf, int j, char letters)
{
	t_fig			*figurs;
	int				x;
	int				y;
	int				i;

	x = 0;
	i = 0;
	y = 1;
	figurs = (t_fig*)malloc(sizeof(t_fig));
	if (figurs == NULL)
		return (0);
	while (i < 16)
	{
		if (buf[j][i] == '#')
		{
			figurs->coord[x] = (i >= 4) ? (i%4) : i;
			figurs->coord[y] = (i/4);
			figurs->letter = letters;
			x = x + 2;
			y = y + 2;
		}
		i++;
	}
	return (figurs);
}