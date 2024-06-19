#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 *
 * @head: Double pointer to the head of the list_t list.
 * @str: String to be duplicated and added to the new node.
 *
 * Return: The address of the new elment, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *new_str;
	unsigned int len = 0;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_str = strdup(str);
	if (new_str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	while (str[len])
		len++;

	new_node->str = new_str;
	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
