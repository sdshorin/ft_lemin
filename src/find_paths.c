



get_max_way(now_path_quantity):
	static int max_way
	static pas_quantity
	if (now_path_quantity > pas_quantity):
		max_way = count_max_wat()
	return max_way





func can_we_use_this_node(t_node):
	if t_node == start:
		return false




finish_recipt = []


func find_new_way():
	t_stacK stack;
	make_start_recipe(start)
	for connection_node in start:
		if not connection_node.is_used_in_any_path():
			make_recipe(start, connection_node)
			stack.push_back(connection_node)
			
	while(stack.size()):
		t_node = stack.pop_front()
		if not can_we_use_this_node(t_node):
			continue
		if t_node is finish:
			finish_recipt.pueh_back(t_node)
			continue
		if t_node.recipe.is_firt_on_old_path:
			t_node_next = t_node.prev_old_path
			stack.add(t_node_next)
			make_recipt_back_on_old_path(t_node, connection)
			continue
		if t_node.recipe.is_on_old_way:
			t_node_next = t_node.prev_old_path
			make_recipt_back_on_old_path(t_node, connection) # Возможно, здесь надо использоваьт отдельную функцию
																# connection.recipe.path_cost = t_node.recipe.path_cost - 1
			stack.add(t_node_next)

		for connection in t_node:
			if connection.recipe.path_cost < node.recipe.path_cost + 1:
				continue
			if (make_recipe(t_node, connection) > get_max_way(.....): # this func return path_cost for new recipe
				stack.add(connection)
	
	if !finish_recipt.size():
		return null # stop wuile in func start() 
	win_recipt = find_finisf_recipt_with_min_cost()
	retun win_recipt

		




func start():
	if !find_min_way() # ищем самый первый наикратчайший путь
		return ...
	
	while (new_good_recipt = find_new_way()):
		change_graph(new_good_recipt) # переделали все маршруты
		get_wax_way() # изменили верхнюю границу длинны пути. можно просто заново пройтись по графу, или использовать рецепт
		clear_fraph() #занулили все рецепты в графе
		if finish.connection.size() == grafh.pas_quantity:
			break




