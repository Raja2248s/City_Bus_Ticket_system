
#include <stdio.h>
#include<stdlib.h>

struct node
{

  int number;
  int data;
  struct node *link;
};

struct stack
{

  int val;
  struct stack *next;
};


struct stack *head1;



struct node *
createnode ()
{
  struct node *newnode;
  newnode = (struct node *) malloc (sizeof (struct node));

  if (newnode == NULL)
    {
      printf ("Space is not available\n");
    }
  else
    {

      return newnode;
    }
}


void
push (int val)
{

  struct stack *ptr = (struct stack *) malloc (sizeof (struct stack));
  if (ptr == NULL)
    {
      printf ("not able to push the element");
    }
  else
    {

      if (head1 == NULL)
	{
	  ptr->val = val;
	  ptr->next = NULL;
	  head1 = ptr;
	}
      else
	{
	  ptr->val = val;
	  ptr->next = head1;
	  head1 = ptr;

	}

    }
}

void
search (struct node *ptr, int item)
{

  if (ptr == NULL)
    {
      printf ("\nNo passenger is boarding on bus  \n");
    }
  else
    {
      struct node *temp;
      temp = ptr;
      int index = 0;
      while (temp != NULL)
	{
	  if (item == temp->data)
	    {
	      index++;
	      printf ("\nDear");
	      printf ("\n Passenger you have reached your Destination %d",
		      temp->number);
	    }

	  temp = temp->link;
	}
      printf ("\nTotal passenger for this STOP = %d", index);

    }
}






int
pop ()
{
  int item;
  struct stack *ptr;
  if (head1 == NULL)
    {
      printf ("\nJourney ends");
    }
  else
    {
      item = head1->val;
      ptr = head1;
      head1 = head1->next;
      free (ptr);
      return item;
      printf ("Item popped");

    }
}



void
insert (struct node **ptr, int number, int key)
{
  struct node *newnode = createnode ();
  newnode->number = number;
  newnode->data = key;
  newnode->link = NULL;
  struct node *temp;

  if (*ptr == NULL)
    {
      *ptr = newnode;
    }
  else
    {

      temp = *ptr;

      while (temp->link != NULL)
	{
	  temp = temp->link;
	}
      temp->link = newnode;
    }
}




int
main ()
{

  struct node *head = NULL;
  int k = 0, total_journey = 0;

  int n, m, stat, item, ch, alert, number, key, i, j, flag;
  char a[][1000] =
    { "BRAHMIFATA", "KALMESHWAR", "RAMDEO", "SADAR", "LIC", "RBI" };


  n = (sizeof (a) / sizeof (char)) / 1000;
  struct stack *head1 = NULL;


  do
    {
      m = n;
      printf ("Enter 1 for new journey or 0 : ");
      scanf ("%d", &j);

      if (j == 1)
	{
	  total_journey++;
	  if (total_journey % 2 != 0)
	    {
	      for (i = 1; i <= n; i++)
		{
		  push (m);
		  m--;
		  flag == 0;
		}
	    }
	  else if (total_journey % 2 == 0)
	    {
	      for (i = 1; i <= n; i++)
		{
		  push (i);
		  m--;
		  flag == 1;
		}

	    }
	  int k = 0, z = n;
	  while (k != n)
	    {
	      printf ("\nEnter 1 for new STOP you reach : ");
	      scanf ("%d", &stat);
	      item = pop ();
	      printf ("\n ************STOP : %s ************", a[item - 1]);
	      search (head, item);


	      do
		{
		  printf ("\nEnter 1 for new passenger or 0 :  ");
		  scanf ("%d", &ch);


		  switch (ch)
		    {


		    case 1:

		      printf ("\nDo he want alert of destination  ");
		      printf ("\npress 1 for yes and 0 for no : ");
		      scanf ("%d", &alert);


		      if (alert == 1)
			{
			  printf ("\nEnter Number : ");
			  scanf ("%d", &number);

			  printf ("\nEnter destination");
			  printf ("\n 1: Brahmifata");
			  printf ("\n 2 : Kalmeshwar");
			  printf ("\n 3 : Ramdeo");
			  printf ("\n 4 : Sadar");
			  printf ("\n 5 : LIC");
			  printf ("\n 6 : RBI \n");
			  scanf ("%d", &key);

			  insert (&head, number, key);

			}


		    }
		}

	      while (ch != 0);

	      k++;
	    }
	}
    }
  while (j != 0);
  return 0;
}



