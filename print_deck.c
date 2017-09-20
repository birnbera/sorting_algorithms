#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_deck - print deck of cards
 * @deck: pointer to linked list of cards
 */
void print_deck(const deck_node_t *deck)
{
	int comma = 0;
	char suit;

	if (deck == NULL)
		return;
	while (deck)
	{
		switch (deck->card->kind)
		{
		case SPADE:
			suit = 'S';
			break;
		case HEART:
			suit = 'H';
			break;
		case CLUB:
			suit = 'C';
			break;
		case DIAMOND:
			suit = 'D';
			break;
		default:
			suit = '?';
		}
		if (comma)
			printf(", ");
		printf("{%s, %c}", deck->card->value, suit);
		deck = deck->next;
		comma++;
		if (comma % 13 == 0)
		{
			putchar('\n');
			comma = 0;
		}
	}
}
