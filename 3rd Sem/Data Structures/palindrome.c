#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
   char data;
   struct Node *next;
   struct Node *prev;
};

struct Node* insertCharacter(struct Node*, char) ;

int checkPalindrome(struct Node *) ;

int main() {
   struct Node* head = NULL;
   char str[100];
   printf("Enter a string=");
   scanf("%s",str);
   for(int i = 0; i< strlen(str); i++){
      head = insertCharacter(head, str[i]);
   }
   if (checkPalindrome(head))
      printf("%s is a palindrome",str);
   else
      printf("%s is not a palindrome",str);
    return 0;
}

struct Node* insertCharacter(struct Node* head, char data) {
  struct Node *new,*temp;

  new =(struct Node *)(malloc(sizeof(struct Node)));
	new->data = data;
	new->prev=NULL;
	new->next=NULL;
	
  if(head == NULL){
    head=new;
  }
  else { 
    temp=head;
    while(temp->next!=NULL)
			  temp=temp->next;
		 
		temp->next=new;
		new->prev= temp;
	  }
    return head;
}

int checkPalindrome(struct Node *head) {
   if (head == NULL) //assuming null string is a palindrome
      return 1;
   struct Node *tail = head;
   while (tail->next != NULL) //find tail of the dll
      tail = tail->next;
   while (head != tail && tail != head->prev) { //For odd lengthed string stop when head == tail and for even lengthed string stop when tail goes to left side of right
      if (head->data != tail->data) //condition for not a palindrome
         return 0;
      head = head->next;  //move head one node right
      tail = tail->prev;  //move tail one node left
   }
   return 1;
}