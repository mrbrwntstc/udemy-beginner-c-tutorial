#include <stdio.h>
#include <stdlib.h>

struct item {
  char *item_name;
  int quantity;
  float price;
  float amount;
};

void read_item(struct item *item);
void print_item(struct item *item);

int main() {

  struct item item = {.item_name = NULL};
  read_item(&item);
  print_item(&item);

  return 0;
}

void read_item(struct item *item) {
  int item_name_length;
  printf("How many characters long is the item name? ");
  scanf("%d", &item_name_length);
  item->item_name = (char*) calloc(item_name_length, sizeof(char));
  printf("Item name? ");
  scanf("%s", item->item_name);

  printf("Item quantity? ");
  scanf("%d", &(item->quantity));

  printf("Item price? ");
  scanf("%f", &(item->price));

  item->amount = (float) item->price * item->quantity;
}

void print_item(struct item *item) {
  printf("\n\n");
  printf("Item name: %s\n", item->item_name);
  free(item->item_name);

  printf("Item quentity: %d\n", item->quantity);

  printf("Item price: %.2f\n", item->price);

  printf("Item amount: %.2f\n", item->amount);
}