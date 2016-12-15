#include<stdio.h>
#include<conio.h>
struct node {
    int data;
    struct node *next;
};
void push(struct node **head,int d){
    struct node *temp,*ptr = *head;
    temp  = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = *head;
    if(*head!=NULL){
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }else{
        temp->next = temp;
    }
    *head = temp;
    return;
}

void append(struct node **head,int d){
    struct node *temp,*ptr = *head;
    temp  = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void delete(struct node**head,int key){
    struct node *it,*ptr = *head;
    if(key == ptr->data && ptr!=NULL){
        *head = ptr->next;
        ptr->next = NULL;
        free(ptr);
        return;
    }
    while(ptr->next!=NULL){
        if(ptr->data == key){
            break;
        }
        it=ptr;
        ptr=ptr->next;
    }
    it->next = ptr->next;
    free(ptr);
}
void deleteNodeAtK(struct node **head,int k){
    struct node *temp = *head,*it;
    int i = 0;
    if(k == 0){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL){
        if(i==k){
            it->next = temp->next;
            free(temp);
            break;
        }
        i++;
        it = temp;
        temp = temp->next;
    }
}
static void reverse(struct node **head){
    struct node *ptr,*temp=*head,*it=NULL;
    while(temp!=NULL){
        ptr = temp->next;
        temp->next = it;
        it = temp;
        temp = ptr;
    }
    *head = it;
}
void printList(struct node *head){
    struct node *ptr = head;
    if(head!=NULL){
        do{
            printf("%d->",ptr->data);
            ptr = ptr->next;
        }while(ptr!=head);
    }
    return;
}
int main(){
    struct node *head = NULL;
    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    printf("Contents of Circular Linked List\n ");
    printList(head);
    return 0;
}
