/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/07 14:47:41 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	deal_key(int key, fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 18)
		data->rotation_x -= 0.1;
	if (key == 19)
		data->rotation_x += 0.1;
	if (key == 20)
		data->rotation_y -= 0.1;
	if (key == 21)
		data->rotation_y += 0.1;
	if (key == 22)
		data->rotation_z -= 0.1;
	if (key == 23)
		data->rotation_z += 0.1;
	if (key == 126)
		data->shift_y -= 50;
	if (key == 125)
		data->shift_y += 50;
	if (key == 123)
		data->shift_x -= 50;
	if (key == 124)
		data->shift_x += 50;
	if (key == 24)
		data->zoom += 10;
	if (key == 27)
		data->zoom -= 10;
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	get_height(char *filename)
{
	int	fd;
	int	height;

	fd = open(filename, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_width_counter(line);
	free(line);
	close(fd);
	return (width);
}

int hextodc(char *hex){
	int val;
	int i;
	int dec;
	int len;

	val = 0;
	i = 0;
	dec = 0;
	len = ft_strlen(hex) - 2;
	ft_printf("hectodec\n");
	while(hex[i])
    {
		if (hex[0] == '0' && hex[1] == 'x' && i == 0)
			i = 2;
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }
		// ft_printf("VAL: %i\n", val);
        dec += val * pow(16, len - 1);
        len--;
		i++;
    }
	// ft_printf("END");
	return dec;
}

int	is_valid_hex_format(char *str)
{
	int i;
	int	len;
	int cc;

	i = 0;
	cc = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == ',')
			cc++;
		i++;
	}
	if (cc == 1)
		return (1);
	return (0);
}

void	fill_row_matrix(int *row, int *color, char *line)
{
	char	**num;
	char	**hex;
	int		i;
	int 	flag;

	num = ft_split(line, ' ');
	i = 0;
	flag = 0;
	while(num[i])
	{
		// ft_printf("%s\n", num[i]);
		if (is_valid_hex_format(num[i]))
		{
			flag = 1;
			// ft_printf("is valid hex \n");
			hex = ft_split(num[i], ',');
			row[i] = ft_atoi(hex[0]);
			// ft_printf("Printing atoi: %i\n", ft_atoi(hex[0]));
			// ft_printf("ckpt: %s\n", color[i]);
			color[i] = hextodc(hex[1]);
			// ft_printf("[%i] - [%i]\n", row[i], color[i]);
			free(num[i]);
			free(hex[0]);
			free(hex[1]);
		}
		else
		{
			row[i] = ft_atoi(num[i]);
			color[i] = 0;
			free(num[i]);
		}
		ft_printf("[%i]-[%i]\n", row[i], color[i]);
		i++;
	}
	free(num);
	if (flag)
		free(hex);
}

void	read_file(char *filename, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(filename);
	data->width = get_width(filename);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->hex_color = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i<=data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		data->hex_color[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	ft_printf(" ------------------ \n");
	ft_printf("Width: %i\n", data->width);
	ft_printf("Heigth: %i\n", data->height);
	ft_printf(" ------------------ \n");
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_row_matrix(data->z_matrix[i], data->hex_color[i], line);
		free(line);
		i++;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	fdf	*data;

	if (argc != 2)
		return (-1);
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 2000, 2000, "FDF");
	data->zoom = 10;
	data->rotation_x = 0.0;
	data->rotation_y = 0.0;
	data->rotation_z = 0.0;

	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
