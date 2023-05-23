#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  * free_list - Entry point
 *   * Description: 'free linked lists'
 *    *
 *     * @head: list_t input
 *      * Return: none
 *       */
void free_list(list_t *head)
{
	        if (head == NULL)
			                return;

		        free_list(head->next);
			        free(head->str);
				        free(head);
}
