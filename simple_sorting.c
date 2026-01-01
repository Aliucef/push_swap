#include "sorting_header.h"
#include <stdlib.h>

static int	*stack_to_array(t_list *stack, int *size)
{
	*size = ft_lstsize(stack);
	int *arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return NULL;
	
	int i = 0;
	while (stack)
	{
		arr[i++] = stack->content;
		stack = stack->next;
	}
	return arr;
}

static int	*find_lis(int *arr, int n, int *lis_len)
{
	if (n == 0)
	{
		*lis_len = 0;
		return NULL;
	}
	
	int *dp = malloc(sizeof(int) * n);
	int *parent = malloc(sizeof(int) * n);
	
	if (!dp || !parent)
	{
		free(dp);
		free(parent);
		return NULL;
	}
	
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		parent[i] = -1;
	}
	
	int max_len = 1;
	int max_idx = 0;
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
		}
		if (dp[i] > max_len)
		{
			max_len = dp[i];
			max_idx = i;
		}
	}
	
	int *lis = malloc(sizeof(int) * max_len);
	if (!lis)
	{
		free(dp);
		free(parent);
		return NULL;
	}
	
	int idx = max_idx;
	for (int i = max_len - 1; i >= 0; i--)
	{
		lis[i] = idx;
		idx = parent[idx];
	}
	
	*lis_len = max_len;
	free(dp);
	free(parent);
	return lis;
}

static int	*create_lis_set(int *lis, int lis_len, int max_index)
{
	int *set = calloc(max_index, sizeof(int));
	if (!set)
		return NULL;
	
	for (int i = 0; i < lis_len; i++)
		set[lis[i]] = 1;
	
	return set;
}

static int	find_insert_position(t_list *a, int value)
{
	if (!a)
		return 0;
	
	int size = ft_lstsize(a);
	
	t_list *tmp = a;
	int min_val = tmp->content;
	int max_val = tmp->content;
	int min_pos = 0;
	
	int i = 0;
	while (tmp)
	{
		if (tmp->content < min_val)
		{
			min_val = tmp->content;
			min_pos = i;
		}
		if (tmp->content > max_val)
			max_val = tmp->content;
		tmp = tmp->next;
		i++;
	}
	
	if (value < min_val || value > max_val)
		return min_pos;
	
	tmp = a;
	i = 0;
	int best_pos = min_pos;
	int best_val = min_val - 1;
	
	while (tmp)
	{
		if (tmp->content < value && tmp->content > best_val)
		{
			best_val = tmp->content;
			best_pos = (i + 1) % size;
		}
		tmp = tmp->next;
		i++;
	}
	
	return best_pos;
}

static int	get_rotation_cost(int pos, int size)
{
	int forward = pos;
	int backward = size - pos;
	return (forward < backward) ? forward : backward;
}

static void	rotate_to_pos(t_list **stack, int pos, char which, t_ops *ops)
{
	int size = ft_lstsize(*stack);
	if (pos == 0)
		return;
	
	int forward = pos;
	int backward = size - pos;
	
	if (forward <= backward)
	{
		while (pos-- > 0)
			rotate(stack, which, ops);
	}
	else
	{
		while (pos++ < size)
			reverse_rotate(stack, which, ops);
	}
}

static int	find_cheapest_move(t_list *a, t_list *b, int *out_pos_a)
{
	int size_a = ft_lstsize(a);
	int size_b = ft_lstsize(b);
	int min_cost = 2147483647;
	int best_pos_b = 0;
	int best_pos_a = 0;
	
	t_list *tmp_b = b;
	int pos_b = 0;
	
	while (tmp_b)
	{
		int value = tmp_b->content;
		int pos_a = find_insert_position(a, value);
		
		int cost_a = get_rotation_cost(pos_a, size_a);
		int cost_b = get_rotation_cost(pos_b, size_b);
		
		int fa = pos_a, ba = size_a - pos_a;
		int fb = pos_b, bb = size_b - pos_b;
		
		int total_cost;
		if ((fa <= ba && fb <= bb) || (fa > ba && fb > bb))
			total_cost = (cost_a > cost_b) ? cost_a : cost_b;
		else
			total_cost = cost_a + cost_b;
		
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			best_pos_b = pos_b;
			best_pos_a = pos_a;
		}
		
		tmp_b = tmp_b->next;
		pos_b++;
	}
	
	*out_pos_a = best_pos_a;
	return best_pos_b;
}

static void	execute_move(t_list **a, t_list **b, int pos_a, int pos_b, t_ops *ops)
{
	int size_a = ft_lstsize(*a);
	int size_b = ft_lstsize(*b);
	
	int fa = pos_a, ba = size_a - pos_a;
	int fb = pos_b, bb = size_b - pos_b;
	
	if (fa <= ba && fb <= bb)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rotate_both(a, b, ops);
			pos_a--;
			pos_b--;
		}
	}
	else if (fa > ba && fb > bb)
	{
		while (pos_a < size_a && pos_b < size_b)
		{
			reverse_rotate_both(a, b, ops);
			pos_a++;
			pos_b++;
		}
	}
	
	rotate_to_pos(a, pos_a, 'a', ops);
	rotate_to_pos(b, pos_b, 'b', ops);
	push(b, a, 'a', ops);
}

static void	align_stack(t_list **a, t_ops *ops)
{
	if (!*a)
		return;
	
	int min = (*a)->content;
	int min_pos = 0;
	
	t_list *tmp = *a;
	int i = 0;
	
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	
	rotate_to_pos(a, min_pos, 'a', ops);
}

void	selection_sort(t_list **stack_a, t_list **stack_b, t_ops *ops)
{
	int n = ft_lstsize(*stack_a);
	if (n <= 1)
		return;
	
	int size;
	int *arr = stack_to_array(*stack_a, &size);
	if (!arr)
		return;
	
	int lis_len;
	int *lis = find_lis(arr, size, &lis_len);
	if (!lis)
	{
		free(arr);
		return;
	}
	
	int *lis_set = create_lis_set(lis, lis_len, size);
	if (!lis_set)
	{
		free(arr);
		free(lis);
		return;
	}
	
	int idx = 0;
	int total = size;
	
	while (idx < total)
	{
		if (lis_set[idx])
			rotate(stack_a, 'a', ops);
		else
			push(stack_a, stack_b, 'b', ops);
		idx++;
	}
	
	free(arr);
	free(lis);
	free(lis_set);
	
	while (*stack_b)
	{
		int pos_a;
		int pos_b = find_cheapest_move(*stack_a, *stack_b, &pos_a);
		execute_move(stack_a, stack_b, pos_a, pos_b, ops);
	}
	
	align_stack(stack_a, ops);
}
